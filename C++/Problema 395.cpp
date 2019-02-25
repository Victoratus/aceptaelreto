#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fila {
    char *caracteres;
};

void limpiar_cortesv(char **cortes) {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 19; j++) {
            cortes[i][j] = '0';
        }
    }
}

void limpiar_cortesh(char **cortes) {
    int i, j;
    for (i = 0; i < 19; i++) {
        for (j = 0; j < 20; j++) {
            cortes[i][j] = '0';
        }
    }
}

int main () {
    Fila *filas = (Fila *) malloc(20*sizeof(Fila));
    int n_filas, n_cols, i, j;
    char **cortes_verticales = (char **) malloc(20*sizeof(char *));
    char **cortes_horizontales = (char **) malloc(19*sizeof(char *));
    for (i = 0; i < 20; i++) {
        cortes_verticales[i] = (char *) malloc(19*sizeof(char));
        if (i < 19) cortes_horizontales[i] = (char *) malloc(20*sizeof(char));
        filas[i].caracteres = (char *) malloc(20*sizeof(char));
    }
    while (true) {
        scanf("%d %d", &n_filas, &n_cols);
        if (feof(stdin)) return 0;
        limpiar_cortesv(cortes_verticales);
        limpiar_cortesh(cortes_horizontales);
        for (i = 0; i < n_filas; i++) {
            scanf("%s", &filas[i].caracteres);
        } //Cortes verticales
        for (i = 0; i < n_filas; i++) {
            for (j = 0; j < n_cols-1; j++) {
                if (filas[i].caracteres[j] != filas[i].caracteres[j+1]) {
                    cortes_verticales[i][j] = '1';
                }
            }
        } //Cortes horizontales
        for (i = 0; i < n_filas-1; i++) {
            for (j = 0; j < n_cols; j++) {
                if (filas[i].caracteres[j] != filas[i+1].caracteres[j]) {
                    cortes_horizontales[i][j] = 1;
                }
            }
        }
        
    }
}