#include <stdio.h>

/*
    Dado o salário bruto de uma pessoa, exibir o desconto do INSS segundo
    a tabela abaixo:
*/

int main(void)
{
    float sal_bruto, porcent, sal_final;

    printf("Salário: R$");
    scanf(" %f", &sal_bruto);

    if (sal_bruto <= 600)
        porcent = 0;
    else if (sal_bruto <= 1200)
        porcent = 20;
    else if (sal_bruto <= 2000)
        porcent = 25;
    else
        porcent = 30;

    sal_final = sal_bruto - (sal_bruto * porcent / 100);

    printf("%.0f%% de desconto - Salário final: R$%.2f\n", porcent, sal_final);
    return 0;
}