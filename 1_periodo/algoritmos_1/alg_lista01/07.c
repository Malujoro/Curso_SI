#include <stdio.h>

int main(void)
{
    float saldo, saldo_aumento, saldo_desconto;

    printf("Saldo: R$");
    scanf("%f", &saldo);

    saldo_aumento = saldo * 1.10;
    saldo_desconto = saldo * 0.90;

    printf("\nSaldo com aumento: R$%.2f", saldo_aumento);
    printf("\nSaldo com desconto: R$%.2f\n",  saldo_desconto);

    return 0;
}