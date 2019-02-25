#include <stdio.h>
#include <stdlib.h>

char stop;

typedef struct Nodo {
    short num_adjs;
    short *adjs;
};

typedef struct Grafo {
    short num_nodos;
    Nodo **nodos;
};

typedef struct Arbol {
    short num_adjs;
    Arbol **adjs;
};

Grafo *crear_grafo(short num_nodos) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->num_nodos = num_nodos;
    grafo->nodos = (Nodo **) malloc(num_nodos*sizeof(Nodo *));
    for (short i = 0; i < num_nodos; i++) {
        grafo->nodos[i] = (Nodo *) malloc(sizeof(Nodo));
        grafo->nodos[i]->num_adjs = 0;
    }
    return grafo;
}

void des_grafo(Grafo *grafo) {
    short i;
    for (i = 0; i < grafo->num_nodos; i++) {
        free(grafo->nodos[i]->adjs);
    }
    free(grafo->nodos);
    free(grafo);
}

Arbol *crear_arbol() {
    Arbol *arbol = (Arbol *) malloc(sizeof(Arbol));
    arbol->num_adjs = 0;
    arbol->adjs = NULL;
    return arbol;
}

void des_arbol(Arbol *arbol) {
    short i;
    for (i = 0; i < arbol->num_adjs; i++) des_arbol(arbol->adjs[i]);
    if (arbol->adjs != NULL) free(arbol->adjs);
    free(arbol);
}

void crear_conexion(Grafo *grafo, short id1, short id2) {
    grafo->nodos[id1]->num_adjs++;
    if (grafo->nodos[id1]->num_adjs == 1) {
        grafo->nodos[id1]->adjs = (short *) malloc(sizeof(short));
    } else {
        grafo->nodos[id1]->adjs = (short *) realloc(grafo->nodos[id1]->adjs, grafo->nodos[id1]->num_adjs*sizeof(short));
    }
    grafo->nodos[id1]->adjs[grafo->nodos[id1]->num_adjs-1] = id2;

    grafo->nodos[id2]->num_adjs++;
    if (grafo->nodos[id2]->num_adjs == 1) {
        grafo->nodos[id2]->adjs = (short *) malloc(sizeof(short));
    } else {
        grafo->nodos[id2]->adjs = (short *) realloc(grafo->nodos[id2]->adjs, grafo->nodos[id2]->num_adjs*sizeof(short));
    }
    grafo->nodos[id2]->adjs[grafo->nodos[id2]->num_adjs-1] = id1;
}

Arbol *extraer_arbol(Grafo *grafo, char *anad, short id) {
    Arbol *arbol;
    if (anad[id] == 1) {
        stop = 1;
        return NULL;
    } else {
        anad[id] = 1;
        arbol = (Arbol *) malloc(sizeof(Arbol));
        arbol->num_adjs = grafo->nodos[id]->num_adjs;
        arbol->adjs = (Arbol **) malloc(grafo->nodos[id]->num_adjs*sizeof(Arbol *));
        for (short i = 0; i < arbol->num_adjs; i++) {
            arbol->adjs[i] = extraer_arbol(grafo, anad, grafo->nodos[id]->adjs[i]);
            if (stop == 1) return NULL;
        }
    }
    return arbol;
}

int main() {
    short num_nodos, num_con;
    short id1, id2;
    short i;
    Grafo *grafo;
    Arbol *arbol;
    char *anad = NULL;

    while (true) {
        scanf("%hd", &num_nodos);
        scanf("%hd", &num_con);
        if (feof(stdin)) return 0;

        grafo = crear_grafo(num_nodos);
        anad = (char *) calloc(num_nodos, sizeof(char));
        stop = 0;

        for (i = 0; i < num_con; i++) {
            scanf("%hd %hd", &id1, &id2);
            crear_conexion(grafo, id1, id2);
        }

        arbol = extraer_arbol(grafo, anad, 0);

        if (stop == 1) {
            printf("NO\n");
        } else {
            i = 0;
            while (stop == 0 && i < num_nodos) {
                if (anad[i] == 0) stop = 1;
                i++;
            }
            if (stop == 1) {
                printf("NO\n");
            } else {
                printf("SI\n");
            }
        }

        des_arbol(arbol);
        des_grafo(grafo);
        free(anad);
    }
}
