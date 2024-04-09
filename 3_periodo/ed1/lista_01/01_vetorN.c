#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%dº elemento: ", i+1);
        scanf(" %d", &vetor[i]);
    }
}

int main()
{
    int n;

    printf("Valor de N (tamanho do vetor): ");
    scanf(" %d", &n);

    int *vetor = (int *) malloc(n * sizeof(int));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }
    
    preencheVetor(vetor, n);

    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    free(vetor);
    return 0;
}