#include <stdio.h>

int main(void)
{
    char op;
    float sal, porcento, novo_sal;

    printf("\nSalário: R$");
    scanf("%f", &sal);
    setbuf(stdin, NULL);

    printf("\nPlano A - 10%%\nPlano B - 15%%\nPlano C - 20%%");
    printf("\nOpção: ");
    scanf("%c", &op);

    if (op == 'a')
        op = 'A';
    else if (op == 'b')
        op = 'B';
    else if (op == 'c')
        op = 'C';

    switch (op)
    {
        case 'A':
            printf("\nAumento de 10%%");
            porcento = 10;
            break;
        case 'B':
            printf("\nAumento de 15%%");
            porcento = 15;
            break;
        case 'C':
            printf("\nAumento de 20%%");
            porcento = 20;
            break;
        default:
            printf("\nOpção inválida");
    }

    novo_sal = sal + (sal * (porcento/100));
    printf("\nNovo salário: R$ %.2f\n", novo_sal);

    return 0;
}