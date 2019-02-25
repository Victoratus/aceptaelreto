#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int i, j, num_eventos, eventos_acaecidos, evento_actual;
    int eventos[200000];
    while (true) {
        scanf("%d", &num_eventos);
        eventos_acaecidos = 0;
        for (i = 0; i < num_eventos; i++) {
            scanf("%d", &evento_actual);
            if (evento_actual == 0) {
                if (eventos_acaecidos == 0) {
                    printf("ECSA\n");
                    continue;
                }
                sort(eventos, eventos+eventos_acaecidos);
                printf("%d ", eventos[(eventos_acaecidos)/2]);
                for (j = (eventos_acaecidos+1)/2; j < eventos_acaecidos-1; j++) {
                    eventos[j] = eventos[j+1];
                }
                eventos_acaecidos--;
            } else {
                eventos[eventos_acaecidos] = evento_actual;
                eventos_acaecidos++;
            }
        }
        printf("\n");
    }
}
