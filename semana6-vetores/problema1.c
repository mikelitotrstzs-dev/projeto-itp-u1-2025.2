#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int gabarito[20], respostas[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &respostas[i]);
    }

    int acertos = 0;
    for (int i = 0; i < n; i++) {
        if (respostas[i] == gabarito[i]) {
            acertos++;
        }
    }

    if (acertos == 1) {
        printf("1 acerto\n");
    } else {
        printf("%d acertos\n", acertos);
    }

    return 0;
}
