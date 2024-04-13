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
        vetor[i] = i;
}

void liberarVetor(int *vetor)
{
    free(vetor);
    vetor = NULL;
}

int main()
{
    int tam = 1500;

    int *vetor = alocarVetor(tam);

    preencherVetor(vetor, tam);

    printf("\n10 primeiros valores: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);

    printf("\n10 últimos valores: ");
    for(int i = tam-10; i < tam; i++)
        printf("%d ", vetor[i]);

    liberarVetor(vetor);
    return 0;
}