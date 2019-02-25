#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    while (true) {
        scanf("%d %d", &a, &b);
        if (a < 0 || b < 0) return 0;
        printf("%d\n", 2*a+2*b);
    }
}