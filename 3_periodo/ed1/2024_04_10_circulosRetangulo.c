#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} Ponto;

// Desenvolva uma solução que dada uma matriz de dimensões N x M, calcule o número máximo dos maiores círculos inscritos (tão quanto "desenhando" os círculos) neste objeto

int **alocarMatriz(int n, int m)
{
    int **matriz = (int **) calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++)
        matriz[i] = (int *) calloc(m, sizeof(int));

    return matriz;
}

void desalocarMatriz(int **matriz, int n)
{
    for(int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
}

void exibirMatriz(int **matriz, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

int calculaDistancia(Ponto centro, int x, int y)
{
    return sqrt(pow(centro.x - x, 2) + pow(centro.y - y, 2));
}

int main()
{
    int n, m;
    Ponto centro;

    while (1)
    {
        printf("Tamanho da matriz NxM: ");
        scanf(" %d %d", &n, &m);

        int quant, menorLado, maiorLado;
        float raio;
        if(n < m)
        {
            menorLado = n;
            maiorLado = m;
        }
        else
        {
            menorLado = m;
            maiorLado = n;
        }
        raio = (float) menorLado/2;
        quant = maiorLado / menorLado;

        int **matriz = alocarMatriz(n, m);

        printf("%d círculos podem ser inscritos\n", quant);
        for(int i = 0; i < quant; i++)
        {
            centro.x = menorLado/2 + (i * menorLado);
            centro.y = menorLado/2;
            for(int j = i * menorLado; j < (i+1) * menorLado && j < maiorLado; j++)
            {
                for(int k = 0; k < menorLado; k++)
                {
                    if(calculaDistancia(centro, j, k) < raio)
                    {
                        if(menorLado == n)
                            matriz[k][j] = 1;
                        else
                            matriz[j][k] = 1;
                    }
                }
            }

        }

        exibirMatriz(matriz, n, m);
        desalocarMatriz(matriz, n);
    }
    return 0;
}