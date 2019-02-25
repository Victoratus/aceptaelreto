#include <stdio.h>
#include <stdlib.h>

void limpiar (int *a) {
    int i;
    for (i = 0; i < 50; i++) a[i] = -1;
}

int main () {
    int a, b, aux1, aux2, i;
    int si, b_real;
    int *regala_a = (int *) malloc(50*sizeof(int));
    int *es_regalado_por = (int *) malloc(50*sizeof(int));
    
    while (true) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        limpiar(regala_a);
        limpiar(es_regalado_por);
        b_real = b;
        for (i = 0 ; i < b; i++) {
            scanf("%d %d", &aux1, &aux2);
            if (regala_a[aux1-1] == 1) b_real--;
            else regala_a[aux1-1] = 1;
            if (es_regalado_por[aux2-1] == 1) b_real--;
            else es_regalado_por[aux2-1] = 1;
        }
        if (a-b_real > 2) {
            printf("NO\n");
            continue;
        }
        if (a-b_real <= 1) {
            printf("SI\n");
            continue;
        }
        si = -1;
        for (i = 0; i < a; i++) {
            if (regala_a[i] == -1 && es_regalado_por[i] == -1) {
                si = 1;
                break;
            }
        }

        if (si == 1) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}