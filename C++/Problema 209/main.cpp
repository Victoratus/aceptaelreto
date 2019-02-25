#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pos_mejor;
char movimiento;


int bbin_mod(int *pos_telefonos, int clave, int ip, int iu) {
    if (ip == iu) {
        pos_mejor = pos_telefonos[ip];
        return 0;
    }
    if (clave == pos_telefonos[(iu-ip)/2]) {
        pos_mejor = pos_telefonos[(iu-ip)/2];
        return 0;
    }
    if (clave < pos_telefonos[(iu-ip)/2]) bbin_mod(pos_telefonos, clave, ip, iu/2);
    else bbin_mod(pos_telefonos, clave, iu/2+1, iu);
    return 0;
}

int main() {
    char caracter;
    int pos_telefonos[500];
    int num_tel = 0;
    int pos = 0;
    int i, tam_tunel;
    int consultas;

    while (true) {
        while (true) {
            scanf("%c", &caracter);
            if (caracter == '\n') break;
            if (caracter == '.') {
                pos++;
                continue;
            }
            if (caracter == 'T') {
                pos_telefonos[num_tel] = pos;
                pos++;
                num_tel++;
            }
        }
        tam_tunel = pos;
        scanf("%d\n", &consultas);
        for (i = 0; i < consultas; i++) {
            scanf("%d\n", &pos);
            bbin_mod(pos_telefonos, pos, 0, num_tel);
            if (pos == pos_mejor) {
                printf("AQUI\n");
                continue;
            }
            if (pos <= tam_tunel/2) {
                if (pos_mejor < tam_tunel/2-pos) {
                    if (pos)
                }
                pos_mejor = 0;
            } else {
                pos_mejor = tam_tunel;
            }
        }
    }

    return 0;
}
