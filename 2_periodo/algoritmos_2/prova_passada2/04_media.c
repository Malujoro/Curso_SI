#include <stdio.h>
#include <stdlib.h>

void preencherVetor(float *vetor, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %f", &vetor[i]);
    }
}

void calculaMediaSubstitui(float *vetor, int tam)
{
    float media = 0;
    int i;

    for(i = 0; i < tam; i++)
        media += vetor[i];
    
    media /= tam;

    for(i = 0; i < tam; i++)
    {
        if(vetor[i] > media)
            vetor[i] = 0;
    }
}

void imprimeVetor(float *vetor, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
        printf("%.2f ", vetor[i]);
}

int main()
{
    int tam;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);

    float *vetor = (float *) malloc(tam * sizeof(float));

    preencherVetor(vetor, tam);
    calculaMediaSubstitui(vetor, tam);
    imprimeVetor(vetor, tam);

    free(vetor);

    return 0;
}