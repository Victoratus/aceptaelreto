#include <stdlib.h>
#include <stdio.h>

int main() {
    long long grosor, altura;
    long long dobleces;
    while (true) {
        scanf("%lld %lld", &grosor, &altura);
        if (feof(stdin)) return 0;
        altura = 1000000*altura;
        dobleces = 0;
        while (grosor < altura) {
            dobleces++;
            grosor = grosor*2;
        }
        printf("%lld\n", dobleces);
    }
    return 0;
}
