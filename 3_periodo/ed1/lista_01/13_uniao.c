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

int *concatenar(int *v1, int n1, int *v2, int n2)
{
    int *v3 = alocarVetor(n1+n2);
    int i;

    for(i = 0; i < n1; i++)
        v3[i] = v1[i];

    for(int j = 0; j < n2; j++, i++)
        v3[i] = v2[j];
    
    return v3;
}

int main()
{
    int n1, n2;
    printf("Tamanhos dos vetores 1 e 2: ");
    scanf(" %d %d", &n1, &n2);

    int *v1 = alocarVetor(n1);
    int *v2 = alocarVetor(n2);

    preencherVetor(v1, n1);
    preencherVetor(v2, n2);

    int *v3 = concatenar(v1, n1, v2, n2);

    exibirVetor(v3, n1+n2);

    free(v1);
    free(v2);
    free(v3);
    return 0;
}