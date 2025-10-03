#include <stdio.h>

int main() {
    int v[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    int visitado[10] = {0};
    int ilha = 0;

    while (!visitado[ilha]) {
        visitado[ilha] = 1;
        ilha = v[ilha];
    }

    printf("%d\n", ilha);

    return 0;
}
