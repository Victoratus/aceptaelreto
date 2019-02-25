#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void limpiar(int *apariciones) {
     int i;
     for (i = 0; i < 10; i++) apariciones[i] = 0;
}

int subnormal(int *apariciones) {
    if (apariciones[0] == apariciones[1] &&
        apariciones[1] == apariciones[2] &&
        apariciones[2] == apariciones[3] &&
        apariciones[3] == apariciones[4] &&
        apariciones[4] == apariciones[5] &&
        apariciones[5] == apariciones[6] &&
        apariciones[6] == apariciones[7] &&
        apariciones[7] == apariciones[8] &&
        apariciones[8] == apariciones[9]) {
            return 1;
    }
    return 0;
}

int main() {
    int i;
    char str[1001];
    int *apariciones = (int *) calloc(10, sizeof(int));
    while (true) {
        scanf("%s", str);
        if (feof(stdin)) return 0;
        i = 0;
        while (true) {
            if (str[i] == '\0') break;
            if (str[i] == '0'){
                apariciones[0]++;
                i++;
                continue;
            }
            if (str[i] == '1'){
                apariciones[1]++;
                i++;
                continue;
            }
            if (str[i] == '2'){
                apariciones[2]++;
                i++;
                continue;
            }
            if (str[i] == '3'){
                apariciones[3]++;
                i++;
                continue;
            }
            if (str[i] == '4'){
                apariciones[4]++;
                i++;
                continue;
            }
            if (str[i] == '5'){
                apariciones[5]++;
                i++;
                continue;
            }
            if (str[i] == '6'){
                apariciones[6]++;
                i++;
                continue;
            }
            if (str[i] == '7'){
                apariciones[7]++;
                i++;
                continue;
            }
            if (str[i] == '8'){
                apariciones[8]++;
                i++;
                continue;
            }
            if (str[i] == '9'){
                apariciones[9]++;
                i++;
                continue;
            }
        }
        if (subnormal(apariciones) == 1) {
            printf("subnormal\n");
        } else {
            printf("no subnormal\n");
        }
        limpiar(apariciones);
    }
    return 0;
}
