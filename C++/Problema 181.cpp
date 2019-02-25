#include <stdlib.h>
#include <stdio.h>
#include <queue> 

using namespace std;

int tam;
char pos[15][16];
int maneras[15][15];

void limpiar() {
    int i,j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            maneras[i][j] = 0;
        }
    }
}

void c_maneras() {
    queue<int> colax;
    queue<int> colay;
    int x, y;
    colax.push(0);
    colay.push(0);
    while (!colax.empty()) {
        x = colax.front();
        y = colay.front();
        colax.pop();
        colay.pop();
        if (x == y && x == tam-1) return;
        if (x+1 < tam && pos[y][x+1] != 'X') {
            maneras[y][x+1] += maneras[y][x];
            if (pos[y][x+1] == '.') {
                pos[y][x+1] = 'm';
                colay.push(y);
                colax.push(x+1);
            }
        }
        if (y+1 < tam && pos[y+1][x] != 'X') {
            maneras[y+1][x] += maneras[y][x];
            if (pos[y+1][x] == '.') {
                pos[y+1][x] = 'm';
                colay.push(y+1);
                colax.push(x);
            }
        }
    }
}

int main () {
    int i, j;
    while (true) {
        scanf("%d", &tam);
        if (tam == 0) return 0;
        for (i = tam-1; i > -1; i--) {
            scanf("%s", pos[i]);
        }
        limpiar();
        maneras[0][0] = 1;
        c_maneras();
        printf("%d\n", maneras[tam-1][tam-1]);
    }
}