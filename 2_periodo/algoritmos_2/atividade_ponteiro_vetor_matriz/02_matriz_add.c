#include <stdio.h>
#include <stdlib.h>

void menu(int *op)
{
    printf("\n----------Menu----------");
    printf("\n[1] - Exibir matriz");
    printf("\n[2] - Adicionar/editar elemento");
    printf("\n[3] - Remover elemento (por valor)");
    printf("\n[4] - Remover elemento (por posição)");
    printf("\n[5] - Buscar elemento");
    printf("\n[0] - Sair do programa");
    printf("\nOpção: ");
    scanf(" %d", op);
}

void exibir_matriz(int **matriz, int lin, int col)
{
    int i, j;

    printf("\n");
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("%d \t", *(*(matriz + i) + j));
        printf("\n");
    }
}

void adicionar_elemento(int **matriz, int lin, int col, int numero)
{
    int linha, coluna;

    printf("Posição (Linha e Coluna): ");
    scanf(" %d %d", &linha, &coluna);

    if(linha >= 0 && linha < lin && coluna >= 0 && coluna < col)
    {
        *(*(matriz + linha) + coluna) = numero;
        printf("\nElemento adicionado\n");
    }
    else
        printf("\nPosição inválida!\n");
}

void preencher(int **matriz, int lin, int col)
{
    int i, j;

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf(" %d", (*(matriz + i) + j));
        }
    }
}

void remover_elemento_valor(int **matriz, int lin, int col, int num)
{
    int i, j;

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(num == *(*(matriz + i) + j))
            {
                *(*(matriz + i) + j) = 0;
                printf("\nElemento removido!\n");
                return;
            }
        }
    }
    printf("\nElemento não encontrado\n");
}

void remover_elemento_pos(int **matriz, int lin, int col, int linha, int coluna)
{
    if(linha >= 0 && linha < lin && coluna >= 0 && coluna < col)
    {
        *(*(matriz + linha) + coluna) = 0;
        printf("\nElemento removido!\n");
    }
    else
        printf("\nPosição inválida\n");
}

void buscar_elemento(int **matriz, int lin, int col, int num)
{
    int i, j;

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(num == matriz[i][j])
            {
                printf("\nElemento encontrado na posição [%d][%d]\n", i, j);
                return;
            }
        }
    }
    printf("\nElemento não encontrado!\n");
}

int main()
{
    int lin, col, i, op, num, linha, coluna;

    printf("Quantidade de Linhas: ");
    scanf(" %d", &lin);

    printf("Quantidade de Colunas: ");
    scanf(" %d", &col);

    int **matriz = (int **) malloc(lin * sizeof(int *));
    for(i = 0; i < lin; i++)
    {
        *(matriz + i) = (int *) malloc(col * sizeof(int));
    }

    printf("\n");
    preencher(matriz, lin, col);

    do
    {
        menu(&op);

        switch(op)
        {
            case 1:
                exibir_matriz(matriz, lin, col);
                break;

            case 2:
                printf("\nElemento a ser adicionado: ");
                scanf(" %d", &num);
                adicionar_elemento(matriz, lin, col, num);
                break;
                
            case 3:
                printf("\nElemento a ser removido: ");
                scanf(" %d", &num);
                remover_elemento_valor(matriz, lin, col, num);
                break;

            case 4:
                printf("\nPosição (Linha e Coluna): ");
                scanf(" %d %d", &linha, &coluna);
                remover_elemento_pos(matriz, lin, col, linha, coluna);
                break;

            case 5:
                printf("\nElemento a ser buscado: ");
                scanf(" %d", &num);
                buscar_elemento(matriz, lin, col, num);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;
        }
    }while(op != 0);

    for(i = 0; i < lin; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);
    
    return 0;
}