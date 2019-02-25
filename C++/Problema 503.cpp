#include <stdio.h>

int main() {
    int i, j, num;
    int a, b;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d %d", &a, &b);
        if (a == b) printf("%d\n", a+1);
        else {
            if (a < b) {
                for (j = a; j < b; j++) {
                    printf("%d ", j+1);
                }
                printf("%d\n", j+1);
            } else {
                for (j = b; j < a; j++) {
                    printf("%d ", j+1);
                }
                printf("%d\n", j+1);
            }
        }
    }
    return 0;
}