#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

long long es_collar;

void comprobar(long long *collar, long long i, long long tam) {
    if (i+1 == tam) {
        if (collar[i] > collar[i-1]) return;
        else {
            es_collar = 0LL;
            return;
        }
    }
    if (collar[i] == collar[i+1]) comprobar(collar, i+2, tam);
    else {
        es_collar = 0LL;
        return;
    }
}

int main () {
    long long collar[1000];
    long long tam;
    long long aux;
    long long i;
    while (true) {
        scanf("%lld", &aux);
        if (aux == 0LL) {
            return 0;
        }
        collar[0] = aux;
        tam = 1LL;
        while (true) {
            scanf("%lld", &aux);
            if (aux == 0LL) break;
            collar[tam] = aux;
            tam++;
        }
        es_collar = 1LL;
        if (tam%2 == 0LL) {
            es_collar = 0LL;
            printf("NO\n");
            continue;
        }
        sort(collar, collar+tam);
        comprobar(collar, 0LL, tam);
        if (es_collar == 0LL) printf("NO\n");
        else {
            if (tam != 1LL) {
                for (i = 0LL; i < tam; i+=2LL) printf("%lld ", collar[i]);
                for (i = tam-2LL; i > 2LL; i-=2LL) printf("%lld ", collar[i]);
                printf("%lld\n", collar[0]);
            } else printf("%lld\n", collar[0]);
        }
    }
    return 0;
}