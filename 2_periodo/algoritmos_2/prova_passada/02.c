#include <stdio.h>

int main()
{
    float n1, n2;
    int i = 1;
    char op;

    do
    {
        printf("\n%dª execução (máximo de 5):\n", i);
        
        printf("\nPrimeiro número: ");
        scanf(" %f", &n1);

        printf("Segundo número: ");
        scanf(" %f", &n2);

        printf("\nSoma: %.1f", n1 + n2);
        printf("\nSubtração: %.1f", n1 - n2);
        printf("\nMultiplicação: %.1f", n1 * n2);
        printf("\nDivisão: %.1f\n", n1 / n2);
        
        if(i < 5)
        {
            printf("\nContinuar (s/n)? ");
            scanf(" %c", &op);
        }
        i++;
    }while((op != 'n' && op != 'N') && i <= 5);
    
    return 0;
}