#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definimos o tamanho máximo para uma palavra e o limite para o relatório
#define MAX_PALAVRA 50
#define MAX_PALAVRAS_REPORT 10
#define TAMANHO_TEXTO_MAX 1024 // Tamanho máximo da string de entrada

// Estrutura para armazenar a palavra e sua contagem de frequência
// Requisito: Structs (Tópico avançado) + Alocação Dinâmica (U2)
typedef struct {
    char palavra[MAX_PALAVRA]; // String (U2)
    int contagem;              // Variável (U1)
    int tamanho;
} ItemFrequencia;

// Protótipos das Funções (Requisito: Funções - U1)
void limpar_string(char *str);
int eh_delimitador(char c);
int analisar_texto(char *texto, ItemFrequencia **dicionario, int *num_palavras_unicas);
void criar_relatorio_tabular(ItemFrequencia *dicionario, int tamanho_dicionario, char matriz_relatorio[MAX_PALAVRAS_REPORT][MAX_PALAVRA]);
void imprimir_matriz(char matriz_relatorio[MAX_PALAVRAS_REPORT][MAX_PALAVRA]);
void liberar_memoria(ItemFrequencia *dicionario);

// Variável Global para contagem total (Não recomendada, mas usada para demonstração de escopo) [cite: 2705]
int total_de_palavras_contadas = 0;

int main() {
    // Declaração de variáveis
    char *texto_original;
    ItemFrequencia *dicionario = NULL; // Ponteiro para a lista de structs (Ponteiros - U2)
    int num_palavras_unicas = 0;
    int resultado_analise;
    
    // Alocação Dinâmica: Reservando espaço para a string de entrada [cite: 1418, 4496]
    texto_original = (char *)malloc(TAMANHO_TEXTO_MAX * sizeof(char));
    if (texto_original == NULL) {
        printf("Erro de Alocacao de Memoria para o texto.\n");
        return 1;
    }
    
    // Entrada de Dados (U1)
    printf("==========================================\n");
    printf("  SISTEMA DE ANALISE DE TEXTOS (U2)       \n");
    printf("==========================================\n");
    printf("Digite um texto (max %d caracteres):\n", TAMANHO_TEXTO_MAX - 1);
    
    // Leitura do texto completo, incluindo espacos. Usando fgets para seguranca.
    if (fgets(texto_original, TAMANHO_TEXTO_MAX, stdin) == NULL) {
        free(texto_original);
        return 1;
    }
    
    // Limpa a string de entrada para evitar o '\n' do fgets
    if (texto_original[strlen(texto_original) - 1] == '\n') {
        texto_original[strlen(texto_original) - 1] = '\0';
    }
    
    // --- 1. Analise de Frequencia ---
    resultado_analise = analisar_texto(texto_original, &dicionario, &num_palavras_unicas);
    
    if (resultado_analise != 0) {
        printf("Nao foi possivel analisar o texto.\n");
        liberar_memoria(dicionario);
        free(texto_original);
        return 1;
    }
    
    // --- 2. Preparacao do Relatorio em Matriz (Matrizes e Repetição Aninhada - U2) ---
    // A matriz armazena o cabeçalho e as 9 palavras mais longas.
    // Usamos Matriz de char (arranjo bidimensional de char) [cite: 882, 1409]
    char matriz_relatorio[MAX_PALAVRAS_REPORT][MAX_PALAVRA]; 
    
    printf("\n==========================================\n");
    printf("RESULTADO GERAL\n");
    printf("Total de palavras lidas: %d\n", total_de_palavras_contadas);
    printf("Palavras unicas encontradas: %d\n", num_palavras_unicas);
    printf("==========================================\n\n");
    
    // Chamar a função para preencher a matriz do relatório
    criar_relatorio_tabular(dicionario, num_palavras_unicas, matriz_relatorio);

    // Imprimir o relatório matricial (Matrizes e Repetição Aninhada - U2)
    printf("RELATORIO DE FREQUENCIA (10 PALAVRAS MAIS LONGAS):\n");
    imprimir_matriz(matriz_relatorio);
    
    // --- 3. Liberacao de Memoria (U2) ---
    liberar_memoria(dicionario);
    free(texto_original); // Libera o texto de entrada alocado dinamicamente
    
    return 0; // Saída: 0 indica sucesso [cite: 2924]
}

// ====================================================================================
// FUNÇÕES DE UTILIDADE E PROCESSAMENTO
// ====================================================================================

/**
 * @brief Verifica se um caractere é um delimitador de palavra (espaco, pontuacao, etc.).
 * @param c Caractere a ser verificado.
 * @return 1 se for delimitador, 0 caso contrario.
 */
int eh_delimitador(char c) {
    // Requisito: Operadores Lógicos (U1) e Funções (U1)
    return (isspace(c) || c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';');
}

/**
 * @brief Limpa a string de qualquer caractere '\n' ou pontuacao no final.
 * @param str Ponteiro para a string.
 * @return void
 */
void limpar_string(char *str) {
    int i = strlen(str) - 1;
    // Percorre a string de tras para frente (Repetição - U1)
    while (i >= 0 && eh_delimitador(str[i])) {
        str[i] = '\0';
        i--;
    }
}

/**
 * @brief Analisa o texto, populando o dicionário com palavras e frequências.
 * * @param texto O texto de entrada.
 * @param dicionario Ponteiro para o dicionário de palavras (ponteiro de ponteiro para passagem por referência).
 * @param num_palavras_unicas Ponteiro para a contagem de palavras únicas.
 * @return int 0 em caso de sucesso, 1 em caso de falha.
 */
int analisar_texto(char *texto, ItemFrequencia **dicionario, int *num_palavras_unicas) {
    char *token;
    int capacidade_dicionario = 0;
    
    // Cria uma copia modificavel do texto
    char *texto_copia = strdup(texto); // Uso da função string.h (U2)
    if (texto_copia == NULL) return 1;

    // Uso de strtok para tokenizar o texto (simula a quebra de palavras)
    token = strtok(texto_copia, " \n\t.,:;!?()");

    // Laco principal para processar cada palavra (Repetição - U1)
    while (token != NULL) {
        // Limpa a pontuacao remanescente
        limpar_string(token);
        
        // Verifica se a palavra nao esta vazia (Condicional - U1)
        if (strlen(token) > 0) {
            
            // --- Logica de contagem ---
            int encontrado = 0;
            for (int i = 0; i < *num_palavras_unicas; i++) {
                // strcmp: Comparação de Strings (U2)
                if (strcmp((*dicionario)[i].palavra, token) == 0) {
                    (*dicionario)[i].contagem++;
                    encontrado = 1;
                    break;
                }
            }
            
            // Se nao for encontrada, adiciona uma nova entrada (Alocação Dinâmica - U2)
            if (!encontrado) {
                // Aumenta a capacidade do dicionario a cada 10 novos itens
                if (*num_palavras_unicas >= capacidade_dicionario) {
                    capacidade_dicionario += 10;
                    // realloc: Alocação dinâmica para redimensionar a memória
                    *dicionario = (ItemFrequencia *)realloc(*dicionario, capacidade_dicionario * sizeof(ItemFrequencia));
                    
                    // Tratamento de falha de alocação (Requisito: Tratamento de erro - U2) [cite: 1422]
                    if (*dicionario == NULL) {
                        printf("Falha ao realocar memoria para o dicionario.\n");
                        free(texto_copia);
                        return 1;
                    }
                }
                
                // strcpy: Copia de Strings (U2)
                strcpy((*dicionario)[*num_palavras_unicas].palavra, token); 
                (*dicionario)[*num_palavras_unicas].contagem = 1;
                (*dicionario)[*num_palavras_unicas].tamanho = strlen(token);
                (*num_palavras_unicas)++;
            }
            
            total_de_palavras_contadas++;
        }
        
        token = strtok(NULL, " \n\t.,:;!?()"); // Busca o proximo token
    }

    free(texto_copia);
    return 0;
}

/**
 * @brief Compara dois itens para ordenação por tamanho, e depois por contagem (decrescente).
 */
int comparar_por_tamanho_e_contagem(const void *a, const void *b) {
    ItemFrequencia *itemA = (ItemFrequencia *)a;
    ItemFrequencia *itemB = (ItemFrequencia *)b;

    // 1. Prioriza o tamanho (do maior para o menor)
    if (itemA->tamanho != itemB->tamanho) {
        return itemB->tamanho - itemA->tamanho;
    }
    // 2. Se o tamanho for igual, prioriza a contagem (do maior para o menor)
    return itemB->contagem - itemA->contagem;
}

/**
 * @brief Preenche uma matriz para relatorio tabular com as N palavras mais relevantes.
 * * @param dicionario Dicionário de palavras.
 * @param tamanho_dicionario Tamanho do dicionário.
 * @param matriz_relatorio Matriz para armazenar o relatório.
 */
void criar_relatorio_tabular(ItemFrequencia *dicionario, int tamanho_dicionario, char matriz_relatorio[MAX_PALAVRAS_REPORT][MAX_PALAVRA]) {
    // Ordena o dicionario para encontrar as palavras mais longas e frequentes.
    qsort(dicionario, tamanho_dicionario, sizeof(ItemFrequencia), comparar_por_tamanho_e_contagem);

    // Converte int para string (necessario para armazenar na matriz de char)
    char temp_str[10];

    // Preenche o cabecalho (Linha 0 da Matriz)
    // strcpy: Uso de função de string.h (U2)
    strcpy(matriz_relatorio[0], "PALAVRA | TAM | FREG");
    
    int num_linhas = (tamanho_dicionario < MAX_PALAVRAS_REPORT - 1) ? tamanho_dicionario : MAX_PALAVRAS_REPORT - 1;

    // Repetição Aninhada para preencher a Matriz (U2) [cite: 1405, 1406, 1407]
    for (int i = 0; i < num_linhas; i++) {
        // Formata a linha como uma string: Palavra | Tamanho | Frequência
        char linha[MAX_PALAVRA];
        
        // Coluna 1: Palavra (String - U2)
        // snprintf: Uso de função de string.h (U2)
        snprintf(linha, MAX_PALAVRA, "%s", dicionario[i].palavra);

        // Coluna 2: Tamanho (int para String)
        sprintf(temp_str, " | %d", dicionario[i].tamanho);
        strcat(linha, temp_str);
        
        // Coluna 3: Frequência (int para String)
        sprintf(temp_str, " | %d", dicionario[i].contagem);
        strcat(linha, temp_str);
        
        // Copia a linha formatada para a Matriz (Array Bidimensional - U2)
        strncpy(matriz_relatorio[i + 1], linha, MAX_PALAVRA - 1);
        matriz_relatorio[i + 1][MAX_PALAVRA - 1] = '\0'; // Garantir o fim da string
    }
}

/**
 * @brief Imprime a matriz do relatório com formatação.
 * * @param matriz_relatorio A matriz contendo as linhas do relatório.
 */
void imprimir_matriz(char matriz_relatorio[MAX_PALAVRAS_REPORT][MAX_PALAVRA]) {
    // Repetição Aninhada (U2) - Um loop externo para as linhas, um interno para a formatação/impressão da linha
    for (int i = 0; i < MAX_PALAVRAS_REPORT; i++) {
        printf("%s\n", matriz_relatorio[i]); // Imprime a linha inteira da matriz (string)
        if (i == 0) {
            printf("---------------------------------------\n");
        }
    }
}

/**
 * @brief Libera a memória alocada dinamicamente.
 * * @param dicionario O ponteiro para o dicionário.
 */
void liberar_memoria(ItemFrequencia *dicionario) {
    if (dicionario != NULL) {
        free(dicionario); // Requisito: free() para evitar memory leak (U2) 
        printf("\nMemoria do dicionario liberada com sucesso.\n");
    }
}