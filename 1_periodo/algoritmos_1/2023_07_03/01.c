#include <stdio.h>

int main(void)
{
    float valor, porcento, valor_total;
    int op=1;

    while (op != 0)
    {
        valor = 0;
        porcento = 0;

        printf("================================");
        printf("\nValor: R$");
        setbuf(stdin, NULL);
        scanf("%f", &valor);


        printf("\nForma de pagamento: \n1- A vista - 15%% de desconto\n2- Cartão Débito - 10%% de desconto\n3- Cartão de Crédito - sem desconto\n4- A prazo - 10%% de acréscimo\n0- Sair\nOpção: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);


        switch (op)
        {
            case 0:
            {
                printf("\nSaindo...\n");
                break;
            }
            case 1:
            {
                porcento = -15;
                break;
            }
            case 2:
            {
                porcento = -10;
                break;
            }
            case 3:
            {
                porcento = 0;
                break;
            }
            case 4:
            {
                porcento = 10;
                break;
            }
            default:
            {
                printf("\nOpção inválida...\n");
            }
        }

        if (1 <= op && op <= 4)
        {
            valor_total = valor + (valor * (porcento/100));
            printf("\nValor a ser pago: R$%.2f\n", valor_total);
        }
    }
    return 0;
}