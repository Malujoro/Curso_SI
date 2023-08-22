#include <stdio.h>

// 100 kw custam 1/7 do salário mínimo
// Entrada: 
//      salário mínimo
//      kw gastos
// Exibir: 
//      valor de cada kw
//      valor da conta
//      novo valor após desconto de 10%
int main(void)
{
    float sal_min, kw_valor, conta_valor, conta_10desc;
    int kw_gasto;

    printf("Salário mínimo: R$");
    scanf("%f", &sal_min);

    printf("Kws gastos: ");
    scanf("%d", &kw_gasto);

    kw_valor = (sal_min/7) / 100;
    conta_valor = kw_valor * kw_gasto;
    conta_10desc = conta_valor * 0.90;

    printf("\nValor de cada Kw: R$%.2f", kw_valor);
    printf("\nValor da conta: R$%.2f", conta_valor);
    printf("\nValor da conta com 10%% de desconto: R$%.2f", conta_10desc);

    return 0;
}