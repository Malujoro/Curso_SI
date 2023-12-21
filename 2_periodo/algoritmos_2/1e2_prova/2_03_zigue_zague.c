#include <stdio.h>
#include <stdlib.h>

void exibir_matriz(int **matriz, int tam)
{
    int i, j;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
           printf("%d \t", matriz[i][j]);
        printf("\n");
    }
}

int main()
{
    int tam, quant = 0, soma = 0;
    int i, j;

    printf("Dimensão da matriz: ");
    scanf(" %d", &tam);

    int **matriz = (int **) malloc(tam * sizeof(int *));
    for(i = 0; i < tam; i++)
        matriz[i] = (int *) malloc(tam * sizeof(int));

    int teste = 1;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            // printf("Matriz[%d][%d]: ", i, j);
            // scanf(" %d", &matriz[i][j]);
            matriz[i][j] = teste;
            teste++;
        }
    }

    exibir_matriz(matriz, tam);

    for(i = 1; i <= tam; i++)
        soma += i;

    int *vetor = (int *) malloc(tam * tam * sizeof(int));

    i = 0, j = 0;
    vetor[i] = matriz[i][j];
    quant++;
    
    // while(i != tam-1 || j != tam-1)
    while((i < tam-1 || j < tam-1) && quant < tam*tam)
    {
        if(j < tam-1 && quant < soma)
        {
            j++;
            for(; j > 0 && i < tam-1; j--, i++)
            {
                vetor[quant] = matriz[i][j];
                quant++;
            }
            vetor[quant] = matriz[i][j];
            quant++;
        }

        if(i < tam-1 && quant < soma)
        {
            i++;
            for(; i > 0 && j < tam-1; j++, i--)
            {
                vetor[quant] = matriz[i][j];
                quant++;
            }
            vetor[quant] = matriz[i][j];
            quant++;
        }

        if(i < tam-1 && quant >= soma)
        {
            i++;
            for(; j > 0 && i < tam-1; j--, i++)
            {
                vetor[quant] = matriz[i][j];
                quant++;
            }
            vetor[quant] = matriz[i][j];
            quant++;
        }

        if(j < tam-1 && quant >= soma)
        {
            j++;
            for(; i > 0 && j < tam-1; j++, i--)
            {
                vetor[quant] = matriz[i][j];
                quant++;
            }
            vetor[quant] = matriz[i][j];
            quant++;
        }
    }

    for(i = 0; i < quant; i++)
        printf("%d ", vetor[i]);

    free(vetor);
    for(i = 0; i < tam; i++)
        free(matriz[i]);
    free(matriz);
    
    return 0;
}