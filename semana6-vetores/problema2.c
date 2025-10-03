#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int tem[1001] = {0}; 

    for (int i = 0; i < n; i++) {
        int fig;
        scanf("%d", &fig);
        tem[fig] = 1; 
    }

    for (int i = 1; i <= m; i++) {
        if (!tem[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
