#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <stack>

typedef struct List_node {
    int id;
    List_node *next;
};

typedef struct List {
    List_node *first;
};

typedef struct Node {
    int id;
    int row, col;
    int *adj;
    int num_adj;
};

typedef struct Graph {
    Node **nodes;
    int num_nodes;
};

List *create_list() {
    List *list = (List *) malloc(sizeof(List));
    list->first = NULL;
    return list;
}

void insert_list(List *list, int id) {
    List_node *list_node = (List_node *) malloc(sizeof(List_node));
    list_node->id = id;
    list_node->next = list->first;
    list->first = list_node;
}

void remove_list(List *list, int id) {
    List_node *node_aux = list->first;
    List_node *temp;
    if (list->first != NULL && list->first->id == id) {
        temp = list->first;
        list->first = list->first->next;
        free(temp);
        return;
    }
    while (node_aux != NULL) {
        if (node_aux->next != NULL && node_aux->next->id == id) {
            temp = node_aux->next;
            node_aux->next = node_aux->next->next;
            free(temp);
            break;
        }
        node_aux = node_aux->next;
    }
}

int is_empty(List *list) {
    if (list->first == NULL) return 1;
    return 0;
}

void free_list(List *list) {
    while(!is_empty(list)) {
        remove_list(list, list->first->id);
    }
}

int is_in_list(List_node *list_node, int id) {
    if (list_node->id == id) return 1;
    if (list_node->next == NULL) return 0;
    else return is_in_list(list_node->next, id);
}

void free_graph(Graph *graph) {
    int i;
    if (graph == NULL) return;
    for (i = 0; i < graph->num_nodes; i++) free(graph->nodes[i]);
    free(graph);
}

void add_node(Graph *graph, Node *node) {
    graph->num_nodes++;
    graph->nodes = (Node **) realloc(graph->nodes, graph->num_nodes*sizeof(Node));
    graph->nodes[graph->num_nodes-1] = node;
}

void add_connection(Node *node1, Node *node2) {
    node1->num_adj++;
    node2->num_adj++;
    node1->adj = (int *) realloc(node1->adj, node1->num_adj*sizeof(int));
    node2->adj = (int *) realloc(node2->adj, node2->num_adj*sizeof(int));
    node1->adj[node1->num_adj-1] = node2->id;
    node2->adj[node2->num_adj-1] = node1->id;
}

void print_node(Node *node) {
    int i;
    printf("\t\tid: %d\n", node->id);
    printf("\t\trow: %d\n", node->row);
    printf("\t\tcol: %d\n", node->col);
    printf("\t\tnum_adj: %d\n", node->num_adj);
    printf("\t\tConnections with: ");
    for (i = 0; i < node->num_adj-1; i++) {
        printf("%d, ", node->adj[i]);
    }
    if (i != 0) printf("%d\n", node->adj[i]);
}

void print_graph(Graph *graph) {
    int i;
    printf("Number of nodes: %d\n", graph->num_nodes);
    for (i = 0; i < graph->num_nodes; i++) {
        printf("\tNode %d: \n", i);
        print_node(graph->nodes[i]);
    }
}

void print_list(List *list) {
    List_node *list_node = list->first;
    while(list_node != NULL) {
        printf("%d ", list_node->id);
        list_node = list_node->next;
    }
    printf("\n");
}

int number_of_nodes(Graph *graph, List *list) {
    int i;
    int size = 1;
    int id = list->first->id;
    std::stack <int> s;
    s.push(id);
    remove_list(list, id);
    List *list_of_adjs = create_list();
    insert_list(list_of_adjs, id);
    while(s.size() != 0) {
        id = s.top();
        s.pop();
        for (i = 0; i < graph->nodes[id]->num_adj; i++) {
            if (!is_in_list(list_of_adjs->first, graph->nodes[id]->adj[i])) {
                insert_list(list_of_adjs, graph->nodes[graph->nodes[id]->adj[i]]->id);
                remove_list(list, graph->nodes[id]->adj[i]);
                s.push(graph->nodes[id]->adj[i]);
                size++;
            }
        }
    }
    free_list(list_of_adjs);
    return size;
}


int main() {
    int num_col, num_rows;
    int i, j;
    int id;
    Graph *graph;
    char aux;
    Node *node_aux;
    List *list = NULL;
    int max, aux_num;

    while (true) {
        scanf("%d %d", &num_rows, &num_col);
        scanf("%c", &aux);
        if (feof(stdin)) return 0;
        graph = (Graph *) malloc(sizeof(Graph));
        graph->num_nodes = 0;
        graph->nodes = NULL;
        
        // Read the grid and initialize the nodes (without their connections)
        for (i = 0; i < num_rows; i++) {
            for (j = 0; j < num_col; j++) {
                scanf("%c", &aux);
                if (aux == '#') {
                    node_aux = (Node *) malloc(sizeof(Node));
                    node_aux->row = i;
                    node_aux->id = graph->num_nodes;
                    node_aux->col = j;
                    node_aux->adj = NULL;
                    node_aux->num_adj = 0;
                    add_node(graph, node_aux);
                }
            }
            scanf("%c", &aux);
        }

        // Create the connections bewtween the nodes inside the graph
        for (i = 0; i < graph->num_nodes; i++) {
            if (graph->nodes[i]->col != num_col-1 && i != graph->num_nodes-1) {
                if (graph->nodes[i+1]->row == graph->nodes[i]->row && graph->nodes[i+1]->col-1 == graph->nodes[i]->col) {
                    //They're adjacent horizontally
                    add_connection(graph->nodes[i], graph->nodes[i+1]);
                }
            }
            if (graph->nodes[i]->row != num_rows-1 && i != graph->num_nodes-1) {
                j = i+1;
                while (true) {
                    if (j >= graph->num_nodes || graph->nodes[j]->row > graph->nodes[i]->row+1) {
                        break;
                    }
                    if (graph->nodes[j]->row-1 == graph->nodes[i]->row && graph->nodes[j]->col == graph->nodes[i]->col) {
                        //They're adjacent vertically
                        add_connection(graph->nodes[i], graph->nodes[j]);
                        break;
                    }
                    j++;
                }
            }
        }

        list = create_list();
        for (i = graph->num_nodes-1; i >= 0; i--) {
            insert_list(list, i);
        }
        max = 0;
        while (!is_empty(list)) {
            //print_graph(graph);
            aux_num = number_of_nodes(graph, list);
            if (aux_num > max) max = aux_num;
        }
        printf("%d\n", max);
        free_list(list);
        free_graph(graph);
    }
}