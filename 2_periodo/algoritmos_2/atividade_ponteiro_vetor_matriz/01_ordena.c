#include <stdio.h>
#include <stdlib.h>

void preencher(int *vetor, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", (vetor + i));
    }
}

void exibir(int *vetor, int tam)
{
    int i;

    printf("\n");
    for(i = 0; i < tam; i++)
        printf("%d ", *(vetor + i));

    printf("\n");
}

void ordena_crescente(int *vetor, int tam)
{
    int aux, i, j;
    int *menor;

    for(i = 0; i < tam-1; i++)
    {
        menor = (vetor + i);
        for(j = i+1; j < tam; j++)
        {
            if(*(vetor + j) < *menor)
                menor = (vetor + j);
        }
        aux = *(vetor + i);
        *(vetor + i) = *menor;
        *menor = aux;
    }
}

void ordena_decrescente(int *vetor, int tam)
{
    int aux, i, j;
    int *maior;

    for(i = 0; i < tam-1; i++)
    {
        maior = (vetor + i);
        for(j = i+1; j < tam; j++)
        {
            if(*(vetor + j) > *maior)
                maior = (vetor + j);
        }
        aux = *(vetor + i);
        *(vetor + i) = *maior;
        *maior = aux;
    }
}

int main()
{
    int tam;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);
    
    int *vetor = (int *) malloc(tam * sizeof(int));

    if(vetor == NULL)
        printf("\nNão foi possível alocar memória para um vetor desse tamanho!\n");
    else
    {
        preencher(vetor, tam);
        exibir(vetor, tam);

        ordena_crescente(vetor, tam);
        exibir(vetor, tam);

        ordena_decrescente(vetor, tam);
        exibir(vetor, tam);

        free(vetor);
    }
    
    return 0;
}