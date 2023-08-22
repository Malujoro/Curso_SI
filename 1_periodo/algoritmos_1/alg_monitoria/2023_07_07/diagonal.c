#include <stdio.h>

//void diagonal1(int tamanho)

//void diagonal2(int tamanho)


void direita_inf(int tamanho)
{
    int i, j;

    for (i=0; i < tamanho; i++) // Repetição que faz as linhas
    {
        for (j=0; j < tamanho; j++) // Repetição que faz as colunas/caracteres
        {
            if (i + j >= tamanho)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

//void direita_sup(int tamanho)

//void esquerda_sup(int tamanho)

//void esquerda_inf(int tamanho)

int main(void)
{
    int tamanho=12, op;

    while (tamanho != 0)
    {
        printf("\n----------Menu----------\n");
        printf("\nTamanho da matriz [0 para sair]: ");
        setbuf(stdin, NULL);
        scanf("%d", &tamanho);

        printf("\n------------------------\n");

        if (tamanho == 0) 
        {
            printf("\nSaindo...\n\n");
        }
        else if (tamanho < 0)
        {
            printf("\nTamanho inválido!!\n\n");
        }
        else
        {
            //switch (op)
            direita_inf(tamanho);
            printf("------------------------\n");
        }
    }
    return 0;
}