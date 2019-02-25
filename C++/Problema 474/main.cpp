#include <stdio.h>
#include <stdlib.h>

int abs (int a) {
    if (a < 0) return -a;
    return a;
}

int main () {
    int i, num_casos;
    int pos_spi, pos_a, pos_b;
    int recorrido;
    scanf("%d", &num_casos);
    for (i = 0; i < num_casos; i++) {
        scanf("%d %d %d", &pos_spi, &pos_a, &pos_b);
        recorrido = 0;
        if (abs(pos_spi-pos_a) < abs(pos_spi-pos_b)) {
            recorrido += abs(pos_spi-pos_a);
            recorrido += abs(pos_a-pos_b);
            printf("%d\n", recorrido);
        } else {
            recorrido += abs(pos_spi-pos_b);
            recorrido += abs(pos_a-pos_b);
            printf("%d\n", recorrido);
        }
    }
    return 0;
}
