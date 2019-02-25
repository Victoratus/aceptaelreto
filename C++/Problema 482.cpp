#include <stdio.h>


int main () {
    char aux;
    short negro, gris, fin;
    while (true) {
        negro = 0;
        gris = 0;
        fin = 1;
        while (true) {
            scanf(" %c", &aux);
            if (aux == '.' && fin == 1) return 0;
            fin = 0;
            if (aux == '.') break;
            else if (aux == 'N') negro = !negro;
            else if (aux == 'G') gris = !gris;
        }
        if (negro == 1 && gris == 1) printf("PAREJA MIXTA\n");
        else if (negro == 1) printf("NEGRO SOLITARIO\n");
        else if (gris == 1) printf("GRIS SOLITARIO\n");
        else printf("EMPAREJADOS\n");
    }
}