#include <stdio.h>
#include <algorithm>

int main() {
    long long int m, d, total, mcm;
    while (true) {
        scanf("%lld %lld %lld", &m, &d, &total);
        if (m == 0 && d == 0 && total == 0) return 0;
        mcm = m*d/std::__gcd(m, d);
        printf("%d\n", (int) total/mcm);
    }
}