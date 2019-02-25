#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main() {
    int num_uvas;
    while (true) {
        scanf("%d", &num_uvas);
        if (num_uvas == 0) break;
        printf("%d\n", (int) ceil((sqrt(1+8*num_uvas)-1)/2));
    }
    return 0;
}
