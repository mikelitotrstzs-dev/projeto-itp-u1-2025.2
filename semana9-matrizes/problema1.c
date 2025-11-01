#include <stdio.h> // Para printf e scanf

int main() {
    int M, N;
    // Declaração das matrizes
    // O problema especifica M <= 10 e N <= 10
    int campo[10][10];
    int irrigacao[10][10] = {0}; // Matriz auxiliar para marcar irrigação, inicializada com 0

    int i, j;
    int irrigados = 0;
    int naoIrrigados = 0;

    // Leitura das dimensões M e N
    scanf("%d %d", &M, &N);

    // Leitura da matriz 'campo' usando loops aninhados
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    // Processamento: Marcar os locais irrigados
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Verifica se a posição é um irrigador (valor 2)
            if (campo[i][j] == 2) {
                // O problema garante que irrigadores nunca estão na borda,
                // então podemos acessar os vizinhos com segurança.
                
                // Marca os 4 vizinhos na matriz 'irrigacao'
                irrigacao[i - 1][j] = 1; // Vizinho Norte
                irrigacao[i + 1][j] = 1; // Vizinho Sul
                irrigacao[i][j - 1] = 1; // Vizinho Oeste
                irrigacao[i][j + 1] = 1; // Vizinho Leste
            }
        }
    }

    // Contagem: Verificar setores férteis
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Verifica se o setor é fértil (valor 1)
            if (campo[i][j] == 1) {
                // Usa um condicional if/else para contar
                if (irrigacao[i][j] == 1) {
                    irrigados++;
                } else {
                    naoIrrigados++;
                }
            }
        }
    }

    // Saída do resultado
    printf("%d %d\n", irrigados, naoIrrigados);

    return 0;
}