#include <stdio.h>
#include <time.h>

// Dados 100 números armazenados em um vetor, exibir quantos números são maiores,
// quantos são menores e quantos são iguais a média aritmética de todos os números do vetor

int main(void)
{
    int quant = 100, i, vetor[quant];
    //float media = 0;
    // Media int para conseguir ter valores inteiros iguais a ela
    int media = 0;
    int quant_maior = 0, quant_menor = 0, quant_igual = 0;

    srand(time(NULL));

    for (i = 0; i < quant; i++)
    {
        
        vetor[i] = rand() % 51;
        media += vetor[i];
    }

    media /= quant;

    for (i = 0; i < quant; i++)
    {
        if (vetor[i] > media)
        {
            quant_maior ++;
        }
        else if (vetor[i] < media)
        {
            quant_menor ++;
        }
        else if (vetor[i] == media)
        {
            quant_igual++;
        }
    }

    printf("\nMédia: %d\n", media);
    printf("\nMaiores que a média: %d", quant_maior);
    printf("\nMenores que a média: %d", quant_menor);
    printf("\nIguais a média: %d\n", quant_igual);

    return 0;
}