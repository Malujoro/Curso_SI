#include <stdio.h>

/*
    A prefeitura permitiu empréstimos a seus funcionários onde
    o valor máximo da prestação não pode ultrapassar 30% do salário.
    Dados os valores do salário, a quantidade de prestações do pagamento
    do empréstimo e a taxa de juros cobrada no empréstimo;
    informa se o empréstimo é permitido ou não
*/

int main(void)
{
    float salario, taxa, valor_prest, valor_emprest;
    int quant_prest;

    printf("Valor empréstimo: R$");
    scanf(" %f", &valor_emprest);

    printf("Salário: R$");
    scanf(" %f", &salario);

    printf("Prestações (meses): ");
    scanf(" %d", &quant_prest);

    printf("Taxa [%%]: ");
    scanf(" %f", &taxa);

    valor_prest = ((valor_emprest * taxa / 100) + valor_emprest) / quant_prest;
    printf("\n%d prestações de R$%.2f\n", quant_prest, valor_prest);
    if (valor_prest > (salario * 0.30))
    {
        printf("\nEmpréstimo negado\n");
    }
    else
    {
        printf("\nEmpréstimo permitido");
        printf("\n%d prestações de R$%.2f\n", quant_prest, valor_prest);
    }
    
    return 0;
}