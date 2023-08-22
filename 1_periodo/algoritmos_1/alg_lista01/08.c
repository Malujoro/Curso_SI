#include <stdio.h>

int main(void)
{
    float deposito, taxa, val_rend, val_tot;

    printf("Depósito: R$");
    scanf("%f", &deposito);

    printf("Taxa de juros [%%]:");
    scanf("%f", &taxa);

    val_rend = deposito * (taxa/100);
    val_tot = deposito + val_rend;

    printf("\nValor do rendimento: R$%.2f", val_rend);
    printf("\nValor total: R$%.2f", val_tot);

    return 0;
}