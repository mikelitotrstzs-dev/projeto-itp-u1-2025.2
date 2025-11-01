#include <stdio.h> // 
#include <string.h> // Para strlen 

// Definição de uma função [cite: 1307]
// Verifica se um caractere é uma letra maiúscula
// Usa a equivalência char/int da tabela ASCII [cite: 444-449]
int ehMaiuscula(char c) {
    // Usa operadores relacionais e lógicos [cite: 2680, 2670]
    if (c >= 'A' && c <= 'Z') {
        return 1; // Verdadeiro 
    }
    return 0; // Falso 
}

// Definição de uma função [cite: 1307]
// Verifica se um caractere é um dígito
int ehDigito(char c) {
    if (c >= '0' && c <= '9') {
        return 1; // Verdadeiro
    }
    return 0; // Falso
}

int main() {
    char placa[11]; // 10 caracteres + \0 
    scanf("%s", placa); // 

    int len = strlen(placa); // [cite: 620, 702]

    // Formato Brasileiro: LLL-AAAA (8 caracteres) 
    if (len == 8) { // 
        // Verifica todas as condições usando o operador E (&&) 
        if (ehMaiuscula(placa[0]) && ehMaiuscula(placa[1]) && ehMaiuscula(placa[2]) &&
            placa[3] == '-' && // [cite: 2678]
            ehDigito(placa[4]) && ehDigito(placa[5]) && ehDigito(placa[6]) && ehDigito(placa[7])) {
            printf("brasileiro\n");
        } else {
            printf("inválido\n");
        }
    } 
    // Formato Mercosul: LLLALAA (7 caracteres) 
    else if (len == 7) { // 
        if (ehMaiuscula(placa[0]) && ehMaiuscula(placa[1]) && ehMaiuscula(placa[2]) &&
            ehDigito(placa[3]) &&
            ehMaiuscula(placa[4]) &&
            ehDigito(placa[5]) && ehDigito(placa[6])) {
            printf("mercosul\n");
        } else {
            printf("inválido\n");
        }
    } 
    // Se não tem 7 ou 8 caracteres, é inválido
    else { // 
        printf("inválido\n");
    }

    return 0; // [cite: 1795]
}