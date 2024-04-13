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

int somarImpar(int *vetor, int tam)
{
    int soma = 0;

    for(int i = 0; i < tam; i++)
    {
        if(vetor[i] % 2 == 1)
            soma += vetor[i];
    }
    
    return soma;
}

int main()
{
    int tam, soma;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);

    int *vetor = alocarVetor(tam);

    preencherVetor(vetor, tam);
    exibirVetor(vetor, tam);

    soma = somarImpar(vetor, tam);
    printf("\nA soma dos ímpares é: %d", soma);

    liberarVetor(vetor);
    return 0;
}