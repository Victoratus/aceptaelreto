#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main () {
    int num_grupos, num_aulas, i, j, k, encontrados;
    int n, ultima_encontrada;
    int tam_aulas[100000];
    int tam_grupos[100000];
    while (true) {
        scanf("%d %d", &num_grupos, &num_aulas);
        if (feof(stdin)) return 0;
        for (i = 0; i < num_grupos; i++) scanf("%d", &tam_grupos[i]);
        for (i = 0; i < num_aulas; i++) scanf("%d", &tam_aulas[i]);
        if (num_grupos > num_aulas) {
            printf("NO\n");
            continue;
        }
        sort(tam_grupos, tam_grupos+num_grupos);
        sort(tam_aulas, tam_aulas+num_aulas);
        encontrados = 0;
        ultima_encontrada = num_aulas-num_grupos-1;
        for (i = 0; i < num_grupos; i++) {
            for (j = ultima_encontrada+1; j < num_aulas; j++) {
                if (tam_grupos[i] <= tam_aulas[j]) {
                    ultima_encontrada = j;
                    encontrados++;
                    break;
                }
            }
            if (encontrados != i+1) break;
        }
        if (encontrados != num_grupos) {
            printf("NO\n");
        } else {
            printf("SI\n");
        }
    }
    return 0;
}
