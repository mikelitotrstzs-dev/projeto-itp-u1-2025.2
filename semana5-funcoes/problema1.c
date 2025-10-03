#include <stdio.h>

void imprimeHorario(int h, int m, int formato) {

    h += m / 60;
    m = m % 60;

    h = h % 24;

    if (formato == 0) {
 
        printf("%02d:%02d\n", h, m);
    } else {
    
        int hora12 = h % 12;
        if (hora12 == 0) hora12 = 12;
        printf("%02d:%02d %s\n", hora12, m, (h < 12 ? "AM" : "PM"));
    }
}

int main() {
    int h, m, formato;
    scanf("%d %d %d", &h, &m, &formato);

    imprimeHorario(h, m, formato);
    imprimeHorario(h + 1, m, formato);
    imprimeHorario(h + 2, m + 10, formato);
    imprimeHorario(h + 4, m + 40, formato);
    imprimeHorario(h + 12, m + 5, formato);

    return 0;
}
