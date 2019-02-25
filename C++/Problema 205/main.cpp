#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int limite = 0;
int capicua = 0;

 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

void flip(char *numeros, int tam) {
    int i;
    char aux[tam];
    for (i = 0; i < tam; i++) {
        aux[tam-i-1] = numeros[i];
    }
    for (i = 0; i < tam; i++) {
        numeros[i] = aux[i];
    }
}

void print(char *numero, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%c", numero[i]);
    }
}

int es_capicua(int num) {
    char numero[11];
    int i, aux;

    itoa(num, numero);
    aux = strlen(numero);
    for (i = 0; i < aux/2; i++) {
        if (numero[i] != numero[aux-i-1]) {
            return 0;
        }
    }
    return 1;
}

int sumas(int num) {
    char numero1[11];
    int num1, num2;

    itoa(num, numero1);
    flip(numero1, strlen(numero1));
    num1 = atoi(numero1);
    num2 = num+num1;
    if (es_capicua(num2) == 1) {
        capicua = num2;
        return 1;
    }
    if (num2 > 1000000000) {
        limite = 1;
        return -1;
    }

    return sumas(num2)+1;
}

int main() {
    int i, nreps, num1, ret;

    scanf("%d", &nreps);
    for (i = 0; i < nreps; i++) {
        limite = 0;
        scanf("%d", &num1);
        ret = sumas(num1);
        if (limite == 0) {
            printf("%d %d\n", ret, capicua);
        } else {
            printf("Lychrel?\n");
        }
    }
}
