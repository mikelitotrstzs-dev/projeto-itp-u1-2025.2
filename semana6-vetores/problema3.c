#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int alturas[30];
    for (int i = 0; i < n; i++) {
        scanf("%d", &alturas[i]);
    }

    int maior = alturas[0];
    for (int i = 1; i < n; i++) {
        if (alturas[i] > maior) {
            maior = alturas[i];
        }
    }

    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < n; i++) {
        if (alturas[i] == maior) {
            if (pos1 == -1) pos1 = i;
            else pos2 = i;
        }
    }

    printf("%d\n", pos2 - pos1);

    return 0;
}
