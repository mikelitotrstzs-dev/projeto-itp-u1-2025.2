#include <stdio.h>
#include <math.h>

int pontos(float d) {
    if (d <= 1.0) return 10;
    else if (d <= 2.0) return 6;
    else if (d <= 3.0) return 4;
    else return 0;
}

int main() {
    float x, y;
    int total = 0;
    int anterior = -1;

    for (int i = 0; i < 10; i++) {
        scanf("%f %f", &x, &y);

        float d = sqrt(x*x + y*y);

        int atual;
        if (d <= 1.0) atual = 1;
        else if (d <= 2.0) atual = 2;
        else if (d <= 3.0) atual = 3;
        else atual = 4;

        int p = pontos(d);
        total += p;

        if (i > 0 && atual == anterior) {
            total += p / 2;
        }

        anterior = atual;
    }

    printf("%d\n", total);
    return 0;
}