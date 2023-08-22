#include <stdio.h>

// Preencher um vetor com 5 números e a medida que for digitado o número,
// calcular o cubo e mostrar em outro vetor.
// Mostrar os dois vetores

int main(void)
{
    int quant = 5, i;
    int vetor[quant], cubo[quant];

    for (i = 0; i < quant; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &vetor[i]);

        cubo[i] = vetor[i] * vetor[i] * vetor[i];
    }

    printf("\nVetor \t Cubo\n");
    for (i = 0; i < quant; i++)
    {
        printf("%d \t %d\n", vetor[i], cubo[i]);
    }
    return 0;
}