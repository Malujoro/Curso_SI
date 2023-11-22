#include <stdio.h>
#define TAM 8

void preencher(int vetor[])
{
    int i;
    for(i = 0; i < 8; i++)
    {
        printf("Valor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }
}

void exibir(int vetor[])
{
    int i;
    for(i = 0; i < 8; i++)
        printf("\nValor[%d]: %d", i, vetor[i]);
    printf("\n");
}

int menor(int vetor[])
{
    int i, menor, pos;

    pos = 0;
    menor = vetor[0];
    for(i = 1; i < 8; i++)
    {
        if(vetor[i] < menor)
        {
            pos = i;
            menor = vetor[i];
        }
    }
    return pos;
}

int main()
{
    int vetor[TAM], pos;
    
    preencher(vetor);
    exibir(vetor);
    pos = menor(vetor);
    printf("O menor elemento está na posição %d\n", pos);

    return 0;
}