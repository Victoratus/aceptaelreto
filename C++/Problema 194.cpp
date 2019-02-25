#include <stdio.h>
#include <stdlib.h>

int leer_tam(char *str) {
    char aux = '0';
    int i = 0;
    while (aux != '\n') {
        scanf("%c", &aux);
        str[i] = aux;
        i++;
    }
    return i;
}

int recuento(char *desc, int tam, int pos) {
    if (desc[pos] == '.') {
        if (pos + 3 < tam) return 1 + recuento(desc, tam, pos+3);
        else return 1;
    } else {
        if (pos + 1 < tam) return recuento(desc, tam, pos+1);
        else return 0;
    }
}

int main() {
    int num_char, i;
    char *desc = (char *) calloc(10001, sizeof(char));
    int tam;

    scanf("%d ", &num_char);
    for (i = 0; i < num_char; i++) {
        tam = leer_tam(desc);
        printf("%d\n", recuento(desc, tam, 0));
    }
}