#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Distancias {
    int izq;
    int der;
    int arr;
    int aba;
};

int main() {
    char desc[100][102];
    Distancias **distancias;
    char aux;
    char dir[15];
    int col, filas, consultas, i, j, filaAux, colAux, distancia_temp;

    while (true) {
        scanf("%d %d", &filas, &col);

        if (col == 0) return 0;

        distancias = (Distancias **) malloc(filas*sizeof(Distancias *));
        for (i = 0; i < filas; i++) {
            distancias[i] = (Distancias *) calloc(col, sizeof(Distancias));
        }

        for (i = 0; i < filas; i++) {
            scanf("%s", &desc[i]);
        }

        
        for (i = 0; i < filas; i++) {
            distancia_temp = -1;
            colAux = 0;
            while (colAux != col) {
                if (desc[i][colAux] == '.') {
                    distancias[i][colAux].izq = distancia_temp;
                    if (distancia_temp != -1) {
                        distancia_temp++;
                    }
                } else {
                    distancia_temp = 0;
                }
                colAux++;
            }
        }

        for (i = 0; i < filas; i++) {
            distancia_temp = -1;
            colAux = col-1;
            while (colAux != -1) {
                if (desc[i][colAux] == '.') {
                    distancias[i][colAux].der = distancia_temp;
                    if (distancia_temp != -1) {
                        distancia_temp++;
                    }
                } else {
                    distancia_temp = 0;
                }
                colAux--;
            }
        }

        for (i = 0; i < col; i++) {
            distancia_temp = -1;
            filaAux = 0;
            while (filaAux != filas) {
                if (desc[filaAux][i] == '.') {
                    distancias[filaAux][i].arr = distancia_temp;
                    if (distancia_temp != -1) {
                        distancia_temp++;
                    }
                } else {
                    distancia_temp = 0;
                }
                filaAux++;
            }
        }

        for (i = 0; i < col; i++) {
            distancia_temp = -1;
            filaAux = filas-1;
            while (filaAux != -1) {
                if (desc[filaAux][i] == '.') {
                    distancias[filaAux][i].aba = distancia_temp;
                    if (distancia_temp != -1) {
                        distancia_temp++;
                    }
                } else {
                    distancia_temp = 0;
                }
                filaAux--;
            }
        }

        /*for (i = 0; i < filas; i++) {
            for (j = 0; j < col; j++) {
                printf("%d", distancias[i][j].der+1);
            }
            printf("\n");
        }*/


        scanf("%d", &consultas);
        for (i = 0; i < consultas; i++) {
            scanf("%d %d", &filaAux, &colAux);
            scanf("%s", &dir);
            if (!strcmp(dir, "ARRIBA")) {
                if (distancias[filaAux-1][colAux-1].arr != -1) {
                    printf("%d\n", distancias[filaAux-1][colAux-1].arr+1);
                } else printf("NINGUNO\n");
            } else if (!strcmp(dir, "DERECHA")) {
                if (distancias[filaAux-1][colAux-1].der != -1) {
                    printf("%d\n", distancias[filaAux-1][colAux-1].der+1);
                } else printf("NINGUNO\n");
            } else if (!strcmp(dir, "IZQUIERDA")) {
                if (distancias[filaAux-1][colAux-1].izq != -1) {
                    printf("%d\n", distancias[filaAux-1][colAux-1].izq+1);
                } else printf("NINGUNO\n");               
            } else {
                if (distancias[filaAux-1][colAux-1].aba != -1) {
                    printf("%d\n", distancias[filaAux-1][colAux-1].aba+1);
                } else printf("NINGUNO\n");
            }
        }
        printf("---\n");
        for (i = 0; i < filas; i++) {
            free(distancias[i]);
        }
        free(distancias);
    }

}