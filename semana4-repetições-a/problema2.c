#include <stdio.h>
#include <math.h>

int main() {
    float x, y, T;
    int n;

    scanf("%f %f %f", &x, &y, &T);

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        float ax, ay;

        scanf("%f %f", &ax, &ay);

        float dist = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));

        if (dist > T) {
            printf("N\n"); 
            return 0;
        }

        x = 2 * ax - x;

    }

    printf("S\n");
    return 0;
}
