#include <stdio.h>

/*
    Dados os salários bruto de 20 pessoas, exibir o desconto do INSS para
    cada pessoa segundo a tabela abaixo:
*/

int main(void)
{
    float sal, porcent, desc;
    int quant = 5, i;
    
    for (i = 0; i < quant; i++)
    {
        printf("\n%dº salário: R$", i+1);
        scanf(" %f", &sal);

        if (sal <= 600)
            porcent = 0;
        else if (sal <= 1200)
            porcent = 20;
        else if (sal <= 2000)
            porcent = 25;
        else
            porcent = 30;
        
        desc = sal * porcent / 100;

        printf("Desconto de %.0f%% - R$%.2f\n", porcent, desc);
    }
    return 0;
}