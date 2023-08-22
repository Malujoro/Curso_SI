#include <stdio.h>

// Armazenar 10 números em um vetor e exibi-los primeiro pela ordem em
// que foram inseridos e depois ao contrário

int main(void)
{
    int vetor[10], c;

    for (c = 0; c < 10; c++)
    {
        printf("%dº número: ", c+1);
        scanf("%d", &vetor[c]);
        setbuf(stdin, NULL);
    }

    for (c = 0; c < 10; c++)
    {
        printf("\n%dº número: %d", c+1, vetor[c]);
    }

    for (c = 9; c >= 0; c--)
    {
        printf("\n%dº número: %d", c+1, vetor[c]);
    }

    return 0;
}