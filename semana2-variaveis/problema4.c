#include <stdio.h>

int main() {
    int num1, num2;
    float media;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

    printf("Soma: %d\n", num1 + num2);
    printf("Diferenca: %d\n", num1 - num2);
    printf("Produto: %d\n", num1 * num2);
    printf("Divisao real: %.2f\n", (float)num1 / num2); 
    printf("Resto da divisao inteira: %d\n", num1 % num2);

    media = (num1 + num2) / 2.0;
    printf("Media aritmetica: %.2f\n", media);

    return 0;
}
