#include <stdio.h>


int main() {
    int i, num_reps;
    int a, b;

    scanf("%d", &num_reps);
    for (i = 0; i < num_reps; i++) {
        scanf("%d / %d", &a, &b);
        if (a >= b) printf("BIEN\n");
        else printf("MAL\n");
    }

    return 0;
}