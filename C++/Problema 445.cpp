#include <stdio.h>
#include <stdlib.h>


int main () {
    int num_actividades, i, j, k, l;
    int inicio, fin;
    int **actividades_companieros = (int **) malloc(1);
    int num_companieros = 0;
    int *num_actividades_por_companiero  = (int *) malloc(1);
    while (true) {
        scanf("%d", &num_actividades);
        if (feof(stdin)) return 0;
        for (i = 0; i < num_companieros; i++) {
            free(actividades_companieros[i]);
        }
        free(num_actividades_por_companiero);
        free(actividades_companieros);
        num_companieros = 1;
        actividades_companieros = (int **) malloc(sizeof(int *));
        num_actividades_por_companiero = (int *) malloc(sizeof(int));
        num_actividades_por_companiero[0] = 0;
        for (i = 0; i < num_actividades; i++) {
            scanf("%d %d", &inicio, &fin);
            for (j = 0; j < num_companieros; j++) {
                for (k = 0; k < num_actividades_por_companiero[j]*2; k++) {
                    if (actividades_companieros[j][k] > inicio) break; 
                }
                // ¿Puede ir el compañeno j?
                if (num_actividades_por_companiero[j] == 0 || actividades_companieros[j][k] > fin) {  // Puede ir el compañero j
                    actividades_companieros[j] = (int *) realloc(actividades_companieros[j], (num_actividades_por_companiero[j]+2)*sizeof(int));
                    num_actividades_por_companiero++;
                    for (l = num_actividades_por_companiero[j]*2; l > k; l--) {
                        actividades_companieros[j][k+2] = actividades_companieros[j][k];
                    }

                }
            }
        }
    }
}