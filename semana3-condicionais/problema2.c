#include <stdio.h>

int main() {
    float consumo, valor = 15.0;
    char tipo;

    printf("Digite o consumo em kWh: ");
    scanf("%f", &consumo);

    printf("Digite o tipo de consumidor (R/C/I): ");
    scanf(" %c", &tipo); 
    if(tipo == 'R' || tipo == 'r') {
        valor += 0.60 * consumo;
    } else if(tipo == 'C' || tipo == 'c') {
        valor += 0.48 * consumo;
    } else if(tipo == 'I' || tipo == 'i') {
        valor += 1.29 * consumo;
    } else {
        printf("Tipo invalido!\n");
        return 0;
    }

    printf("Valor total da conta: R$ %.2f\n", valor);
    return 0;
}
