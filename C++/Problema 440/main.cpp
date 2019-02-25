#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
        long long num_grupos, num_escaladores, vel_aux, vel_lider, grupo_min, grupo_max;
        long long *tamanio_grupos;
        long long i;
        while (true) {
            scanf("%lld", &num_escaladores);
            if (num_escaladores == 0) break;
            vel_lider = 1000000001;
            num_grupos = 0;
            tamanio_grupos = (long long *) calloc(num_escaladores, sizeof(long long));
            for (i = 0; i < num_escaladores; i++) {
                scanf("%lld", &vel_aux);
                if (vel_aux >= vel_lider) {
                    tamanio_grupos[num_grupos-1]++;
                } else {
                    num_grupos++;
                    vel_lider = vel_aux;
                    tamanio_grupos[num_grupos-1]++;
                }
            }
            grupo_max = tamanio_grupos[0];
            grupo_min = tamanio_grupos[0];
            for (i = 1; i < num_grupos; i++) {
                if (tamanio_grupos[i] > grupo_max) grupo_max = tamanio_grupos[i];
                if (tamanio_grupos[i] < grupo_min) grupo_min = tamanio_grupos[i];
            }
            printf("%lld %lld %lld\n", num_grupos, grupo_min, grupo_max);
            free(tamanio_grupos);
        }
        return 0;
}
