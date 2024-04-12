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
    printf("\n");
}

void liberarVetor(int *vetor)
{
    free(vetor);
    vetor = NULL;
}

int *uniao(int *v1, int q1, int *v2, int q2)
{
    int *v3 = alocarVetor(q1 + q2);
    
    for(int i = 0; i < q1; i++)
        v3[i] = v1[i];
    
    for(int pos = q1, i = 0; i < q2; i++, pos++)
        v3[pos] = v2[i];
    
    return v3;
}

int main()
{
    int n, n2;

    printf("Tamanho do vetor 1: ");
    scanf(" %d", &n);

    int *vetor = alocarVetor(n);
    preencherVetor(vetor, n);

    printf("Tamanho do vetor 2: ");
    scanf(" %d", &n2);

    int *vetor2 = alocarVetor(n2);
    preencherVetor(vetor2, n2);

    int *vetor3 = uniao(vetor, n, vetor2, n2);

    exibirVetor(vetor, n);

    exibirVetor(vetor2, n2);
    exibirVetor(vetor3, n + n2);

    liberarVetor(vetor);
    liberarVetor(vetor2);
    liberarVetor(vetor3);

    return 0;
}