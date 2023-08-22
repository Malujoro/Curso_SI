#include <stdio.h>

//  Faça um programa que leia duas matrizes 3x3 com valores reais.
//  Ofereça ao usuário um menu de opções:
//      Somar as duas matrizes
//      Subtrair as 2 matrizes
//      Multiplicar as matrizes
//      Imprimir as matrizes

int main(void)
{
    int op, tam = 3, l, c;
    float matriz[tam][tam], matriz2[tam][tam];

    printf("\nMatriz 1:\n");
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            printf("Número (%d, %d): ", l+1, c+1);
            scanf("%f", &matriz[l][c]);
        }
    }
    
    printf("\nMatriz 2:\n");
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            printf("Número (%d, %d): ", l+1, c+1);
            scanf("%f", &matriz2[l][c]);
        }
    }

    do
    {
        printf("\n \t Menu \t ");
        printf("\n1 - Somar as matrizes\n2 - Subtrair as matrizes\n3 - Multiplicar as matrizes\n4 - Imprimir as matrizes\n0 - Sair\n");
        printf("\nOpção: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("\nSoma das matrizes:\n");
                for (l = 0; l < tam; l++)
                {
                    for (c = 0; c < tam; c++)
                    {
                        printf("%.1f \t", matriz[l][c]+matriz2[l][c]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                int op_sub;
                do 
                {
                    printf("\nSubtração das matrizes:\n");
                    printf("1 - [Matriz 1 - Matriz 2]\n2 - [Matriz 2 - Matriz 1]\n");
                    printf("\nOpção: ");
                    scanf("%d", &op_sub);
                    switch (op_sub)
                    {
                        case 1:
                            printf("\n(Matriz 1 - Matriz 2):\n");
                            for (l = 0; l < tam; l++)
                            {
                                for (c = 0; c < tam; c++)
                                {
                                    printf("%.1f \t", matriz[l][c]-matriz2[l][c]);
                                }
                                printf("\n");
                            }
                            break;
                        
                        case 2:
                            printf("\n(Matriz 2 - Matriz 1):\n");
                            for (l = 0; l < tam; l++)
                            {
                                for (c = 0; c < tam; c++)
                                {
                                    printf("%.1f \t", matriz2[l][c]-matriz[l][c]);
                                }
                                printf("\n");
                            }
                            break;

                        default:
                            printf("\nOpção Inválida!!\n");
                    }
                } while (op_sub != 1 && op_sub != 2);
                break;
            case 3:
                printf("\nMultiplicação das matrizes:\n");
                for (l = 0; l < tam; l++)
                {
                    for (c = 0; c < tam; c++)
                    {
                        printf("%.1f \t", matriz[l][c]*matriz2[l][c]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("\n\tMatriz 1\t| \t \tMatriz2\n");
                for (l = 0; l < tam; l++)
                {
                    for (c = 0; c < tam; c++)
                    {
                        printf("[%.1f] \t", matriz[l][c]);
                    }
                    printf("| \t");
                    for (c = 0; c < tam; c++)
                    {
                        printf("[%.1f] \t", matriz2[l][c]);
                    }
                    printf("\n");
                }
                
                
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("Opção Inválida!!");
        }
    } while (op != 0);
    return 0;
}