#include <stdio.h>

int main() {
    float valorCompra, desconto = 0.0, valorFinal;
    float taxa = 0.0;

    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);

    if(valorCompra > 1000.0) {
        taxa = 0.20;
    } else if(valorCompra > 500.0) {
        taxa = 0.15;
    } else if(valorCompra > 100.0) {
        taxa = 0.10;
    }

    desconto = valorCompra * taxa;
    valorFinal = valorCompra - desconto;

    printf("Desconto aplicado: %.2f%%\n", taxa * 100);
    printf("Valor do desconto: R$ %.2f\n", desconto);
    printf("Valor final a pagar: R$ %.2f\n", valorFinal);

    return 0;
}
