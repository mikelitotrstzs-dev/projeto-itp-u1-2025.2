#include <stdio.h> // [cite: 1986, 2000]

int main() { // [cite: 1989, 867]
    
    // --- Declaração de Variáveis ---
    
    int M; // Número de cidades [cite: 2091]
    
    // Matriz para os preços. O problema define M <= 10. [cite: 3257]
    // [cite: 2582, 2591] (Conceito de 'arranjosBidimensionais.pdf')
    int precos[10][10];
    
    int X, Z; // Cidades de origem (X) e destino (Z) [cite: 2091]
    int i, j; // Variáveis de iteração para os loops 'for' [cite: 1328]
    
    int custoMinimo;
    int cidadeIntermediaria; // Armazena a cidade 'Y' do melhor caminho
    int custoComParada;

    // --- Leitura dos Dados de Entrada ---

    // Lê o tamanho da matriz (M) [cite: 2162]
    scanf("%d", &M);

    // Usa repetições aninhadas para ler a matriz M x M [cite: 3199, 2765]
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            // Lê o preço e armazena em precos[i][j] [cite: 2770]
            scanf("%d", &precos[i][j]);
        }
    }

    // Lê a origem (X) e o destino (Z) [cite: 2180]
    scanf("%d %d", &X, &Z);

    // --- Processamento (Encontrar o menor custo) ---

    // 1. Define o custo direto (0 paradas) como o custo mínimo inicial.
    // [cite: 2239] (Operador de atribuição)
    // [cite: 2604] (Acesso a elemento da matriz)
    custoMinimo = precos[X][Z];
    cidadeIntermediaria = -1; // Usamos -1 como "bandeira" para o caminho direto

    // 2. Verifica todos os caminhos com 1 parada (X -> i -> Z)
    // [cite: 1328] (Estrutura 'for')
    for (i = 0; i < M; i++) {
        
        // Calcula o custo passando pela cidade 'i'
        // [cite: 2214] (Operador aritmético '+')
        custoComParada = precos[X][i] + precos[i][Z];

        // Compara o novo custo com o custo mínimo atual
        // [cite: 2916] (Estrutura 'if')
        // [cite: 2313] (Operador relacional '<')
        if (custoComParada < custoMinimo) {
            // Se for mais barato, atualiza o custo mínimo
            custoMinimo = custoComParada;
            // E salva qual foi a cidade intermediária
            cidadeIntermediaria = i;
        }
    }

    // --- Impressão do Resultado ---

    // Verifica se o caminho mais barato foi o direto (cidadeIntermediaria == -1)
    // [cite: 3013] (Estrutura 'if/else')
    // [cite: 2311] (Operador relacional '==')
    if (cidadeIntermediaria == -1) {
        // Imprime o caminho direto (X -> Z)
        // [cite: 2151, 2153] (Impressão formatada 'printf')
        printf("%d-%d R$%d\n", X, Z, custoMinimo);
    } else {
        // [cite: 3018] (Bloco 'else')
        // Imprime o caminho com parada (X -> Y -> Z)
        printf("%d-%d-%d R$%d\n", X, cidadeIntermediaria, Z, custoMinimo);
    }

    // Retorno da função main [cite: 869, 1997]
    return 0;
}