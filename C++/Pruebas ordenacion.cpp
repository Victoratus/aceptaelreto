#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
 

#define NUM_ELEMENTOS 500000
#define ERR -1

typedef struct {
  int top;
  int *ip;
  int *iu;
} Stack;


using namespace std;

void swap(int *a, int *b);

int partir(int *tabla, int ip, int iu, int *pos);

int medio(int *tabla, int ip, int iu, int *pos);

int quicksort(int *tabla, int ip, int iu);

int quicksort_src(int *tabla, int ip, int iu);

int main () {
    int i, j;
    clock_t start, end;
    clock_t start2, end2;
    double cpu_time;
    int b[NUM_ELEMENTOS];

    srand(time(NULL));

    for (j = 0; j < NUM_ELEMENTOS; j++) b[j] = rand()%NUM_ELEMENTOS;

    //Prueba sort
    start = clock();

    sort(b, b+NUM_ELEMENTOS);

    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sort ha tardado %0.4fs.\n", cpu_time);

    for (j = 0; j < NUM_ELEMENTOS; j++) b[j] = rand()%NUM_ELEMENTOS;

    //Prueba quicksort
    start2 = clock();

    quicksort_src(b, 0, NUM_ELEMENTOS-1);

    end2 = clock();
    cpu_time = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("Quicksort ha tardado %.04fs.\n", cpu_time);

    return 0;
}

void swap(int *a, int *b){
  int c;

  if (a == NULL || b == NULL) return;

  c = *a;
  *a = *b;
  *b = c;

  return;
}

int partir(int *tabla, int ip, int iu, int *pos) {
  int i, m, OB;

  if (tabla == NULL || ip < 0 || ip >= iu || *pos < ip || *pos > iu) return ERR;

  swap(&tabla[*pos], &tabla[ip]);

  OB = 0;
  m = ip;
  for(i = ip+1; i <= iu; i++) {
    OB++;
    if (tabla[i] < tabla[ip]) {
      m++;
      swap(&tabla[i], &tabla[m]);
    }
  }

  swap(&tabla[ip], &tabla[m]);

  *pos = m;

  return OB;
}

int medio(int *tabla, int ip, int iu, int *pos) {

  if (tabla == NULL || ip < 0 || ip >= iu) return ERR;
  *pos = ip;
  return 0;
}

int quicksort(int *tabla, int ip, int iu) {
  int pos_pivote, OB;

  if (tabla == NULL || ip < 0 || ip > iu) return ERR;

  if(ip == iu) return 0;

  OB = 0;

  OB += medio(tabla, ip, iu, &pos_pivote);
  OB += partir(tabla, ip, iu, &pos_pivote);

  OB += quicksort(tabla, ip, pos_pivote-1);
  OB += quicksort(tabla, pos_pivote+1, iu);

  return OB;
}

int quicksort_src(int *tabla, int ip, int iu) {
  int pos_pivote, pos_ip, pos_iu, OB;
  Stack stack;

  if (tabla == NULL || ip < 0 || ip > iu) return ERR;

  OB = 0;

  if (ip == iu) return OB;

  stack.top = 0;

  stack.ip = NULL;
  stack.ip = (int *) malloc((iu-ip+1000)*sizeof(int));
  if (stack.ip == NULL) return ERR;

  stack.iu = NULL;
  stack.iu = (int *) malloc((iu-ip+1000)*sizeof(int));
  if (stack.iu == NULL) {
    free(stack.ip);
    return ERR;
  }

  stack.ip[stack.top] = ip;
  stack.iu[stack.top] = iu;
  stack.top++;

  while (stack.top > 0) {
    stack.top--;
    pos_ip = stack.ip[stack.top];
    pos_iu = stack.iu[stack.top];

    OB += medio(tabla, pos_ip, pos_iu, &pos_pivote);
    OB += partir(tabla, pos_ip, pos_iu, &pos_pivote);

    if (pos_ip < pos_pivote-1) {
      stack.ip[stack.top] = pos_ip;
      stack.iu[stack.top] = pos_pivote-1;
      stack.top++;
    }

    if (pos_pivote+1 < pos_iu) {
      stack.ip[stack.top] = pos_pivote+1;
      stack.iu[stack.top] = pos_iu;
      stack.top++;
    }
  }

  free(stack.ip);
  free(stack.iu);

  return OB;
}
