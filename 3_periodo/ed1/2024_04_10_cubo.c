#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dado uma combinação de valores X, Y, |. Gere a esta matriz 3d a maior esfera inscrita ao objeto(cubo)

typedef struct
{
    int x;
    int y;
    int z;
} Ponto;

int ***alocaMatriz(int profundidade, int linha, int largura)
{
    int ***matriz = malloc(profundidade * sizeof(int **));

    for(int i = 0; i < profundidade; i++)
    {
        matriz[i] = malloc(linha * sizeof(int *));

        for(int j = 0; j < linha; j++)
            matriz[i][j] = calloc(largura, sizeof(int));
    }

    return matriz;
}

void exibirMatriz(int ***matriz, int profundidade, int linha, int largura)
{
    for(int i = 0; i < profundidade; i++)
    {
        for(int j = 0; j < linha; j++)
        {
            for(int k = 0; k < largura; k++)
                printf("%d ", matriz[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

void desalocarMatriz(int ***matriz, int profundidade, int linha)
{
    for(int i = 0; i < profundidade; i++)
    {
        for(int j = 0; j < linha; j++)
            free(matriz[i][j]);

        free(matriz[i]);
    }
    free(matriz);
}

int calculaDistancia(Ponto centro, int x, int y, int z)
{
    return sqrt(pow(x - centro.x, 2) + pow(y - centro.y, 2) + pow(z - centro.z, 2));
}

int main()
{
    int lado = 30;

    // printf("Digite o lado do cubo: ");
    // scanf(" %d", &lado);

    int ***matriz = alocaMatriz(lado, lado, lado);
    float raio = (float) lado/2; 

    Ponto centro;

    centro.x = lado/2;
    centro.y = lado/2;
    centro.z = lado/2;

    for(int i = 0; i < lado; i++)
    {
        for(int j = 0; j < lado; j++)
        {
            for(int k = 0; k < lado; k++)
            {
                if(calculaDistancia(centro, j, i, k) <= raio)
                    matriz[i][j][k] = 1;
            }
        }
    }

    exibirMatriz(matriz, lado, lado, lado);
    
    for(int i = 0; i < lado; i++)
        free(matriz[i]);
    
    free(matriz);
    return 0;
}