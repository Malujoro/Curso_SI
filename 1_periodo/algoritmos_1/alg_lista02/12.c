#include <stdio.h>

/*
    Um comerciante comprou um produto e deseja revendê-lo com um lucro
    de 45% se o valor de compra for menor do que R$ 20,00;
    caso contrário, o lucro será de 30%.
    Entrar com o valor de compra do produto e exibir seu valor de venda.
*/

int main(void)
{
    float produto, porcent, venda;

    printf("Preço do produto: R$");
    scanf(" %f", &produto);

    if (produto < 20)
        porcent = 45;
    else
        porcent = 30;

    venda = (produto * porcent / 100) + produto;

    printf("O preço de venda será R$%.2f\n", venda);

    return 0;
}