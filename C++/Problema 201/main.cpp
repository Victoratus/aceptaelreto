#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ninguno_mas_de_uno = 1;
int todos_exactamente_dos = 1;

void read_line(char *str) {
    int i = 0;
    while (true) {
        scanf("%c", &str[i]);
        if (str[i] == '\n') return;
        i++;
    }
}

int generador_arbol(char *str, int indice) {
    short hi, hd;

    if (str[indice] == '.') return 0;

    if (indice+1 <= (strlen(str)) && str[indice+1] != '.') hi = 1;
    else hi = 0;
    if (indice+2 <= (strlen(str)) && str[indice+2] != '.') hd = 1;
    else hd = 0;

    if (hi == 1) generador_arbol(str, indice+1);
    if (hd == 1) generador_arbol(str, indice+2);

    if (hi == 1 && hd == 1) {
        ninguno_mas_de_uno = 0;
        return 0;
    }
    if (hi == 1 || hd == 1) {
        todos_exactamente_dos = 0;
        return 0;
    }
    return 0;
}

int main() {
    char familia[100001];
    while (true) {
        scanf("%s", familia);
        if (familia[0] == '.') return 0;
        generador_arbol(familia, 0);
        if (ninguno_mas_de_uno == 1) printf("1");
        if (todos_exactamente_dos == 1) printf("2");
        if (ninguno_mas_de_uno == 0 && todos_exactamente_dos == 0) printf("N");
        printf("\n");
        ninguno_mas_de_uno = 1;
        todos_exactamente_dos = 1;
    }
}
