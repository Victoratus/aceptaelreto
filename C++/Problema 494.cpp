#include <stdio.h>
#include <stdlib.h>


int main() {
    int num, i;
    int pruebas[1000];
    int tam_per, salto, suposicion, anterior, aux;

    while (true) {
        scanf("%d", &num);
        if (num == 0) return 0;

        tam_per = 0;
        suposicion = 0;
        anterior = 0;
        scanf("%d", &aux);

        for (i = 0; i < num; i++) {
            scanf("%d", &salto);
            aux = salto;
            salto -= anterior;
            anterior = aux;
            if (tam_per != 0) {
                if (salto == pruebas[suposicion] && salto < tam_per) {
                    suposicion++;
                } else {
                    suposicion = 0;
                    pruebas[tam_per] = salto;
                    tam_per++;
                }
            } else {
                pruebas[tam_per] = salto;
                tam_per++;
                suposicion = 0;
            }
        }

        printf("%d\n", anterior+pruebas[suposicion]);
    }
}