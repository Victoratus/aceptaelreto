#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main () {
    char str[1001];
    int num_signos, num_letras, i;
    while (true) {
        gets(str);
        if (feof(stdin)) return 0;
        i = 0;
        num_signos = 0;
        num_letras = 0;
        while (true) {
            if (str[i] == '\0') break;
            if (isalpha(str[i])) {
                num_letras++;
                i++;
                continue;
            }
            if (str[i] == '!') {
                num_signos++;
                i++;
                continue;
            }
            i++;
        }
        if (num_signos > num_letras) {
            printf("ESGRITO\n");
        } else {
            printf("escrito\n");
        }
    }
    return 0;
}
