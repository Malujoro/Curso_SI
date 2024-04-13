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
    int *vetor = alocarVetor(1);
    int tam = -1;

    do
    {
        tam++;
        vetor = (int *) realloc(vetor, (tam+1) * sizeof(int));
        printf("%dº Número: ", tam+1);
        scanf(" %d", &vetor[tam]);
    }while(vetor[tam] >= 0);

    vetor = (int *) realloc(vetor, (tam) * sizeof(int));

    exibirVetor(vetor, tam);

    liberarVetor(vetor);
    return 0;
}