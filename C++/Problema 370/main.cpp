#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, num_llaves, tam1, tam2;
    scanf("%d", &num_llaves);
    for (i = 0; i < num_llaves; i++) {
        scanf("%d-%d", &tam1, &tam2);
        if (tam1 <= tam2) {
            if (tam2-tam1 != 1) {
                printf("NO\n");
                continue;
            }
            if (tam1%2 == 0) printf("SI\n");
            else printf("NO\n");
        } else {
            if (tam1-tam2 != 1) {
                printf("NO\n");
                continue;
            }
            if (tam2%2 == 0) printf("SI\n");
            else printf("NO\n");
        }
    }
}
