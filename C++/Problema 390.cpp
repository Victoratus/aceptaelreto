#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    int n_casos, i, n_mag, n_amar, n_cian, lon, j;
    char colores[100001];
    scanf("%d", &n_casos);
    for (i = 0; i < n_casos; i++) {
        scanf("%d %d %d", &n_mag, &n_amar, &n_cian);
        scanf("%s", colores);
        lon = strlen(colores);
        for (j = 0; j < lon; j++) {
            if (n_mag < 0 || n_amar < 0 || n_cian < 0) break;
            if (colores[j] == 'B') continue;
            else if (colores[j] == 'M') {
                n_mag--;
            } else if (colores[j] == 'A') {
                n_amar--;
            } else if (colores[j] == 'C') {
                n_cian--;
            } else if (colores[j] == 'R') {
                n_mag--;
                n_amar--;
            } else if (colores[j] == 'V') {
                n_cian--;
                n_amar--;
            } else if (colores[j] == 'L') {
                n_cian--;
                n_mag--;
            } else if (colores[j] == 'N') {
                n_mag--;
                n_cian--;
                n_amar--;
            }
        }
        if (n_mag < 0 || n_amar < 0 || n_cian < 0) {
            printf("NO\n");
        } else {
            printf("SI %d %d %d\n", n_mag, n_amar, n_cian);
        }
    }
    return 0;
}