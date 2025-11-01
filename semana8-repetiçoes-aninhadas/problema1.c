#include <stdio.h>

int main() {
    int m, n;
    int sorteados[50];
    int aposta[50];
    int acertos = 0;
    int i, j;

    // Lê a quantidade de números sorteados (m) e apostados (n)
    scanf("%d %d", &m, &n);

    // Lê os m números sorteados e armazena no vetor 'sorteados'
    // [Conceito: Laço 'for' para leitura de vetor, cite: 1723, 592]
    for (i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    // Lê os n números da aposta e armazena no vetor 'aposta'
    for (i = 0; i < n; i++) {
        scanf("%d", &aposta[i]);
    }

    // Compara os vetores usando laços aninhados
    // [Conceito: Estruturas de repetição aninhadas, cite: 1, 3]
    for (i = 0; i < n; i++) { // Para cada número na aposta...
        for (j = 0; j < m; j++) { // ...compare com cada número sorteado
            
            // [Conceito: Condicional 'if' e operador '==', cite: 127, 2223]
            if (aposta[i] == sorteados[j]) {
                acertos++; // Incrementa o contador de acertos
                // O problema diz que não há números repetidos no sorteio/aposta[cite: 395],
                // então podemos parar de procurar este número (otimização).
                break; 
            }
        }
    }

    // Imprime o resultado final
    printf("%d\n", acertos);

    return 0;
}