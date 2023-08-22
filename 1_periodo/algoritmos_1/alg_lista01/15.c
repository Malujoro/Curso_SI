#include <stdio.h>

int main(void)
{
    float sal_min, sal_pes, sal_quant;

    printf("Salário mínimo: R$");
    scanf("%f", &sal_min);
    
    printf("Salário pessoa: R$");
    scanf("%f", &sal_pes);

    sal_quant = sal_pes / sal_min;

    printf("Ele ganha %.1f salários mínimos", sal_quant);
    
    return 0;
}