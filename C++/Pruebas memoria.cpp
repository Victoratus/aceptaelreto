#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_ELEMENTOS 100000
#define REPETICIONES 10000


int main () {
    int *a, i, j;
    clock_t start, end;
    clock_t start2, end2;
    double cpu_time;
    int b[NUM_ELEMENTOS];

    //Prueba calloc
    start = clock();

    for (i = 0; i < REPETICIONES; i++) {
        a = (int *) calloc(NUM_ELEMENTOS, sizeof(int));
        free(a);
    }

    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Calloc ha tardado %fs.\n", cpu_time);

    //Prueba calloc
    start2 = clock();

    for (i = 0; i < REPETICIONES; i++) {
        for (j = 0; j < NUM_ELEMENTOS; j++) b[j] = 0;
    }

    end2 = clock();
    cpu_time = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("For ha tardado %fs.\n", cpu_time);

    return 0;
}