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

int *intervalo(int *vetor, int tam, int minimo, int maximo, int *tam2)
{
    *tam2 = 0;
    int *vetor2 = alocarVetor(tam);

    for(int i = 0; i < tam; i++)
    {
        if(vetor[i] > minimo && vetor[i] < maximo)
        {
            vetor2[*tam2] = vetor[i];
            (*tam2)++;
        }
    }
    vetor2 = (int *) realloc(vetor2, (*tam2) * sizeof(int));

    return vetor2;
}

int main()
{
    int tam, tam2, minimo, maximo;
    
    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &tam);

    int *vetor = alocarVetor(tam);
    preencherVetor(vetor, tam);

    printf("Digite os valores mínimo e máximo: ");
    scanf(" %d %d", &minimo, &maximo);

    int *vetor2 = intervalo(vetor, tam, minimo, maximo, &tam2);
    exibirVetor(vetor2, tam2);

    free(vetor2);
    return 0;
}