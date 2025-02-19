#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main() {
        int buf[6];
        printf("Insert 2 heights as XftY.Zin, each on their own line\n");
        scanf("%dft%d.%din", &buf[0], &buf[1], &buf[2]);
        scanf("%dft%d.%din", &buf[3], &buf[4], &buf[5]);

        printf("%dft%d.%din\n", buf[0], buf[1], buf[2]);

        return 0;
}
