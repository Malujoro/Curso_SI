#include <stdio.h>

// Dado dois vetores com 5 posições (0 a 4)
// Em cada vetor, entrar com cinco números
// Mostrar os números e depois somar números que pertençam a mesma posição,
// ou seja: [0]+[0], [1]+[1]...

int main(void)
{
    int vetor1[5], vetor2[5], vetor_soma[5], i;

    printf("\nVetor 1\n");
    for (i = 0; i < 5; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &vetor1[i]);
        setbuf(stdin, NULL);
    }

    printf("\n\nVetor 2:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &vetor2[i]);
        setbuf(stdin, NULL);
    }

    for (i = 0; i < 5; i++)
    {
        vetor_soma[i] = vetor1[i] + vetor2[i];
    }

    printf("\nNÚMEROS DIGITADOS:\n");
    printf("\nVetor 1 \t Vetor 2 \t Somatório\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d \t \t %d \t \t %d\n", vetor1[i], vetor2[i], vetor_soma[i]);
    }
    return 0;
}