#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int familiares[200000];

int comp(int a, int b) {
    if (a <= b) return 1;
    else return 0;
}

int main() {
    int num_familiares, peso_max;
    int i;
    int total, rango;

    while (true) {
        scanf("%d %d", &num_familiares, &peso_max);
        if (num_familiares == 0) return 0;

        for (i = 0; i < num_familiares; i++) {
            scanf("%d", &familiares[i]);
        }
        std::sort(familiares, familiares+i);

        total = 0;

        for (i = 0; i < num_familiares; i++) {
            rango = std::upper_bound(familiares[i+1], familiares[num_familiares], peso_max-familiares[i], &comp);
            total += rango-i-1;
        }

        printf("%d\n", total);
    }
}