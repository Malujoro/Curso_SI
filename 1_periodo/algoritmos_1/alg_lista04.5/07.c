#include <stdio.h>

// Faça um programa que armazene em um vetor 10 números inteiros entre 1 e 20 
// informados pelo usuário e imprima um histograma desses números de acordo
// com a seguinte formatação:
//      Elemento     Valor      Histograma
//             0     2          **
//             1     4          ****
//             2     6          ******
//             .     .          .
//             .     .          .
//             .     .          .
//             9     10         **********

int main(void)
{
    int quant = 10, i, cont;
    int vetor[quant], num;
    
    for (i = 0; i < quant; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &num);

        if (num >= 1 && num <= 20)
        {
            vetor[i] = num;
        }
        else
        {
            i--;
        }
    }


    printf("\nElemento \t Valor \t \t Histograma");    
    for (i = 0; i < quant; i++)
    {
        printf("\n%d \t \t %d \t \t ", i, vetor[i]);

        for (cont = 0; cont < vetor[i]; cont++)
        {
            printf("*");
        }
    }
    return 0;
}