#include <stdio.h>
#include <string.h> // Para usar strcpy [cite: 2659]

int main() {
    int chuva[12];
    char meses[12][12] = { // Vetor de strings para os nomes 
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    int i, j, max_index;
    
    // Variáveis temporárias para a troca (swap)
    int temp_chuva;
    char temp_mes[12];

    // Lê os 12 valores de chuva
    // [Conceito: Laço 'for' para preencher vetor, cite: 1723, 592]
    for (i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }

    // Ordena os vetores usando Selection Sort (ordem decrescente)
    // [Conceito: Laços aninhados para ordenação, cite: 1, 3]
    for (i = 0; i < 11; i++) {
        // Encontra o índice do maior elemento restante
        max_index = i;
        for (j = i + 1; j < 12; j++) {
            // [Conceito: Condicional 'if' para comparação, cite: 127]
            if (chuva[j] > chuva[max_index]) {
                max_index = j;
            }
        }

        // Se o maior não for o elemento atual (i), realiza a troca
        if (max_index != i) {
            // 1. Troca o valor da chuva
            temp_chuva = chuva[i];
            chuva[i] = chuva[max_index];
            chuva[max_index] = temp_chuva;

            // 2. Troca o nome do mês (usando strcpy [cite: 2704])
            strcpy(temp_mes, meses[i]);
            strcpy(meses[i], meses[max_index]);
            strcpy(meses[max_index], temp_mes);
        }
    }

    // Imprime o ranking ordenado
    // [Conceito: Escrita de string com %s, cite: 2489]
    for (i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i], chuva[i]);
    }

    return 0;
}