#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main() {
    int i, num_casos, num_palomas, num_cajas;
    scanf("%d", &num_casos);
    for (i = 0; i < num_casos; i++) {
        scanf("%d %d", &num_palomas, &num_cajas);
        if (num_palomas > num_cajas) printf("PRINCIPIO\n");
        else printf("ROMANCE\n");
    }
    return 0;
}
