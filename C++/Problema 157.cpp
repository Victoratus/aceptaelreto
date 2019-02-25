#include <stdio.h>

int num_dias (int mes, int dia) {
    if (mes == 1) {
        return 365-dia;
    } else if (mes == 2) {
        return 334-dia;
    } else if (mes == 3) {
        return 306-dia;
    } else if (mes == 4) {
        return 275-dia;
    } else if (mes == 5) {
        return 245-dia;
    } else if (mes == 6) {
        return 214-dia;
    } else if (mes == 7) {
        return 184-dia;
    } else if (mes == 8) {
        return 153-dia;
    } else if (mes == 9) {
        return 122-dia;
    } else if (mes == 10) {
        return 92-dia;
    } else if (mes == 11) {
        return 61-dia;
    } else if (mes == 12) {
        return 31-dia;
    }
    return -1;
}

int main () {
    int i, num_casos;
    int dia, mes;

    scanf("%d ", &num_casos);
    for (i = 0; i < num_casos; i++) {
        scanf("%d %d", &dia, &mes);
        printf("%d\n", num_dias(mes, dia));
    }

    return 0;
}