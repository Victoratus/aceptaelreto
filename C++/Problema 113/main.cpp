#include <stdio.h>
#include <stdlib.h>

void ver() {
    int *velocidades_posibles = (int *) calloc(10000, sizeof(int));
    int dis_total = 0, i;

    for (i = 0; i < num_semaforos; i++) {
        dis_total += distancias[i];
    }
    for (i = 0; i < dis_total/)


}

int main () {
    int vel_maxima, num_semaforos, i;
    int *t_abierto = (int *) calloc(100, sizeof(int));
    int *t_cerrado = (int *) calloc(100, sizeof(int));
    int *distancias = (int *) calloc(100, sizeof(int));
    while (true) {
        scanf("%d %d", &num_semaforos, &vel_maxima);
        if (num_semaforos == 0 && vel_maxima == 0) return 0;
        for (i = 0; i < num_semaforos; i++) {
            scanf("%d %d %d", &distancias[i], &t_cerrado[i], &t_abierto[i]);
        }
    }
    return 0;
}
