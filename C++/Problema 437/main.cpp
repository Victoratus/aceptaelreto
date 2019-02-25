#include <stdio.h>
#include <stdlib.h>

int horas_fin, minutos_fin, segundos_fin;

void resta_horas(int horas1, int minutos1, int segundos1, int horas2, int minutos2, int segundos2) {
    int acarreo;
    if (segundos1 >= segundos2) {
        segundos_fin = segundos1-segundos2;
        acarreo = 0;
    } else {
        segundos_fin = 60+segundos1-segundos2;
        acarreo = 1;
    }
    if (minutos1 >= minutos2+acarreo) {
        minutos_fin = minutos1-minutos2-acarreo;
        acarreo = 0;
    } else {
        minutos_fin = 60+minutos1-minutos2-acarreo;
        acarreo = 1;
    }
    horas_fin = horas1-horas2-acarreo;
}

int main () {
    int i, cantidad, horas, minutos, segundos;

    scanf("%d", &cantidad);
    for (i = 0; i < cantidad; i++) {
        scanf("%d:%d:%d", &horas, &minutos, &segundos);
        resta_horas(24, 0, 0, horas, minutos, segundos);
        printf("%02d:%02d:%02d\n", horas_fin, minutos_fin, segundos_fin);
    }
    return 0;
}
