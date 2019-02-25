#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct {
    int dias;
    int meses;
    int anios;
} Fecha;

int fecha_a_pos(int dias, int meses, int anios) {
    int pos;

    pos = 365*anios;

    if (meses == 1) return pos+dias;
    if (meses == 2) return pos+dias+31;
    if (meses == 3) return pos+dias+59;
    if (meses == 4) return pos+dias+90;
    if (meses == 5) return pos+dias+120;
    if (meses == 6) return pos+dias+151;
    if (meses == 7) return pos+dias+181;
    if (meses == 8) return pos+dias+212;
    if (meses == 9) return pos+dias+243;
    if (meses == 10) return pos+dias+273;
    if (meses == 11) return pos+dias+304;
    if (meses == 12) return pos+dias+334;
}

int main() {
    int *martis_por_dia, *martis_idos_por_dia;
    int num_viajes, i, j, aux, num_consultas;
    Fecha fecha_inicio_viaje, fecha_fin_viaje, fecha_inicio_siguiente_viaje;
    while (true) {
        scanf("%d", &num_viajes);
        if (num_viajes == 0) return 0;

        martis_por_dia = (int *) calloc(sizeof(int), 3649635);

        fecha_inicio_viaje.dias = 12;
        fecha_inicio_viaje.meses = 6;
        fecha_inicio_viaje.anios = 1968;

        for (i = 0; i < num_viajes; i++) {
            scanf("%d/%d/%d %d/%d/%d", &fecha_fin_viaje.dias, &fecha_fin_viaje.meses, &fecha_fin_viaje.anios, &fecha_inicio_siguiente_viaje.dias, &fecha_inicio_siguiente_viaje.meses, &fecha_inicio_siguiente_viaje.anios);
            aux = fecha_a_pos(fecha_fin_viaje.dias, fecha_fin_viaje.meses, fecha_fin_viaje.anios);
            if (aux != 3649635) martis_por_dia[aux]--;
            martis_por_dia[fecha_a_pos(fecha_inicio_viaje.dias, fecha_inicio_viaje.meses, fecha_inicio_viaje.anios)-1]++;
            fecha_inicio_viaje.dias = fecha_inicio_siguiente_viaje.dias;
            fecha_inicio_viaje.meses = fecha_inicio_siguiente_viaje.meses;
            fecha_inicio_viaje.anios = fecha_inicio_siguiente_viaje.anios;
        }
        martis_por_dia[fecha_a_pos(fecha_inicio_viaje.dias, fecha_inicio_viaje.meses, fecha_inicio_viaje.anios)-1]++;

        aux = 0;
        for (i = 0; i < 3649635; i++) {
            aux += martis_por_dia[i];
            martis_por_dia[i] = aux;
        }

        scanf("%d", &num_consultas);
        for (i = 0; i < num_consultas; i++) {
            scanf("%d/%d/%d", &fecha_fin_viaje.dias, &fecha_fin_viaje.meses, &fecha_fin_viaje.anios);
            printf("%d\n", martis_por_dia[fecha_a_pos(fecha_fin_viaje.dias, fecha_fin_viaje.meses, fecha_fin_viaje.anios)-1]);
        }

        free(martis_por_dia);
    }
}
