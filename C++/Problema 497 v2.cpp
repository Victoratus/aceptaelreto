#include <stdlib.h>
#include <stdio.h>
#include <stack>

typedef struct Nodo {
    int id;
    int num_con;
    int *con;
};

typedef struct Grafo {
    int num_nodos;
    Nodo *nodos;
};

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

Nodo *crear_nodo(int id) {
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->id = id;
    nodo->num_con = 0;
    nodo->con = NULL;
    return nodo;
}

Grafo *crear_grafo(int num_nodos) {
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->num_nodos = num_nodos;
    grafo->nodos = (Nodo *) malloc(num_nodos*sizeof(Nodo));
    for (int i = 0; i < num_nodos; i++) {
        grafo->nodos[i] = *crear_nodo(i);
    }
    return grafo;
}

void destruir_grafo(Grafo *grafo) {
    for (int i = 0; i < grafo->num_nodos; i++) {
        if (grafo->nodos[i].num_con != 0) free(grafo->nodos[i].con);
    }
    free(grafo->nodos);
    free(grafo);
}

void conectar(Grafo *grafo, int a, int b) {
    grafo->nodos[a].con = (int *) realloc(grafo->nodos[a].con, (grafo->nodos[a].num_con+1)*sizeof(int));
    grafo->nodos[a].con[grafo->nodos[a].num_con] = b;
    grafo->nodos[a].num_con++;
    
    grafo->nodos[b].con = (int *) realloc(grafo->nodos[b].con, (grafo->nodos[b].num_con+1)*sizeof(int));
    grafo->nodos[b].con[grafo->nodos[b].num_con] = a;
    grafo->nodos[b].num_con++;
}

void desconectar(Grafo *grafo, int a, int b) {
    int id_aux;
    
    if (grafo->nodos[a].con[0] == b) {
        if (grafo->nodos[a].num_con == 2) id_aux = grafo->nodos[a].con[1];
        else id_aux = -1;
    }
    free(grafo->nodos[a].con);
    if (id_aux != -1) {
        grafo->nodos[a].con = (int *) malloc(sizeof(int));
        grafo->nodos[a].con[0] = id_aux;
    }

    if (grafo->nodos[b].con[0] == a) {
        if (grafo->nodos[b].num_con == 2) id_aux = grafo->nodos[b].con[1];
        else id_aux = -1;
    }
    free(grafo->nodos[b].con);
    if (id_aux != -1) {
        grafo->nodos[b].con = (int *) malloc(sizeof(int));
        grafo->nodos[b].con[0] = id_aux;
    }
}

int simplificar(Grafo *grafo, int **costes, char *importantes) {
    int id_raiz, i, id_aux, peso;
    Nodo *a, *b;
    a = crear_nodo(-1);
    b = crear_nodo(-1);    

    for (i = 0; i < grafo->num_nodos; i++) { //Busco un nodo que no sea importante y que no haya usado ya
        if (importantes[i] == 0) {
            id_raiz = i;
            break;
        }
    }
    if (i == grafo->num_nodos) return 0;

    //Ya tengo una id sobre la que partir
    std::stack<int> pila;
    pila.push(id_raiz);
    peso = 0;
    
    while (!pila.empty()) { //Voy almacenando en la pila las ids de los nodos a ir eliminando
        id_aux = pila.top();
        pila.pop();
        importantes[id_aux] = 'X';
        peso++;
        for (i = 0; i < grafo->nodos[id_aux].num_con; i++) { //Para cada nodo que tiene conexion con el que estoy mirando (1 o 2)
            if (importantes[grafo->nodos[id_aux].con[i]] == 1) { //Si es importante lo registro
                if (a->id == -1) {
                    a->id = grafo->nodos[id_aux].con[i];
                } else {
                    b->id = grafo->nodos[id_aux].con[i];
                    break;
                }
            } else { //Si no meto su id en la pila y lo desconecto del que estaba mirando para no volver para atrás
                pila.push(grafo->nodos[id_aux].con[i]);
                desconectar(grafo, id_aux, grafo->nodos[id_aux].con[i]);
            }
        }
        if (a->id != -1 && b->id != -1) { //Cuando he encontrado dos importantes salgo
            break;
        }
    }

    if (a->id != -1 && b->id != -1) { //Si he encontrado dos importantes actualizo el coste de su unión en la tabla de costes
        if (a->id > b->id) { 
            costes[a->id][b->id] = min(peso, costes[a->id][b->id]);
        }
    }
    return 1;
}

void warshall(int **costes, int num_importantes) {
    int i, j, k, distancia;

    for (i = 0; i < num_importantes; i++) {
        for (j = 0; j < num_importantes; j++) {
            for (k = 0; k <= j; k++) {
                distancia = costes[i][k]+costes[k][j];
                if (costes[i][j] > distancia || (costes[i][j] == 0 && i != j)) {     //Inicializo los arrays a 0, de 
                    costes[i][j] = distancia;                                        // manera que tengo que comprobar
                }                                                                   // si es 0 la posición a sobreescribir
            }
        }
    }
}


//Esta función te devuelve la posicion del nodo importante con menos coste acumulado asociado
int menor_coste(int **costes, int num_importantes) {
    int pos_menor_coste = -1;
    int i, j, coste_acumulado, coste_acumulado_anterior = 9999999; //El 9999999 es indiferente
    for (i = 0; i < num_importantes; i++) {
        coste_acumulado = 0;
        for (j = 0; j <= i; j++) {
            coste_acumulado += costes[i][j];
        }
        for (; j < num_importantes; j++) {
            coste_acumulado += costes[j][i];
        }
        if (coste_acumulado < coste_acumulado_anterior || pos_menor_coste == -1) {
            pos_menor_coste = i;
        }
        coste_acumulado_anterior = coste_acumulado;
    }
    return pos_menor_coste;
}

int main() {
    int num_nodos, num_importantes, num_lineas, i, j, id1, id2;
    char *importantes;
    int **costes;
    int ids_importantes[200];   //Uso este array para almacenar la información de las ids de las estaciones importantes,
                            // para así no tener que buscar luego en el array "importantes" después de aplicar warshall
                            // para hallar la solución.

    Grafo *grafo;

    while (true) {
        scanf("%d %d", &num_nodos, &num_lineas);
        if (num_nodos == 0 && num_lineas == 0) return 0;

        grafo = crear_grafo(num_nodos);
        importantes = (char *) calloc(num_nodos, sizeof(char));
        num_importantes = 0;

        for (i = 0; i < num_lineas; i++) {
            scanf("%d", &id1);
            if (importantes[id1-1] < 5+i && importantes[id1-1] != 0) importantes[id1-1] = 1; //La estacion es importante
            if (importantes[id1-1] == 0) importantes[id1-1] = 5+i; //La estacion solo aparece en una linea de momento
            while(true) {   //Creo las conexiones
                scanf("%d", &id2);
                if (id2 == 0) break;
                if (importantes[id2-1] < 5+i && importantes[id2-1] != 0) importantes[id2-1] = 1; //La estacion es importante
                if (importantes[id2-1] == 0) importantes[id2-1] = 5+i; //La estacion solo aparece en una linea de momento
                conectar(grafo, id1-1, id2-1);
                id1 = id2;
            }
        }

        for (i = 0; i < num_nodos; i++) {   //Almaceno las que son importantes
            if (importantes[i] == 1) {
                importantes[i] = 1;
                ids_importantes[num_importantes] = i;
                num_importantes++;
            }
        }

        /*printf("Importantes: ");
        for (i = 0; i < num_importantes; i++) printf("%d ", ids_importantes[i]+1);
        printf("\n");*/

        costes = (int **) malloc(num_importantes*sizeof(int *));
        for (i = 0; i < num_importantes; i++) {
            costes[i] = (int *) calloc(i+1, sizeof(int));
        }

        while (simplificar(grafo, costes, importantes));

        for (i = 0; i < num_importantes; i++) {
            for (j = 0; j <= i; j++) {
                printf("%d ", costes[i][j]+1);
            }
            printf("\n");
        }

        warshall(costes, num_importantes);

        printf("%d\n", ids_importantes[menor_coste(costes, num_importantes)]+1);

        destruir_grafo(grafo);
        free(importantes);
        for (i = 0; i < num_importantes; i++) free(costes[i]);
        free(costes);
    }
}