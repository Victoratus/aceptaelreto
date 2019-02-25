#include <stdio.h>
#include <stdlib.h>

int main() {
    short a, b;
    int i, num_reps;

    scanf("%d", &num_reps);
    for (i = 0; i < num_reps; i++) {
        scanf("%hd %hd", &a, &b);
        if (a+b >= 0) printf("SI\n");
        else printf("NO\n");
    }
}