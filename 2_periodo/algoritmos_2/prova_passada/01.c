#include <stdio.h>

int main()
{
    float n1, n2, result = 0;
    char sinal;

    printf("\nPrimeiro número: ");
    scanf(" %f", &n1);

    printf("Segundo número: ");
    scanf(" %f", &n2);

    printf("Operação: ");
    scanf(" %c", &sinal);

    switch(sinal)
    {
        case '+':
            result = n1 + n2;
            break;

        case '-':
            result = n1 - n2;
            break;

        case '*':
        case 'x':
        case 'X':
            result = n1 * n2;
            break;

        case '/':
            result = n1 / n2;
            break;

        default:
            printf("\nOperação Inválida!!");
    }

    printf("\n%.2f %c %.2f = %.2f\n", n1, sinal, n2, result);

    return 0;
}