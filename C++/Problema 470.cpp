#include <stdio.h>
#include <string.h>

typedef struct {
    char color;
    Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *primero;
    int tam;
} Lista;

Lista *crear_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->tam = 0;
    lista->primero = NULL;
}

void borrar_rec(Nodo *nodo, char elem) {
    Nodo *aux;
    if (nodo->siguiente != NULL && nodo->siguiente->color == elem) {
        aux = nodo->siguiente;
        nodo->siguiente = nodo->siguiente->siguiente;
        freopen(aux);
    } else if {
        
    }
}

void borrar_elemento(Lista *lista, char elem) {

}

int main() {

    int num_semaforos;
    int pos;

    while(true) {
        scanf("%s", bombillas);
        if(feof(stdin)) return 0;
        tam = strlen(bombillas);
        num_semaforos = 0;
        pos = 0;
        while(true) {
            if (pos == tam) break;
            if (bombillas[pos] == 'R') {
                while(true) {
                    pos++;
                    if (pos == tam) break;
                    if (bombillas[pos] == 'A') {
                        while (true) {
                            pos++;
                            if (pos == tam) break;
                            if (bombillas[pos] == 'V') {
                                pos++;
                                num_semaforos++;
                                break;
                            }
                        }
                    }
                }
            }
            pos++;
        }

        printf("%d\n", num_semaforos);
    }
}