#include <stdio.h>

int main() {
    char j1, j2;

    printf("Jogador 1 (P/A/T): ");
    scanf(" %c", &j1);
    printf("Jogador 2 (P/A/T): ");
    scanf(" %c", &j2);

    if(j1 == j2) {
        printf("Empate!\n");
    } else if((j1=='P' && j2=='T') || (j1=='T' && j2=='A') || (j1=='A' && j2=='P')) {
        printf("Jogador 1 venceu!\n");
    } else {
        printf("Jogador 2 venceu!\n");
    }
    return 0;
}
