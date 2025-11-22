#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Retorna o endereço base de um vetor contendo os índices do 'valor' buscado.
 * A quantidade de ocorrências é armazenada indiretamente em *qtd.
 * Retorna NULL se não houver ocorrências.
 */
int* buscaNoVetor(int *v, int n, int valor, int *qtd) {
    int count = 0;
    
    // 1. Contar as ocorrências do valor no vetor v
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            count++;
        }
    }

    // 2. Armazenar a contagem via ponteiro 'qtd'
    *qtd = count; 

    // 3. Se não houver ocorrências, retorna NULL
    if (count == 0) {
        return NULL;
    }

    // 4. Alocar dinamicamente o vetor para armazenar os índices
    int *indices = (int*) malloc(count * sizeof(int)); 
    if (indices == NULL) {
        printf("Erro ao alocar memória para indices.\n");
        exit(1);
    }

    // 5. Percorrer novamente o vetor para armazenar os índices encontrados
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[j] = i; // Guarda o índice
            j++;
        }
    }

    return indices;
}

int main() {
    int n; 
    int *v = NULL;
    int valor;
    int *indices = NULL;
    int qtd_ocorrencias = 0;
    
    // 1. Ler a quantidade de elementos 'n'
    if (scanf("%d", &n) != 1) return 1;

    // 2. Alocar dinamicamente o vetor principal 'v'
    if (n > 0) {
        v = (int*) malloc(n * sizeof(int));
        if (v == NULL) return 1;
    }
    
    // 3. Ler os n inteiros para 'v'
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    // 4. Ler o valor a ser buscado
    if (scanf("%d", &valor) != 1) return 1;
    
    // 5. Obter os índices das ocorrências
    // Passamos o endereço de qtd_ocorrencias para o retorno indireto do contador
    indices = buscaNoVetor(v, n, valor, &qtd_ocorrencias);

    // 6. Escrever o resultado
    if (indices == NULL) {
        printf("Nenhuma ocorrencia\n");
    } else {
        printf("%d\n", qtd_ocorrencias); // Escreve a quantidade
        for (int i = 0; i < qtd_ocorrencias; i++) {
            printf("%d", indices[i]); // Escreve os índices
        }
        printf("\n");
    }

    // 7. Liberar a memória
    if (v != NULL) free(v); 
    if (indices != NULL) free(indices); // Libera o vetor de índices criado na função

    return 0;
}