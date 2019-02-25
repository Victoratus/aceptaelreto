#include <stdio.h>
#include <string.h>

void read_word(char *word) {
    int i = 0;
    while (true) {
        scanf("%c", &word[i]);
        if (word[i] == ' ' || word[i] == '\n') {
            word[i] = '\0';
            break;
        }
        i++;
    }
}

int main() {
    int num_abuelas, num_nombres, i, j;
    char aux, falsa;
    char nombre_real[11];
    char nombre_dicho[11];
    char nombre_patata[11];
    scanf("%d", &num_abuelas);
    scanf("%c", &aux);
    for (i = 0; i < num_abuelas; i++) {
        read_word(nombre_real);
        falsa = 0;
        scanf(" %d ", &num_nombres);
        for (j = 1; j < num_nombres; j++) {
            read_word(nombre_patata);
            if (falsa == 0 && !strcmp(nombre_patata, nombre_real)) {
                falsa = 1;
            }
        }
        read_word(nombre_dicho);
        if (falsa == 1) {
            printf("FALSA\n");
            continue;
        }
        if (!strcmp(nombre_real, nombre_dicho) && num_nombres > 1) printf("VERDADERA\n");
        else printf("FALSA\n");
    }
}