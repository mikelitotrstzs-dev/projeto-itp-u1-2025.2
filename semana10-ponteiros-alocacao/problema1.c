#include <stdio.h>
#include <stdlib.h> // Necessário para malloc, free, calloc
#include <limits.h>

// Funções para manipulação de vetores

/**
 * Aloca dinamicamente um vetor de 'n' inteiros.
 * Retorna o endereço base do espaço alocado (ponteiro).
 */
int *alocarVetor(int n) {
    // Aloca (n * tamanho de um int) bytes
    // Usamos calloc para garantir que a memória seja inicializada com zero
    int *v = (int *)calloc(n, sizeof(int)); 
    if (v == NULL) {
        // Tratar erro de alocação
        perror("Falha na alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    return v;
}

/**
 * Calcula a soma de dois vetores de mesma dimensão.
 * Retorna um novo vetor com a soma.
 */
int *somaVetores(int *u, int *v, int n) {
    // A função principal (main) já deve ter garantido que n1 == n2.
    int *w = alocarVetor(n); // Aloca espaço para o vetor resultado.

    for (int i = 0; i < n; i++) {
        // Soma elemento a elemento.
        w[i] = u[i] + v[i];
    }
    return w;
}

/**
 * Imprime os elementos de um vetor.
 */
void imprimirVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;
    int *u = NULL;
    int *v = NULL;
    int *w = NULL;

    // 1. Ler dimensões
    scanf("%d %d", &n1, &n2);

    // 2. Alocar e ler os vetores, se as dimensões forem compatíveis
    if (n1 > 0 && n2 > 0) {
        // Alocar dinamicamente um vetor u de n1 e outro v de n2.
        u = alocarVetor(n1); 
        v = alocarVetor(n2);
        
        // Ler n1 inteiros para u e n2 inteiros para v.
        for (int i = 0; i < n1; i++) {
            scanf("%d", &u[i]);
        }
        for (int i = 0; i < n2; i++) {
            scanf("%d", &v[i]);
        }
    }
    
    // 3. Verificar compatibilidade e chamar a função de soma
    if (n1 == n2 && n1 > 0) {
        w = somaVetores(u, v, n1);
        // Escrever na tela o vetor resultante.
        imprimirVetor(w, n1);
    } else {
        // Escrever 'dimensoes incompativeis' caso n1 != n2.
        printf("dimensoes incompativeis\n");
    }

    // 4. Liberar a memória alocada dinamicamente
    if (u != NULL) free(u);
    if (v != NULL) free(v);
    if (w != NULL) free(w);

    return 0;
}