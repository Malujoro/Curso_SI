#include <stdio.h>

void reajusta(float *preco, float *reajuste)
{
    *reajuste = *preco * 0.20;
    *preco = *preco * 1.20;
}

void media(int *vetor, int tam, float *med)
{
    int i;
    *med = 0;

    for(i = 0; i < tam; i++)
    {
        printf("\nEndereço de Vetor[%d]: %p", i, &vetor[i]);
        *med += *(vetor + i);
    }
    *med /= tam;
}

void preencher(int vetor[], int tam)
{
    int i;

    for(i = 0; i < tam; i ++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }
}

void exibir(int vetor[], int tam)
{
    int i;

    printf("\n");
    for(i = 0; i < tam; i ++)
    {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}

int main()
{
    float med;
    int tam;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);

    int vetor[tam];

    preencher(vetor, tam);
    media(vetor, tam, &med);
    exibir(vetor, tam);

    printf("Média do vetor: %.2f\n", med);

    return 0;
}