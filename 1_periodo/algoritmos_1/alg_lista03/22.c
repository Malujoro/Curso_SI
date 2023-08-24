#include <stdio.h>

/*
    Dadas a idade e peso de 20 pessoas, exibir a média aritmética dos pesos
    das pessoas da mesma faixa etária.
    As faixas etárias são:
    de 1 a 10 anos,
    de 11 a 20 anos,
    de 21 a 30 anos,
    maiores de 30 anos.
*/

int main(void)
{
    int idade, quant = 20, i;
    float peso;
    int quant_1_10 = 0, quant_11_20 = 0, quant_21_30 = 0, quant_31 = 0;
    float media_1_10 = 0, media_11_20 = 0, media_21_30 = 0, media_31 = 0;

    for (i = 0; i < quant; i++)
    {
        printf("\n%dª pessoa:", i+1);
        printf("\nPeso [kg]: ");
        scanf(" %f", &peso);
        printf("Idade: ");
        scanf(" %d", &idade);

        if (idade >= 1 && idade <= 10)
        {
            quant_1_10++;
            media_1_10 += peso;
        }
        else if (idade >= 11 && idade <= 20)
        {
            quant_11_20++;
            media_11_20 += peso;
        }
        else if (idade >= 21 && idade <= 30)
        {            
            quant_21_30++;
            media_21_30 += peso;
        }
        else if (idade >= 31)
        {
            quant_31++;
            media_31 += peso;
        }
    }

    if (quant_1_10 > 0)
        media_1_10 /= quant_1_10;

    if (quant_11_20 > 0)
        media_11_20 /= quant_11_20;

    if (quant_21_30 > 0)
        media_21_30 /= quant_21_30;

    if (quant_31 > 0)
        media_31 /= quant_31;

    printf("\nMédias de peso:");
    printf("\nIdades de 1 a 10 anos: %.1f kg", media_1_10);
    printf("\nIdades de 11 a 20 anos: %.1f kg", media_11_20);
    printf("\nIdades de 21 a 30 anos: %.1f kg", media_21_30);
    printf("\nIdades maiores de 30 anos: %.1f kg\n", media_31);
    return 0;
}