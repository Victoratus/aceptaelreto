#include <stdlib.h>
#include <stdio.h>


int main () {
    int dia_esp, mes_esp, anio_esp, n_casos, i;
    int dia_ing, mes_ing, anio_ing;
    int llevada;
    scanf("%d", &n_casos);
    for (i = 0; i < n_casos; i++) {
        scanf("%d %d %d", &dia_esp, &mes_esp, &anio_esp);
        if (anio_esp < 1582 || (anio_esp == 1582 && mes_esp < 10) || (anio_esp == 1582 && mes_esp == 10 && dia_esp <= 4)) {
            //No hay diferencias de calendario
            anio_ing = anio_esp;
            mes_ing = mes_esp;
            dia_ing = dia_esp;
        } else if (anio_esp < 1700 || (anio_esp == 1700 && mes_esp < 2) || (anio_esp == 1700 && mes_esp == 2 && dia_esp <= 28)) {
            //Diferencia de 10 días
            if (dia_esp-10 > 0) {
                dia_ing = dia_esp-10;
                mes_ing = mes_esp;
                anio_ing = anio_esp;
            } else {
                if (mes_esp == 1) {
                    if (anio_esp%4 == 0) {
                        dia_ing = 31+dia_esp-10;
                    } else {

                    }
                } else if (mes_esp == 2) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 3) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 4) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 5) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 6) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 7) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 8) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 9) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 10) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 11) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                } else if (mes_esp == 12) {
                    if (anio_esp%4 == 0) {

                    } else {
                        
                    }
                }
            }
        } else if (anio_esp < 1752 || (anio_esp == 1752 && mes_esp < 9) || (anio_esp == 1752 && mes_esp == 9 && dia_esp <= 13)) {
            //Diferencia de 11 días
        } else {
            //No hay diferencias de calendario
            anio_ing = anio_esp;
            mes_ing = mes_esp;
            dia_ing = dia_esp;
        }
        printf("%d %d %d\n", dia_ing, mes_ing, anio_ing);
    }
}