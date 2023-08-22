#include <stdio.h>

int menu()
{
    int op;

    printf("\n----------Menu----------");
    printf("\n1 - Triângulo\n2 - Quadrado\n3 - Retângulo\n0 - Sair\n\nResposta: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);
    
    return op;
}

void triangulo(int altura)
{
    int i, j; // Linhas e Colunas

    for (i=0; i < altura; i++)
    {
        for (j=0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void quadrado(int lado)
{
    int i, j; // Linhas e Colunas
    
    for (i=0; i < lado; i++)
    {
        for (j=0; j < lado; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void retangulo(int largura, int altura)
{
    int i, j; // Linhas e Colunas

    for (i=0; i < altura; i++)
    {
        for (j=0; j < largura; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main(void)
{
    int op=1, altura, largura;

    while (op != 0)
    {
        op = menu();

        switch (op)
        {
            case 1: // Triângulo
            {
                printf("\nAltura do Triãngulo: ");
                scanf("%d", &altura);
                printf("\n");
                triangulo(altura);
                break;
            }
            case 2: // Quadrado
            {
                printf("\nTamanho do Quadrado: ");
                scanf("%d", &altura);
                printf("\n");
                quadrado(altura);
                break;
            }
            case 3: // Retângulo
            {
                printf("\nLargura e Altura do Retângulo: ");
                scanf("%d %d", &largura, &altura);
                printf("\n");
                retangulo(largura, altura);
                break;
            }
            case 0:
            {
                printf("\nSaindo...\n");
                break;
            }
            default:
            {
                printf("\nOpção inválida!!\n");
            }
            
        }
    }
    return 0;
}