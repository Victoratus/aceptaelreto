#include <stdlib.h>
#include <stdio.h>

long long pos_troz(int *trozos, int num_trozos) {
    int i, j;
    long long total;
    long long pos = -1;
    for (i = 0; i < num_trozos-1; i++) {
        total = 0;
        for (j = i+1; j < num_trozos; j++) {
            total += trozos[j];
            if (total > trozos[i]) break;
        }
        if (trozos[i] == total) {
            pos = i;
            break;
        }
    }
    return pos;
}

int main () {
    int i, num_trozos;
    long long pos;
    int trozos[100000];
    while (true) {
        scanf("%d", &num_trozos);
        if (num_trozos == 0) return 0;
        for (i = 0; i < num_trozos; i++) {
            scanf("%d", &trozos[i]);
        }
        pos = pos_troz(trozos, num_trozos);
        if (pos == -1) {
            printf("NO\n");
        } else {
            printf("SI %lld\n", pos+1);
        }
    }
    return 0;
}
