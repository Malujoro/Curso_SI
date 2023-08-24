#include <stdio.h>

/*
    No dia da estreia do filme “Senhor dos Anéis”, uma grande emissora de
    TV realizou uma pesquisa logo após o encerramento do filme.
    Cada espectador respondeu a um questionário no qual constava sua idade e
    sua opinião em relação ao filme:
        excelente – 3;
        bom – 2;
        regular – 1.    
    Criar um algoritmo que receba a idade e a opinião de N espectadores,
    calcular e exibir:
    • a quantidade de pessoas em cada opinião;
    • a média da idade das pessoas em cada opinião;
    • a porcentagem de resposta para cada opinião.
*/

int main(void)
{
    int n, op, idade, i;
    float quant1 = 0, quant2 = 0, quant3 = 0;
    float media1 = 0, media2 = 0, media3 = 0;
    float porcent1 = 0, porcent2 = 0, porcent3 = 0;

    printf("Quantos espectadores? ");
    scanf(" %d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n%dª pessoa:", i+1);
        printf("\nIdade: ");
        scanf(" %d", &idade);

        printf("\nOpinião:");
        printf("\n3- excelente");
        printf("\n2- bom");
        printf("\n1- regular");
        printf("\nOpção: ");
        scanf(" %d", &op);

        switch (op)
        {
            case 1:
                quant1 ++;
                media1 += idade;
                break;
            
            case 2:
                quant2 ++;
                media2 += idade;
                break;

            case 3:
                quant3 ++;
                media3 += idade;
                break;

            default:
                printf("\nOpinião inválida!\n");
        }
    }
    if (quant1 > 0)
    {
        media1 /= quant1;
        porcent1 = quant1/n * 100;
    }
    if (quant2 > 0)
    {
        media2 /= quant2;
        porcent2 = quant2/n * 100;
    }
    if (quant3 > 0)
    {
        media3 /= quant3;
        porcent3 = quant3/n * 100;
    }
    printf("\n%.0f pessoas Regular", quant1);
    printf("\n%.0f pessoas Bom", quant2);
    printf("\n%.0f pessoas Excelente\n", quant3);

    printf("\nMédia de idade Regular: %.1f", media1);
    printf("\nMédia de idade Bom: %.1f", media2);
    printf("\nMédia de idade Excelente: %.1f\n", media3);

    printf("\nPorcentagem Regular: %.1f%%", porcent1);
    printf("\nPorcentagem Bom: %.1f%%", porcent2);
    printf("\nPorcentagem Excelente: %.1f%%\n", porcent3);
    return 0;
}