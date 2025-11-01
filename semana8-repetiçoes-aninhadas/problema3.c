#include <stdio.h>

int main() {
    int n; // Quantidade de pilotos
    int i, piloto;
    
    // Vetores para mapear Piloto -> Posição.
    // Tamanho 21 para acessar índices de 1 a 20 (n <= 20 [cite: 413])
    // [Conceito: Vetores para contagem/mapeamento, cite: 623]
    int pos_largada[21];
    int pos_chegada[21];

    int max_ganho = 0;
    int piloto_vencedor = 0;
    int empate = 0;

    scanf("%d", &n);

    // Lê a ordem de largada e preenche o mapa
    // [Conceito: Laço 'for', cite: 1723]
    for (i = 0; i < n; i++) {
        scanf("%d", &piloto); // Lê o ID do piloto (ex: 2)
        pos_largada[piloto] = i; // Armazena a posição dele (ex: 0)
    }

    // Lê a ordem de chegada e preenche o mapa
    for (i = 0; i < n; i++) {
        scanf("%d", &piloto); // Lê o ID do piloto (ex: 1)
        pos_chegada[piloto] = i; // Armazena a posição dele (ex: 0)
    }

    // Calcula o ganho de cada piloto e acha o vencedor
    for (piloto = 1; piloto <= n; piloto++) {
        // [Conceito: Operador aritmético '-', cite: 2126]
        int ganho = pos_largada[piloto] - pos_chegada[piloto];

        // [Conceito: Condicionais aninhados, cite: 294, 304]
        if (ganho > max_ganho) {
            max_ganho = ganho;          // Novo melhor ganho
            piloto_vencedor = piloto;   // Novo vencedor
            empate = 0;                 // Reseta o flag de empate
        } else if (ganho == max_ganho && max_ganho > 0) {
            // Se o ganho é igual ao máximo (e o máximo é > 0), temos um empate [cite: 417]
            empate = 1;
        }
    }

    // Verifica a condição final para impressão
    // [Conceito: Operador lógico '||' (OU), cite: 2209]
    if (max_ganho == 0 || empate == 1) {
        printf("empate\n");
    } else {
        printf("%d\n", piloto_vencedor);
    }

    return 0;
}