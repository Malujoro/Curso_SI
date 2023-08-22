#include <stdio.h>

// Dados 10 números armazenados em um vetor, exibir quantos números são maiores,
// quantos são menores e quantos são iguais a média aritmética de todos os números do vetor

int main(void)
{
    int quant = 10, i;
    float vetor[quant], media;
    int vetor2[3];
    // 0 - Maiores
    // 1 - Menores
    // 2 - Iguais 

    media = 0;
    for (i = 0; i < quant; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%f", &vetor[i]);
        media += vetor[i];
    }
    media /= quant;

    vetor2[0] = 0;
    vetor2[1] = 0;
    vetor2[2] = 0;
    for (i = 0; i < quant; i++)
    {
        if (vetor[i] > media)
            vetor2[0]++;
        if (vetor[i] < media)
            vetor2[1]++;
        if (vetor[i] == media)
            vetor2[2]++;
    }

    printf("\nMédia: %.1f", media);
    printf("\nMaiores: %d\nMenores: %d\nIguais: %d\n", vetor2[0], vetor2[1], vetor2[2]);

    return 0;
}