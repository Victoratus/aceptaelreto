#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

int main () {
    int a, aux, i;
    int encontrado;
    int encontrados[20001];
    stack <int> pos;
    while (true) {
        scanf("%d", &a);
        if (a == 0) return 0;
        for (i = 0; i <= a; i++) encontrados[i] = 0;
        while(!pos.empty()) pos.pop();
        encontrados[1] = 1;
        encontrado = 0;
        pos.push(1);
        while (!pos.empty()) {
            aux = pos.top();
            pos.pop();
            if (aux == a) {
                encontrado = 1;
                break;
            }
            if (aux+5 <= a && encontrados[aux+5] == 0) {
                encontrados[aux+5] = 1;
                pos.push(aux+5);
            }
            if (aux*3 <= a && encontrados[aux*3] == 0) {
                encontrados[aux*3] = 1;
                pos.push(aux*3);
            }
        }
        if (encontrado == 1) printf("SI\n");
        else printf("NO\n");
    }
}