#include <stdio.h> // Para printf e scanf 
#include <string.h> // Para strlen 

int main() {
    // Declara um vetor de char (string) [cite: 380, 890]
    // Tamanho 21 para comportar 20 caracteres mais o '\0' 
    char palavra[21]; 
    
    int indice;
    int bombas = 0; // Variável para contar as bombas [cite: 1893]

    // Lê a string (palavra sem espaços) 
    scanf("%s", palavra);

    // Lê o índice (inteiro) 
    scanf("%d", &indice);

    // Estrutura de seleção if/else [cite: 167]
    // Verifica se há uma bomba no índice exato [cite: 973, 2678]
    if (palavra[indice] == 'x') {
        printf("bum!\n"); // [cite: 1943]
    } else { // 
        // Se não, verifica as adjacências
        
        // Condicionais aninhados 
        // Verifica à esquerda (indice - 1)
        //  (operador >) e  (operador &&)
        if (indice > 0 && palavra[indice - 1] == 'x') {
            bombas = bombas + 1; // [cite: 2607] (ou bombas++)
        }

        // Verifica à direita (indice + 1)
        //  (função strlen) e  (operador <)
        if (indice < (int)strlen(palavra) - 1 && palavra[indice + 1] == 'x') {
            bombas++; // [cite: 2607]
        }

        // Imprime o total de bombas adjacentes
        printf("%d\n", bombas); // 
    }

    return 0; // [cite: 1795]
}