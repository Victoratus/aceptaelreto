#include <stdlib.h>
#include <stdio.h>

int leer(char *num) {
    char aux;
    int i = 0;
    while (true) {
        scanf("%c", &aux);
        if (aux == '\n') break;
        num[i] = aux;
        i++;
    }
    return i;
}

int main() {
    char num[9];
    int i, num_reps, len;
    int aux, pos, len_aux;

    scanf("%d ", &num_reps);
    for (i = 0; i < num_reps; i++) {
        len = leer(num);
        len_aux = len;
        pos = 0;
        while(true) {
            aux = (int) num[pos];
            if (aux == 'a' && len_aux == 0 && pos == 0) {
                printf("SALTARINES\n");
                break;
            }
            if (aux == 'a') {
                printf("NORMALES\n");
                break;
            }
            num[pos] = 'a';
            pos = (int) (pos + aux - (int) '0')%len;
            len_aux--;
        }
    }
    return 0;
}