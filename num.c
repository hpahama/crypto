#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    uint8_t x, y;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    return x + y;
}

