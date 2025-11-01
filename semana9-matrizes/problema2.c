#include <stdio.h> // Para printf e scanf

int main() {
    int M;
    // O problema especifica M <= 100
    int amizades[100][100];
    int x; // Usuário para quem vamos sugerir
    int i, j, k;

    // 1. Ler o tamanho M
    scanf("%d", &M);

    // 2. Ler a matriz de amizades (loops aninhados)
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }

    // 3. Ler o usuário 'x'
    scanf("%d", &x);

    // 4. Loop principal: Iterar por todos os usuários 'j' para ver se podem ser sugeridos
    // O loop de 0 a M-1 já garante a "ordem numérica crescente"
    for (j = 0; j < M; j++) {
        
        // Condição 1: 'x' e 'j' NÃO são amigos
        // (O problema garante a[ii]=0, então 'x' não será sugerido para si mesmo)
        if (amizades[x][j] == 0) {
            
            int achouComum = 0; // Variável "flag" para marcar se achou amigo em comum

            // Condição 2: Verificar se há PELO MENOS UM amigo em comum 'k'
            for (k = 0; k < M; k++) {
                
                // 'k' é amigo de 'x' E 'k' também é amigo de 'j'?
                // (Usamos amizades[k][j] ou amizades[j][k], pois a matriz é simétrica)
                if (amizades[x][k] == 1 && amizades[j][k] == 1) {
                    achouComum = 1;
                    break; // Já achou um amigo em comum, não precisa continuar procurando
                }
            }

            // 5. Se as duas condições foram atendidas, imprimir a sugestão
            if (achouComum == 1) {
                printf("%d ", j);
            }
        }
    }
    
    printf("\n"); // Para pular a linha no final da saída

    return 0;
}