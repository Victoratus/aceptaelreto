#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void warshall(int costes[200][200], int num_importantes) {
    int i, j, k;

    for (i = 0; i < num_importantes; i++) {
        for (j = 0; j < num_importantes; j++) {
            if (j == i) continue;
            for (k = 0; k < num_importantes; k++) {
                if (k == i || k == j) continue;
                if (costes[i][k] == __INT_MAX__ || costes[j][i] == __INT_MAX__) continue;
                
                if (costes[i][k]+costes[j][i] < costes[j][k]) {     //Inicializo los arrays a 0, de 
                    costes[j][k] = costes[i][k]+costes[j][i];         
                    costes[k][j] = costes[j][k];                               // manera que tengo que comprobar
                }                                                                   // si es 0 la posición a sobreescribir
            }
        }
    }
}


//Esta función te devuelve la posicion del nodo importante con menos coste acumulado asociado
int menor_coste(int costes[200][200], int num_importantes) {
    int pos_menor_coste = -1;
    int i, j, coste_acumulado, coste_acumulado_anterior = 9999999; //El 9999999 es indiferente
    for (i = 0; i < num_importantes; i++) {
        coste_acumulado = 0;
        for (j = 0; j < num_importantes; j++) {
            coste_acumulado += costes[i][j];
        }
        if (pos_menor_coste == -1) {
            pos_menor_coste = i;
        } else if (coste_acumulado == coste_acumulado_anterior) {
            if (i < pos_menor_coste) {
                pos_menor_coste = i;
            }
            coste_acumulado_anterior = coste_acumulado;
        } else if (coste_acumulado < coste_acumulado_anterior) {
            pos_menor_coste = i;
            coste_acumulado_anterior = coste_acumulado;
        }
    }
    return pos_menor_coste;
}

int main() {
    int num_nodos, num_importantes, num_lineas, i, j, k, id1, id1_c, id2, id2_c, aux;
    char importantes[10000];
    int id_a_id_importante[10000];
    int lineas[100][101]; //En la posicion 101 se almacena el tamaño de la linea
    int costes[200][200];
    int ids_importantes[200];   //Uso este array para almacenar la información de las ids de las estaciones importantes,
                            // para así no tener que buscar luego en el array "importantes" después de aplicar warshall
                            // para hallar la solución.


    while (true) {
        scanf("%d %d", &num_nodos, &num_lineas);
        if (num_nodos == 0 && num_lineas == 0) return 0;

        for (i = 0; i < num_nodos; i++) importantes[i] = 0;
        num_importantes = 0;

        for (i = 0; i < num_lineas; i++) {
            j = 0;
            while (true) {
                scanf("%d", &aux);
                if (aux == 0) {
                    lineas[i][100] = j;
                    break;
                }
                aux--;
                lineas[i][j] = aux;
                j++;
            }
        }

        for (i = 0; i < num_lineas; i++) {
            for (j = 0; j < lineas[i][100]; j++) {
                id1 = lineas[i][j];
                if (importantes[id1] < 5+i && importantes[id1] != 0) importantes[id1] = 1; //La estacion es importante
                if (importantes[id1] == 0) importantes[id1] = 5+i; //La estacion solo aparece en una linea de momento
            }
        }

        for (i = 0; i < num_nodos; i++) {   //Almaceno las que son importantes
            if (importantes[i] == 1) {
                ids_importantes[num_importantes] = i;
                id_a_id_importante[i] = num_importantes;
                num_importantes++;
            }
        }

        for (i = 0; i < num_importantes; i++) {
            for (j = 0; j <= i; j++) {
                if (i == j) {
                    costes[i][j] = 0;
                    continue;
                }
                costes[i][j] = __INT_MAX__;
            }
        }

        for (i = 0; i < num_lineas; i++) {  //Para cada línea
            for (j = 0; j < lineas[i][100]; j++) {  //Recorro todas las posiciones
                id1 = lineas[i][j];
                if (importantes[id1] == 1) {   //Hasta que encuentro una importante
                    id1_c = id_a_id_importante[id1];
                    for (k = j+1; k < lineas[i][100]; k++) {    //Entonces recorro el resto de la línea
                        id2 = lineas[i][k];
                        if (importantes[id2] == 1) { //Si alguna de las siguientes que encuentro es importante actualizo su coste
                            id2_c = id_a_id_importante[id2];
                            if (costes[id1_c][id2_c] > k-j || costes[id1_c][id2_c] == __INT_MAX__) {
                                costes[id1_c][id2_c] = k-j;
                                costes[id2_c][id1_c] = k-j;
                            }
                        }
                    }
                }
            }
        }

        for (i = 0; i < num_importantes; i++) {
            for (j = 0; j < num_importantes; j++) {
                printf("%d ", costes[i][j]);
            }
            printf("\n");
        }

        warshall(costes, num_importantes);

        for (i = 0; i < num_importantes; i++) {
            for (j = 0; j < num_importantes; j++) {
                printf("%d ", costes[i][j]);
            }
            printf("\n");
        }


        printf("%d\n", ids_importantes[menor_coste(costes, num_importantes)]+1);
    }
}