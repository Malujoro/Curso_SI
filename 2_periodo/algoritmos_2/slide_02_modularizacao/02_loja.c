#include <stdio.h>

int menu()
{
    int op;

    printf("\nOpções de pagamento:");
    printf("\n[1] - a vista com 10%% de desconto");
    printf("\n[2] - em duas vezes (preço da etiqueta)");
    printf("\n[3] - de 3 até 10 vezes com 3%% de juros ao mês (somente para compras acima de R$100,00)");
    printf("\nOpção: ");
    scanf(" %d", &op);
    return op;
}

void vista(float preco, float desc)
{
    preco -= preco * desc/100;
    printf("\nO pagamento a vista ficará R$%.2f reais\n", preco);
}

void duas_vezes(float preco)
{
    float prestacoes;

    prestacoes = preco/2;
    printf("\n2 prestações de R$%.2f totalizando R$%.2f\n", prestacoes, preco)
;}

void parcelado(float preco)
{
    int quant_parc;
    float parc, total;

    if (preco <= 100)
        printf("\nA compra não pode ser parcelada, pois deve ser maior que R$100.00\n");
    else
    {
        printf("\nQuantidade de parcelas? [de 3 a 10] ");
        scanf(" %d", &quant_parc);
        if(quant_parc < 3 || quant_parc > 10)
            printf("\nQuantidade inválida de parcelas!!\n");
        else
        {
            parc = (preco/quant_parc) * 1.03;
            total = parc * quant_parc;
            printf("\n%d parcelas de R$%.2f totalizando R$%.2f\n", quant_parc, parc, total); 
        }
    }
}

int main()
{
    float total_gasto;
    int op;

    printf("Total gasto na loja: ");
    scanf(" %f", &total_gasto);

    op = menu();
    switch(op)
    {
        case 1:
            vista(total_gasto, 10);
            break;

        case 2:
            duas_vezes(total_gasto);
            break;

        case 3:
            parcelado(total_gasto);
            break;

        default:
            printf("\nOpção inválida\n");
    }
    
    return 0;
}