#include <stdio.h>
#include <math.h>

float altura(float x, float y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

int pontoSeguro(float x, float y) {
    float pontos[5][2] = {
        {x, y},
        {x + 0.2f, y + 0.2f},
        {x - 0.2f, y - 0.2f},
        {x + 0.2f, y - 0.2f},
        {x - 0.2f, y + 0.2f}
    };

    for (int i = 0; i < 5; i++) {
        float h = altura(pontos[i][0], pontos[i][1]);
        if (h < 0 || h > 2) return 0;
    }
    return 1;
}

int main() {
    float x, y;
    scanf("%f %f", &x, &y);

    if (!pontoSeguro(x, y)) {
        printf("troque de coordenada\n");
        return 0;
    }

    int seguros = 0;
    if (pontoSeguro(x + 2, y)) seguros++;
    if (pontoSeguro(x - 2, y)) seguros++;
    if (pontoSeguro(x, y + 2)) seguros++;
    if (pontoSeguro(x, y - 2)) seguros++;

    if (seguros <= 1) {
        printf("inseguro\n");
    } else if (seguros <= 3) {
        printf("relativamente seguro\n");
    } else {
        printf("seguro\n");
    }

    return 0;
}
