#include <stdio.h> // Para printf e scanf

int main() {
    int M;
    // O problema especifica M <= 20
    int placar[20][20];
    int i, j;
    int empates = 0; // Contador para o resultado

    // 1. Ler o tamanho M
    scanf("%d", &M);

    // 2. Ler a matriz de placares (loops aninhados)
    // Conforme ensinado em "arranjosBidimensionais.pdf"
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &placar[i][j]);
        }
    }

    // 3. Processar os jogos
    // Para evitar contar o jogo i x j E o jogo j x i,
    // o loop 'j' começa em 'i + 1'.
    // Isso garante que só verificamos pares onde j > i
    // (ex: 0x1, 0x2, 1x2)
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < M; j++) {
            
            // Verifica a condição de empate usando o operador relacional '=='
            // [cite: 114]
            // a[i][j] == a[j][i]
            if (placar[i][j] == placar[j][i]) {
                empates++; // Incrementa o contador
            }
        }
    }

    // 4. Imprimir o resultado final
    printf("%d\n", empates);

    return 0;
}