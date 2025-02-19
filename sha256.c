#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

void compute_sha256(FILE *file, unsigned char *outputBuffer) {
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    if(mdctx == NULL) {
        perror("Failed to create EVP_MD_CTX");
        return;
    }

    if(1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
        perror("EVP_DigestInit_ex failed");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    const int bufferSize = 32768;
    unsigned char *buffer = malloc(bufferSize);
    int bytesRead = 0;

    if(!buffer) {
        perror("Failed to allocate buffer");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    while((bytesRead = fread(buffer, 1, bufferSize, file)) > 0) {
        if(1 != EVP_DigestUpdate(mdctx, buffer, bytesRead)) {
            perror("EVP_DigestUpdate failed");
            free(buffer);
            EVP_MD_CTX_free(mdctx);
            return;
        }
    }

    unsigned int outputLength;
    if(1 != EVP_DigestFinal_ex(mdctx, outputBuffer, &outputLength)) {
        perror("EVP_DigestFinal_ex failed");
    }

    free(buffer);
    EVP_MD_CTX_free(mdctx);
}

void print_sha256(unsigned char *hash) {
    for(int i = 0; i < EVP_MD_size(EVP_sha256()); i++) {
        fprintf(stdout, "%02x", hash[i]);
    }
    fprintf(stdout, "\n");
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if(!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    compute_sha256(file, hash);
    print_sha256(hash);

    fclose(file);
    return 0;
}

