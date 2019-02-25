#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int es_penta(char *palabra) {
    int a, e, i, o, u;
    int buc, len;
    a = 0;
    e = 0;
    i = 0;
    o = 0;
    u = 0;
    len = strlen(palabra);
    for (buc = 0; buc < len; buc++) {
        if (palabra[buc] == 'a') {
            a = 1;
            continue;
        }
        if (palabra[buc] == 'e') {
            e = 1;
            continue;
        }
        if (palabra[buc] == 'i') {
            i = 1;
            continue;
        }
        if (palabra[buc] == 'o') {
            o = 1;
            continue;
        }
        if (palabra[buc] == 'u') {
            u = 1;
            continue;
        }
    }
    if (a == 1 && e == 1 && i == 1 && o == 1 && u == 1) return 1;
    return 0;
}

int main() {
    char *palabra = (char *) malloc(sizeof(char)*51);
    int num_palabras, i;

    scanf("%d", &num_palabras);
    for (i = 0; i < num_palabras; i++) {
        scanf("%s", palabra);
        if (es_penta(palabra) == 1) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
