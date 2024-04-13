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
}

void liberarVetor(int *vetor)
{
    free(vetor);
    vetor = NULL;
}

void centroFora(int *vetor, int tam)
{
    int centro = tam/2;
    printf("\n %d", vetor[centro]);

    for(int i = centro-1, j = centro+1; i >= 0 && j < tam; i--, j++)
        printf("\n%d %d", vetor[i], vetor[j]);
    printf("\n");
}

int main()
{
    int tam;

    do
    {
        printf("Tamanho do vetor (ímpar): ");
        scanf(" %d", &tam);
    }while(tam % 2 == 0);

    int *vetor = alocarVetor(tam);

    preencherVetor(vetor, tam);
    exibirVetor(vetor, tam);
    centroFora(vetor, tam);

    liberarVetor(vetor);
    return 0;
}