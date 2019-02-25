#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;


typedef struct Nodo {
    short n_con;
    short *con;
    char importante;
};

typedef struct Grafo {
    short num_nodos;
    Nodo *nodos;
};

Grafo *crear_grafo(short num_nodos) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->num_nodos = num_nodos;
    grafo->nodos = (Nodo *) calloc(num_nodos, sizeof(Nodo));
    for (short i = 0; i < num_nodos; i++) {
        grafo->nodos[i].con = NULL;
    }
    return grafo;
}

void destruir_grafo(Grafo *grafo) {
    for (short i = 0; i < grafo->num_nodos; i++) {
        if (grafo->nodos[i].n_con != 0) free(grafo->nodos[i].con);
    }
    free(grafo->nodos);
    free(grafo);
}

void conectar(Grafo *grafo, short a, short b) {
    grafo->nodos[a].n_con++;
    grafo->nodos[a].con = (short *) realloc(grafo->nodos[a].con, grafo->nodos[a].n_con*sizeof(short));
    grafo->nodos[a].con[grafo->nodos[a].n_con-1] = b;

    grafo->nodos[b].n_con++;
    grafo->nodos[b].con = (short *) realloc(grafo->nodos[b].con, grafo->nodos[b].n_con*sizeof(short));
    grafo->nodos[b].con[grafo->nodos[b].n_con-1] = a;
}

void desconectar(Grafo *grafo, short a, short b) {
    grafo->nodos[a].con[grafo->nodos[a].n_con-1] = -1;
    grafo->nodos[b].con[grafo->nodos[a].n_con-1] = -1;

}

short bbin(short *datos, short ip, short iu, short id) {
    short pos = (iu-ip)/2 + ip;
    if (id == datos[pos]) return pos;
    if (ip == iu) return -1;
    if (id > datos[pos]) return bbin(datos, pos, iu, id);
    else return bbin(datos, ip, pos, id);
}

short dji(Grafo grafo, short a, short b) {
    short lon = 0;
    short i;
    queue <short> cola;
    cola.push(a);
    short id_aux;

    while(!cola.empty()) {
        id_aux = cola.front();
        cola.pop();
        for (i = 0; i < grafo.nodos[id_aux].n_con; i++) {
            if (grafo.nodos[id_aux].con[i] == b) return lon+1;
        }
    }
}

int main() {
    short num_nodos, num_lineas;
    short a, b, i;
    Grafo *grafo;
    short num_importantes;
    short *importantes = (short *) malloc(201*sizeof(short));
    short **conexiones;
    

    while(true) {
        scanf("%hd %hd", &num_nodos, &num_lineas);
        if (num_nodos == 0 && num_lineas == 0) return 0;

        grafo = crear_grafo(num_nodos);
        num_importantes = 0;


        for (i = 0; i < num_lineas; i++) {
            scanf("%hd", &a);
            b = a;
            while (true) {
                scanf("%hd", &b);
                if (b == 0) break;
                conectar(grafo, a-1, b-1);
                a = b;
            }
        }


        for (i = 0; i < num_nodos; i++) {
            if (grafo->nodos[i].n_con >= 2) {
                grafo->nodos[i].importante = 1;
                importantes[num_importantes] = i;
                num_importantes++;
            } else {
                grafo->nodos[i].importante = 0;
            }
        }

        conexiones = (short **) malloc(num_importantes*sizeof(short *));

        for (i = 0; i < num_importantes; i++) {
            conexiones[i] = (short *) calloc(num_importantes, sizeof(short))
        }

    }
    
}