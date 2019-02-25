#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main () {
    long long num_familias;
    long long midi;
    long long i, j;
    long long num_hijos;
    long long fuerza;
    long long mejores[20];
    long long f_mejor;

    while (true) {
        scanf("%lld", &num_familias);
        if (num_familias == 0) break;
        for (i = 0; i < num_familias; i++) {
            scanf("&lld, &lld", &num_hijos, &midi);
            f_mejor = 0;
            for (j = 0; j < num_hijos; j++) {
                scanf("%lld", &fuerza);
                fuerza = fuerza*midi;
                if (fuerza > f_mejor) f_mejor = fuerza;
            }
            mejores[i] = f_mejor;
        }
        sort(mejores, mejores+num_familias);
        reverse(mejores, mejores+num_familias);
        for (i = 0; i < num_familias; i++) printf("%lld ", mejores[i]);
        printf("\n");
    }
    return 0;
}
