#include <stdint.h> / * !!! NEW */

#define CHOICE(e,f,g) ((e)?(f):(g))
#define MEDIAN(e,f,g) ((!!(e) + !!(f) + !!(g)) > 1)
#define ROTATE(a,n) ((a) >> (n))

int main() {
    uint32_t e = 0xAA, f = 0x55, g = 0x66; /* !!! NEW */
    CHOICE(e,g,g);
    MEDIAN(e,f,g);
    ROTATE(e,f);
    return 0;
}

