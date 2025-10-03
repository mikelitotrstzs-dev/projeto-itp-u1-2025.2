#include <stdio.h>
#include <math.h>

int ehPrimo(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int limite = sqrt(n);
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int x = 2; x <= 50000; x++) {
        if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }
    return 0;
}
