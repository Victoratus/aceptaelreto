#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int costes[1000000001];

int main() {
    int num, x, y, i, pos, acumulado, maxAcumulado, max, min;

    while (true) {
        scanf("%d", &num);
        if (num == 0) return 0;

        max = 0;
        min = __INT_MAX__;

        memset(costes, 0, 1000000001*2);
        memset(&costes[500000000], 0, 1000000001*2);

        for (i = 0; i < num; i++) {
            scanf("%d %d", &x, &y);
            if (x-y < 0) {
                costes[0]++;
                if (min > 0) min = 0;
            } else {
                costes[x-y]++;
                if (min > x-y) min = x-y;
            }
            if (x+y+1 < 1000000000) costes[x+y+1]--;
            if (max < x+y+1) max = x+y+1;
        }

        if (max > 1000000000) max = 1000000000;

        acumulado = 0;
        maxAcumulado = 0;

        for (i = min; i < max; i++) {
            acumulado += costes[i];
            if (acumulado > maxAcumulado) maxAcumulado = acumulado;
        }

        printf("%d\n", maxAcumulado);
    }
}