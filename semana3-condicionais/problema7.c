#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, r1, r2;

    printf("Digite os coeficientes a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    if(a == 0) {
        printf("Nao e uma equacao do segundo grau.\n");
    } else {
        delta = b*b - 4*a*c;
        if(delta > 0) {
            r1 = (-b + sqrt(delta)) / (2*a);
            r2 = (-b - sqrt(delta)) / (2*a);
            printf("Duas raizes reais: %.2f e %.2f\n", r1, r2);
        } else if(delta == 0) {
            r1 = -b / (2*a);
            printf("Uma raiz real: %.2f\n", r1);
        } else {
            printf("Nao possui raizes reais.\n");
        }
    }
    return 0;
}
