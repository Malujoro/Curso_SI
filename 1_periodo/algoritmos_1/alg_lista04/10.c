#include <stdio.h>

// Criar um algoritmo que leia os elementos de um vetor com 20 posições e escreva-o
// Em seguida, troque o primeiro elemento pelo último, o seguindo pelo penúltimo,
// o terceito pelo antepenúltimo e assim sucessivamente.
// Mostre o vetor depois das trocas

int main(void)
{
    int quant = 20, i, aux, fim;
    int vetor[20];

    for (i = 0; i < quant; i++)
    {
        vetor[i] = i;
    }
    
    for (i = 0; i < quant; i++)
    {
        printf("%d\n", vetor[i]);
    }

    fim = quant-1;
    for (i = 0; i < (quant/2); i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[fim];
        vetor[fim] = aux;
        
        fim--;
    }

    for (i = 0; i < quant; i++)
    {
        printf("%d\n", vetor[i]);
    }

    return 0;
}