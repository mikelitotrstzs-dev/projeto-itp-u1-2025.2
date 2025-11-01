#include <stdio.h> // 
#include <string.h> // Para strlen e strcmp [cite: 623, 702, 834]

int main() {
    char nomeAluno[11]; // [cite: 380, 2561]
    char frequencias[1001]; // [cite: 380, 2560]

    // Lê o nome do aluno (palavra única)
    scanf("%s", nomeAluno); // 

    // Lê o restante da linha (string com espaços)
    //  (gets é para frases com espaços)
    gets(frequencias); // 

    int totalAulas = 0;
    int ausencias = 0;
    int presenteNaAula = 0; // Flag lógica (0 = falso, 1 = verdadeiro) 
    
    char palavraAtual[20]; // Buffer para construir cada palavra
    int p_idx = 0; // Índice da palavraAtual
    int i = 0;

    // Loop 'while' para pular espaços em branco no início
    // (deixados pelo 'scanf' antes do 'gets')
    while (frequencias[i] == ' ') { // [cite: 2133, 2146, 2678]
        i++;
    }

    // Loop 'for' para percorrer a string de frequências [cite: 609, 619, 2380]
    // Continua do 'i' de onde o 'while' parou
    for (; i <= (int)strlen(frequencias); i++) { // 
        char c = frequencias[i];

        // Se for espaço ou fim da string, processa a palavra 
        if (c == ' ' || c == '\0') {
            palavraAtual[p_idx] = '\0'; // Finaliza a string atual 

            // Verifica se a palavra tem o formato de data (DD/MM) [cite: 2561]
            if (strlen(palavraAtual) == 5 && palavraAtual[2] == '/') { // [cite: 620, 2670, 2678]
                // É uma data.
                
                // Se já passamos de uma aula (totalAulas > 0), 
                // verificar se o aluno faltou na aula anterior.
                if (totalAulas > 0) {
                    if (presenteNaAula == 0) { // [cite: 2645, 2678]
                        ausencias++;
                    }
                }
                totalAulas++; // Contabiliza a nova aula
                presenteNaAula = 0; // Reseta a flag de presença
            } 
            // Se não for data e não for vazia, é um nome
            else if (strlen(palavraAtual) > 0) {
                // Compara a palavra com o nome do aluno 
                if (strcmp(palavraAtual, nomeAluno) == 0) {
                    presenteNaAula = 1; // Marca presença 
                }
            }

            p_idx = 0; // Reseta o índice para a próxima palavra
        } else {
            // Se não for espaço, adiciona o caractere à palavraAtual
            palavraAtual[p_idx] = c;
            p_idx++;
        }
    }

    // Após o fim do loop, é preciso verificar a *última* aula
    if (totalAulas > 0) {
        if (presenteNaAula == 0) {
            ausencias++;
        }
    }

    printf("%d\n", ausencias); // 

    return 0; // [cite: 1795]
}