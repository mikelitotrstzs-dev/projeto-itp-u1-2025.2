#include <stdio.h>
#include <math.h>   // necessário para pow()

int main() {
    float capital, taxa, montante;
    int tempo;

    printf("Digite o capital inicial: ");
    scanf("%f", &capital);

    printf("Digite a taxa de juros (%%): ");
    scanf("%f", &taxa);

    printf("Digite o tempo (anos): ");
    scanf("%d", &tempo);

    montante = capital * pow((1 + taxa / 100), tempo);

    printf("Montante final: %.2f\n", montante);
    return 0;
}
