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

int **alocarMatriz(int lin, int col)
{
    int **matriz = (int **) malloc(lin * sizeof(int *));
    
    if(!matriz)
    {
        printf("Erro! Não foi possível alocar a matriz");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < lin; i++)
        matriz[i] = alocarVetor(col);
    
    return matriz;
}

void exibirMatriz(int **matriz, int lin, int col)
{
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void liberarMatriz(int **matriz, int lin)
{
    for(int i = 0; i < lin; i++)
        liberarVetor(matriz[i]);
    
    free(matriz);
    matriz = NULL;
}

int **multiplica(int *v1, int q1, int *v2, int q2)
{
    int **matriz = alocarMatriz(q1, q2);

    for(int i = 0; i < q1; i++)
    {
        for(int j = 0; j < q2; j++)
            matriz[i][j] = v1[i] * v2[j];
    }

    return matriz;
}

int main()
{
    int tam1, tam2;

    printf("Tamanhos dos vetores 1 e 2: ");
    scanf(" %d %d", &tam1, &tam2);

    int *vetor1 = alocarVetor(tam1);
    printf("\nVetor 1:\n");
    preencherVetor(vetor1, tam1);

    int *vetor2 = alocarVetor(tam2);
    printf("\nVetor 2:\n");
    preencherVetor(vetor2, tam2);

    int **matriz = multiplica(vetor1, tam1, vetor2, tam2);
    printf("\nMatriz:\n");
    exibirMatriz(matriz, tam1, tam2);

    liberarVetor(vetor1);
    liberarVetor(vetor2);
    liberarMatriz(matriz, tam1);

    return 0;
}