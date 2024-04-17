#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} Ponto;

int **alocaMatriz(int linha, int largura)
{
    int **matriz = (int **) malloc(linha * sizeof(int *));
    
    if(!matriz)
        exit(EXIT_FAILURE);
    
    for(int i = 0; i < linha; i++)
    {
        matriz[i] = (int *) calloc(largura, sizeof(int));
        if(!matriz[i])
            exit(EXIT_FAILURE);
    }
    return matriz;
}

void exibeMatriz(int **matriz, int linha, int largura)
{
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < largura; j++)
            printf("%d ", matriz[i][j]);
        
        printf("\n");
    }
}

int calculaDistancia(Ponto centro, int x, int y)
{
    return sqrt(pow(x - centro.x, 2) + pow(y - centro.y, 2));
}

int main()
{
    // int lado = 30;
    int lado;

    printf("Digite o lado do quadrado: ");
    scanf(" %d", &lado);

    int **matriz = alocaMatriz(lado, lado);
    float raio = (float) lado/2;

    Ponto centro;

    centro.x = lado/2;
    centro.y = lado/2;

    for(int i = 0; i < lado; i++)
    {
        for(int j = 0; j < lado; j++)
        {
            if(calculaDistancia(centro, j, i) < raio)
                matriz[i][j] = 1;
        }
    }

    exibeMatriz(matriz, lado, lado);
    printf("\n");
    for(int i = 0; i < lado; i++)
        free(matriz[i]);
    
    free(matriz);
    return 0;
}