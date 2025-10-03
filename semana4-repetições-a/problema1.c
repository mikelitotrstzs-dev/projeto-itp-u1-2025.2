#include <stdio.h>

int main() {
    float comp, larg, bolso;
    int dobras = 0;

    scanf("%f %f %f", &comp, &larg, &bolso);

    while(comp > bolso && larg > bolso) {
        if(comp > larg) {
            comp = comp / 2.0;
        } else {
            larg = larg / 2.0;
        }
        dobras++;
    }

    printf("%d\n", dobras);
    return 0;
}
