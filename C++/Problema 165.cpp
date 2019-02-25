#include <stdio.h>

int main () {
    char aux;
    int hyperpar;
    while (true) {
        hyperpar = 1;
        while (true) {
            scanf("%c", &aux);
            if (aux == '-') return 0;
            if (aux == '\n') break;
            if (aux%2 != 0) {
                hyperpar = 0;
            }
        }
        if (hyperpar == 1) printf("SI\n");
        else printf("NO\n");
    }
}