#include <stdio.h>

int mod(int a) {
    int k = 31543;
    int res = 0;
    while (1) {
        if (a < k) break;
        a -= k;
    }
    return a;
}

int main () {
    int a, b, res;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) return 0;
        res = 1;
        a = mod(a);
        while (b > 0) {
            res = mod(res*a);
            b--;
        }
        printf("%d\n", res);
    }
}