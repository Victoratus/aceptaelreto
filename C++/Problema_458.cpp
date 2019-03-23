#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <queue>          
#include <vector>         
#include <functional>     

using namespace std;

int main() {
    long long mayorPositivo[2];
    long long menorPositivo;
    long long mayorNegativo[2];
    long long menorNegativo;
    long long productoPos, productoNeg;
    priority_queue<long long, vector<long long>, greater<long long> > heap; 

    long long aux;

    int num, i;

    while(true) {
        scanf("%d", &num);
        if (num == 0) return 0;

        mayorPositivo[0] = -1;
        mayorPositivo[1] = -1;
        menorPositivo = LLONG_MAX;
        mayorNegativo[0] = 1;
        mayorNegativo[1] = 1;
        menorNegativo = LLONG_MIN;

        for (i = 0; i < num; i++) {
            scanf("%lld", &aux);
            if (aux > 0) {
                if (aux > mayorPositivo[0] || aux > mayorPositivo[1]) {
                    if (mayorPositivo[0] < mayorPositivo[1]) {
                        mayorPositivo[0] = aux;
                    } else {
                        mayorPositivo[1] = aux;
                    }
                } else if (aux < menorPositivo) {
                    menorPositivo = aux;
                }
            } else if (aux < 0) {
                if (aux < mayorNegativo[0] || aux < mayorNegativo[1]) {
                    if (mayorNegativo[0] > mayorNegativo[1]) {
                        mayorNegativo[0] = aux;
                    } else {
                        mayorNegativo[1] = aux;
                    }
                } else if (aux > menorNegativo) {
                    menorNegativo = aux;
                }
            } else if (aux == 0) {
                if (menorNegativo != 0) {
                    menorNegativo = 0;
                } else {
                    menorPositivo = 0;
                }
            }
        }

        productoPos = mayorPositivo[0]*mayorPositivo[1];
        productoNeg = mayorNegativo[0]*mayorNegativo[1];

        if (productoPos >= 0 && productoNeg >= 0) {
            if (productoPos > productoNeg) {
                printf("%lld\n", productoPos);
            } else {
                printf("%lld\n", productoNeg);
            }
        } else if (productoPos >= 0) {
            printf("%lld\n", productoPos);
        } else if (productoNeg >= 0) {
            printf("%lld\n", productoNeg);
        } else {
            if (mayorPositivo[0] != -1) {
                heap.push(mayorPositivo[0]);
            }
            if (mayorPositivo[1] != -1) {
                heap.push(mayorPositivo[1]);
            }
            if (menorPositivo != LLONG_MAX) {
                heap.push(menorPositivo);
            }
            if (mayorNegativo[0] != 1) {
                heap.push(-mayorNegativo[0]);
            }
            if (mayorNegativo[1] != 1) {
                heap.push(-mayorNegativo[1]);
            }
            if (menorNegativo != LLONG_MIN) {
                heap.push(-menorNegativo);
            }
            aux = heap.top();
            heap.pop();
            printf("%lld\n", -aux*heap.top());

            while(!heap.empty()) heap.pop();
        }
    }
}