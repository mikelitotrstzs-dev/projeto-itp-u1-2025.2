#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, maior, somaDosOutros;

    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);

    if(a + b > c && a + c > b && b + c > a) {
        // Classificação pelos lados
        if(a == b && b == c) {
            printf("Triangulo Equilatero\n");
        } else if(a == b || a == c || b == c) {
            printf("Triangulo Isosceles\n");
        } else {
            printf("Triangulo Escaleno\n");
        }

        // Ângulos
        if(a >= b && a >= c) {
            maior = a; somaDosOutros = b*b + c*c;
        } else if(b >= a && b >= c) {
            maior = b; somaDosOutros = a*a + c*c;
        } else {
            maior = c; somaDosOutros = a*a + b*b;
        }

        if(fabs(maior*maior - somaDosOutros) < 0.0001) {
            printf("Triangulo Retangulo\n");
        } else if(maior*maior < somaDosOutros) {
            printf("Triangulo Acutangulo\n");
        } else {
            printf("Triangulo Obtusangulo\n");
        }
    } else {
        printf("Nao formam um triangulo.\n");
    }

    return 0;
}
