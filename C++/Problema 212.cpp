#include <stdlib.h>
#include <stdio.h>


int main() {
    int *nodos = (int *) malloc(1);
    int num_nodos, num_aristas;
    int a, b;

    while(true) {
        scanf("%d", &num_aristas);
        if (num_aristas == 0) return 0;
        scanf("%d", &num_nodos);
        free(nodos);
        nodos = (int *) calloc(num_nodos, sizeof(int));
        for (int i = 0; i < num_aristas; i++) {
            scanf("%d %d", &a, &b);
            nodos[a-1]++;
            nodos[b-1]++;
        }
        a = 0;
        for (int i = 0; i < num_nodos; i++) {
            if (nodos[i]%2 != 0) {
                if (a < 3) a++;
                else break;
            }
        }
        if (a != 0 && a != 2) printf("NO\n");
        else printf("SI\n");
    }
}