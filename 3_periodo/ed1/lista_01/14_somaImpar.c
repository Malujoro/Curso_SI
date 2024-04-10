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

int main()
{
    int tam, somaImpar = 0;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);

    int *vetor = alocarVetor(tam);
    preencherVetor(vetor, tam);
    exibirVetor(vetor, tam);

    for(int i = 0; i < tam; i++)
    {
        if(vetor[i] % 2 == 1)
            somaImpar += vetor[i];
    }

    printf("A soma dos ímpares é: %d\n", somaImpar);

    free(vetor);
    return 0;
}