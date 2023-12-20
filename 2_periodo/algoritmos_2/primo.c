#include <stdio.h>

int main()
{
    int i, j;
    int vetor[5];

    // Preencher o vetor
    for(i = 0; i < 5; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 2; j < vetor[i]; j++)
        {
            if(vetor[i] % j == 0)
                break;
        }

        if(j == vetor[i])
            printf("\nNúmero [%d] | Posição: [%d]", vetor[i], i);
    }
    return 0;
}