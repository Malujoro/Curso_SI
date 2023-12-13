#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void limpar_tela() // Função para limpar a tela baseado no sistema operacional do usuário
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void preencher(int **matriz, int lin, int col)
{
    int i, j;

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }
}

void exibir(int **matriz, int lin, int col)
{
    int i, j;

    limpar_tela();
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("%d \t", matriz[i][j]);
        
        printf("\n");
    }
    usleep(350000); // Função para "demorar" mais nas ações (dar tempo para ver a matriz)
}

void move_esquerda(int **matriz, int lin, int col)
{
    int i, j, aux;

    for(i = 0; i < lin; i++)
    {
        aux = matriz[i][0];
        for(j = 0; j < col-1; j++)
            matriz[i][j] = matriz[i][j+1];
        matriz[i][j] = aux;
    }
}

void move_baixo(int **matriz, int lin)
{
    int *aux;
    int i;

    aux = matriz[lin-1];
    for(i = lin-1; i > 0; i--)
        matriz[i] = matriz[i-1];
    matriz[i] = aux;
}

void move_direita(int **matriz, int lin, int col)
{
    int aux, i, j;

    for(i = 0; i < lin; i++)
    {
        aux = matriz[i][col-1];
        for(j = col-1; j > 0; j--)
            matriz[i][j] = matriz[i][j-1];
        matriz[i][j] = aux;
    }
}

void move_cima(int **matriz, int lin)
{
    int *aux;
    int i;

    aux = matriz[0];
    for(i = 0; i < lin-1; i++)
        matriz[i] = matriz[i+1];
    matriz[i] = aux;
}

void rodar(int **matriz, int lin, int col)
{
    int passo;
    do
    {
        // Move a coluna uma casa para a esquerda
        for(passo = 0; passo < col-1; passo++)
        {
            move_esquerda(matriz, lin, col);
            exibir(matriz, lin, col);
        }
        // Move a linha uma casa para baixo
        for(passo = 0; passo < lin-1; passo++)
        {
            move_baixo(matriz, lin);
            exibir(matriz, lin, col);
        }

        // Move a coluna uma casa para direita
        for(passo = 0; passo < col-1; passo++)
        {
            move_direita(matriz, lin, col);
            exibir(matriz, lin, col);
        }

        // Move a linha uma casa para cima
        for(passo = 0; passo < lin-1; passo++)
        {
            move_cima(matriz, lin);
            exibir(matriz, lin, col);
        }
    }while(1);
}

int main()
{
    int lin, col, i;

    printf("Linhas e Colunas: ");
    scanf(" %d %d", &lin, &col);

    int **matriz = (int **) malloc(lin * sizeof(int *));
    for(i = 0; i < lin; i++)
        matriz[i] = (int *) malloc(col * sizeof(int));

    preencher(matriz, lin, col);
    rodar(matriz, lin, col);

    for(i = 0; i < lin; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}