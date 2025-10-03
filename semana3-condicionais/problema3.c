#include <stdio.h>

int main() {
    float n1, n2, n3, media, notaFinal, mediaFinal;

    printf("Digite as tres notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = (n1 + n2 + n3) / 3;
    printf("Media = %.2f\n", media);

    if(media >= 7.0) {
        printf("Aluno aprovado!\n");
    } else if(media < 4.0) {
        printf("Aluno reprovado!\n");
    } else {
        printf("Aluno em recuperacao.\n");
        printf("Digite a nota da prova final: ");
        scanf("%f", &notaFinal);
        mediaFinal = (media + notaFinal) / 2;
        if(mediaFinal >= 5.0) {
            printf("Aprovado na recuperacao!\n");
        } else {
            printf("Reprovado apos recuperacao.\n");
        }
    }
    return 0;
}
