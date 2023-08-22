#include <stdio.h>

int main(void)
{
    float n1, n2;
    char op;

    do
    {
        printf("\n===========================\n");
        
        printf("1º Número: ");
        setbuf(stdin, NULL);
        scanf("%f", &n1);

        printf("2º Número: ");
        setbuf(stdin, NULL);
        scanf("%f", &n2);

        printf("-----------------------");
        printf("\nMENU");
        printf("\n-----------------------");
        printf("\nA - Maior número\nB - Menor número\nC - Média Aritmética\nD - Finalizar\nOpção: ");
        setbuf(stdin, NULL);
        scanf("%c", &op);

        if (op == 'a')
        {
            op = 'A';
        }
        else if (op == 'b')
        {
            op = 'B';
        }
        else if (op == 'c')
        {
            op = 'C';
        }
        else if (op == 'd')
        {
            op = 'D';
        }

        switch (op)
        {
            case 'A':
            {
                if (n1 >= n2)
                {
                    printf("\nMaior: %.2f", n1);
                }
                else if (n2 > n1)
                {
                    printf("\nMaior: %.2f", n2);
                }
                break;
            }
            case 'B':
            {
                if (n1 <= n2)
                {
                    printf("\nMenor: %.2f", n1);
                }
                else if (n2 > n1)
                {
                    printf("\nMenor: %.2f", n2);
                }
                break;
            }
            case 'C':
            {
                printf("Média: %.2f", (n1+n2)/2);
                break;
            }
            case 'D':
            {
                printf("\nSaindo...\n");
                break;
            }
        }
    } while (op != 'D');
    return 0;
}