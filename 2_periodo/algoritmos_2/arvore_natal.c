#include <stdio.h>
#include <stdlib.h>

void preencher_matriz(char **matriz, int lin, int col, int tam_tronco, char ch)
{
    int i, j, ponto = col/2;
    
    // Preenche árvore
    for(i = 0; i < lin-tam_tronco; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(j < (ponto - i) || j > (ponto + i))
                matriz[i][j] = ' ';
            else
                matriz[i][j] = ch;
        }
    }
    
    // Preenche tronco
    for(; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(j < ponto-tam_tronco || j > ponto+tam_tronco || lin-tam_tronco <= 2)
                matriz[i][j] = ' ';
            else
                matriz[i][j] = '_';
        }
        if(i > 2)
        {
            matriz[i][ponto-tam_tronco] = '|';
            matriz[i][ponto+tam_tronco] = '|';
        }
        else
            matriz[i][ponto] = '|';
    }
}

void exibir_matriz(char **matriz, int lin)
{
    int i;

    for(i = 0; i < lin; i++)
        printf("%s\n", matriz[i]);
}

int main()
{
    int lin, col, i, tam_tronco = 1;
    char simbolo;

    printf("Símbolo: ");
    scanf(" %c", &simbolo);

    printf("Quantidade de Linhas: ");
    scanf(" %d", &lin);
    
    
    col = lin*2 +1;

    tam_tronco += lin / 15;
    lin += tam_tronco;
    char **matriz = (char **) malloc(lin * sizeof(char *));
    for(i = 0; i < lin; i++)
        matriz[i] = (char *) malloc(col * sizeof(char));

    preencher_matriz(matriz, lin, col, tam_tronco, simbolo);
    exibir_matriz(matriz, lin);

    return 0;
}