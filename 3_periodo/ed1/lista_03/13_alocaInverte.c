#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tam)
{
    int *vetor = (int *) malloc(tam * sizeof(int));
    
    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void preencherVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }
}

void exibirVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void liberarVetor(int *vetor)
{
    free(vetor);
    vetor = NULL;
}

void inverte(int *vetor, int tam)
{
    int aux;

    for(int i = 0, j = tam-1; i < j; i++, j--)
    {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

int main()
{
    int tam;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);

    int *vetor = alocarVetor(tam);
    preencherVetor(vetor, tam);

    exibirVetor(vetor, tam);
    
    inverte(vetor, tam);
    exibirVetor(vetor, tam);

    liberarVetor(vetor);
    return 0;
}