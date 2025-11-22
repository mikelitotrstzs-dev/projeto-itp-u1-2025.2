#include <stdio.h>
#include <stdlib.h> // Para malloc, free e NULL
#include <string.h> // Para strlen

/*
 * Recebe duas strings e retorna uma nova string alocada dinamicamente,
 * alternando as letras e anexando o restante da maior string.
 * Retorna NULL em caso de falha de alocação.
 */
char* misturar(char *str1, char *str2) {
    // DECLARAÇÃO DE TODAS AS VARIÁVEIS NO INÍCIO DO BLOCO
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_total = len1 + len2;

    // Variáveis de controle de índice
    int i = 0; 
    int j = 0; 
    int k = 0; 

    // O ponteiro é declarado sem atribuição aqui
    char *nova_str; 

    // Aloca a nova string com espaço para todos os caracteres + o '\0'
    // A atribuição é feita separadamente para maior compatibilidade.
    nova_str = (char*) malloc((len_total + 1) * sizeof(char)); 
    
    if (nova_str == NULL) {
        // Retorna NULL se a alocação falhar
        return NULL; 
    }
    
    // Início da lógica para alternar
    while (i < len1 && j < len2) {
        nova_str[k++] = str1[i++];
        nova_str[k++] = str2[j++];
    }

    // Anexa os caracteres restantes
    while (i < len1) {
        nova_str[k++] = str1[i++];
    }
    while (j < len2) {
        nova_str[k++] = str2[j++];
    }

    // Finaliza a string
    nova_str[k] = '\0';

    return nova_str;
}

int main() {
    // Declaramos o tamanho das strings de entrada (até 100 caracteres)
    char str1[101], str2[101];
    char *resultado = NULL;

    // Leitura das duas strings.
    printf("Digite a primeira palavra (max 100): ");
    if (scanf("%s", str1) != 1) return 1; 
    
    printf("Digite a segunda palavra (max 100): ");
    if (scanf("%s", str2) != 1) return 1;

    // Chamada da função misturar
    resultado = misturar(str1, str2);

    // Escrever o resultado e liberar a memória
    if (resultado != NULL) {
        printf("Resultado da mistura: %s\n", resultado);
        free(resultado); // Liberando a memória alocada dinamicamente
    } else {
        printf("Falha na alocacao de memoria.\n");
    }

    return 0;
}