#include <stdio.h>

// ---------- Funções de conversão ----------
float metrosParaCentimetros(float m) {
    return m * 100;
}

float centimetrosParaMetros(float cm) {
    return cm / 100;
}

float celsiusParaFahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32;
}

float fahrenheitParaCelsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}

// ---------- Programa Principal ----------
int main() {
    int opcao;
    float valor, resultado;
    float historico[100];  // vetor para armazenar resultados
    int contador = 0;      // quantos resultados já foram salvos

    do {
        printf("\n=== Conversor de Unidades ===\n");
        printf("1 - Metros -> Centimetros\n");
        printf("2 - Centimetros -> Metros\n");
        printf("3 - Celsius -> Fahrenheit\n");
        printf("4 - Fahrenheit -> Celsius\n");
        printf("5 - Ver historico\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor em metros: ");
                scanf("%f", &valor);
                resultado = metrosParaCentimetros(valor);
                printf("%.2f m = %.2f cm\n", valor, resultado);
                historico[contador++] = resultado;
                break;

            case 2:
                printf("Digite o valor em centimetros: ");
                scanf("%f", &valor);
                resultado = centimetrosParaMetros(valor);
                printf("%.2f cm = %.2f m\n", valor, resultado);
                historico[contador++] = resultado;
                break;

            case 3:
                printf("Digite a temperatura em Celsius: ");
                scanf("%f", &valor);
                resultado = celsiusParaFahrenheit(valor);
                printf("%.2f °C = %.2f °F\n", valor, resultado);
                historico[contador++] = resultado;
                break;

            case 4:
                printf("Digite a temperatura em Fahrenheit: ");
                scanf("%f", &valor);
                resultado = fahrenheitParaCelsius(valor);
                printf("%.2f °F = %.2f °C\n", valor, resultado);
                historico[contador++] = resultado;
                break;

            case 5:
                printf("\n--- Historico de Conversoes ---\n");
                for(int i = 0; i < contador; i++) {
                    printf("%d: %.2f\n", i+1, historico[i]);
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
