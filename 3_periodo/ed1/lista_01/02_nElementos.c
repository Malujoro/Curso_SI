#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int n)
{
    int *vetor = (int *) malloc(n * sizeof(int));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void imprimeN(int *vetor, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
}

void liberaVetor(int *vetor)
{
    free(vetor);
    
    if(!vetor)
        printf("Erro! Não foi possível desalocar o vetor");
}

int main()
{
    int n;
    
    printf("Tamanho do vetor: ");
    scanf(" %d", &n);

    int *vetor = alocaVetor(n);
    
    for(int i = 0; i < n; i++)
    {
        printf("%dº elemento: ", i+1);
        scanf(" %d", &vetor[i]);
    }

    imprimeN(vetor, n);
    liberaVetor(vetor);
    
    return 0;
}