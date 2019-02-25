#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int abdb;
int balanceado;

typedef struct Arbol{
    int valor, balanceo;
    Arbol *izq;
    Arbol *der;
};

void es_abdb(Arbol *arbol) {
    if (arbol->izq != NULL && arbol->valor < arbol->izq->valor) {
        abdb = 0;
        return;
    }
    if (arbol->der != NULL && arbol->valor > arbol->der->valor) {
        abdb = 0;
        return;
    }
    if (arbol->izq != NULL) es_abdb(arbol->izq);
    if (arbol->der != NULL) es_abdb(arbol->der);
}

void esta_balanceado(Arbol *arbol) {
    if (arbol->izq != NULL) esta_balanceado(arbol->izq);
    if (arbol->der != NULL) esta_balanceado(arbol->der);
    if (arbol->izq == NULL && arbol->der == NULL) {
        arbol->balanceo = 0;
    }
    arbol->balanceo = 0;
    if (arbol->izq != NULL) {
        arbol->balanceo += arbol->izq->balanceo;
    }
    if (arbol->der != NULL) {
        arbol->balanceo -= arbol->der->balanceo;
    }
    if (arbol->balanceo > 1 || arbol->balanceo < -1) {
        balanceado = 0;
    }
}

Arbol *genera_arbol(char *arbol_char, int pos) {
    Arbol *arbol = (Arbol *) malloc(sizeof(Arbol));
    arbol->valor = arbol_char[pos];
    if (arbol_char[pos+1] != -1) arbol->izq = genera_arbol(arbol_char, pos+1);
    else arbol->izq = NULL;
    if (arbol_char[pos+2] != -1) arbol->der = genera_arbol(arbol_char, pos+2);
    else arbol->der = NULL;
    return arbol;
}

void libera_arbol(Arbol *arbol) {
    if (arbol->izq != NULL) libera_arbol(arbol->izq);
    if (arbol->der != NULL) libera_arbol(arbol->der);
    free(arbol);
}

int main() {
    int i, num_arboles;
    char arbol_char[4001];
    Arbol *arbol;

    scanf("%d", &num_arboles);
    for (i = 0; i < num_arboles; i++) {
        scanf("%s", arbol_char);
        arbol = genera_arbol(arbol_char, 0);
        abdb = 1;
        balanceado = 1;
        es_abdb(arbol);
        esta_balanceado(arbol);
        if (abdb == 1 && balanceado == 1) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
        libera_arbol(arbol);
    }
    return 0;
}
