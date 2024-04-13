#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100
#define QUANT_STR 6

int tamanho(char *str)
{
    int tam;

    for(tam = 0; str[tam] != '\0'; tam++);

    return tam;
}

char **alocarMatriz(int lin, int col)
{
    char **matriz = (char **) malloc(lin * sizeof(char *));
    
    if(!matriz)
    {
        printf("Erro! Não foi possível alocar a matriz");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < lin; i++)
    {
        matriz[i] = (char *) malloc(col * sizeof(char));
        if(!matriz[i])
        {
            printf("Erro! Não foi possível alocar a matriz");
            exit(EXIT_FAILURE);
        }
    }
    
    return matriz;
}

void liberarMatriz(int **matriz, int lin)
{
    for(int i = 0; i < lin; i++)
    {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    
    free(matriz);
    matriz = NULL;
}


int main()
{
    char **matriz = alocarMatriz(QUANT_STR, MAX_STR);

    for(int i = 0; i < QUANT_STR; i++)
    {
        printf("%dª string: ", i+1);
        scanf(" %[^\n]s", matriz[i]);

        if(tamanho(matriz[i]) < 4)
            i--;
    }

    int posMenor = 0, tamMenor = tamanho(matriz[0]);
    int posMaior = 0, tamMaior = tamanho(matriz[0]);

    for(int i = 1; i < QUANT_STR; i++)
    {
        if(tamanho(matriz[i]) > tamMaior)
        {
            tamMaior = tamanho(matriz[i]);
            posMaior = i;
        }

        if(tamanho(matriz[i]) < tamMenor)
        {
            tamMenor = tamanho(matriz[i]);
            posMenor = i;
        }
    }

    printf("\nA Menor string tem tamanho [%d] e é [%s]", tamMenor, matriz[posMenor]);
    printf("\nA Maior string tem tamanho [%d] e é [%s]\n", tamMaior, matriz[posMaior]);
    
    liberarMatriz(matriz, QUANT_STR);
    return 0;
}