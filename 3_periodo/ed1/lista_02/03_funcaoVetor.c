#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tam)
{
    int *vetor = (int *) malloc(tam * sizeof(int));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void preencherVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i+1);
        scanf(" %d", &vetor[i]);
    }
}

void exibirVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
}

void liberarVetor(int *vetor)
{
    free(vetor);
    vetor = NULL;
}


int main()
{
    int n;

    printf("Tamanho do vetor: ");
    scanf(" %d", &n);

    int *vetor = alocarVetor(n);
    preencherVetor(vetor, n);
    exibirVetor(vetor, n);
    liberarVetor(vetor);

    return 0;
}