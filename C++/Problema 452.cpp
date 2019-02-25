#include <stdlib.h>
#include <stdio.h>

int abs (int a) {
    if (a < 0) return -a;
    return a;
}

int main () {
    int num_numeros, i, j, resta;
    int numeros_salidos[2000];
    int *numeros_imprimir = (int *) malloc(1);
    while (true) {
        scanf("%d ", &num_numeros);
        if (num_numeros == 0) return 0;
        free(numeros_imprimir);
        numeros_imprimir = (int *) calloc(2000, sizeof(int));
        for (i = 0; i < num_numeros; i++) {
            scanf("%d ", &numeros_salidos[i]);
        }
        for (i = 0; i < num_numeros; i++) {
            for (j = i+1; j < num_numeros; j++) {
                resta = abs(numeros_salidos[i]-numeros_salidos[j]);
                numeros_imprimir[resta] = 1;
            }
        }
        for (i = 0; i < 2000; i++) {
            if (numeros_imprimir[i] == 1) {
                printf("%d", i);
                break;
            }
        }
        for (i++; i < 2000; i++) {
            if (numeros_imprimir[i] == 1) printf(" %d", i);
        }
        printf("\n");
    }
}