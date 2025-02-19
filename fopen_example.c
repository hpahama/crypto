#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the file for reading
    FILE *file = fopen("testfile.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read and print the file content
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
