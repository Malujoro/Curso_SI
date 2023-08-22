#include <stdio.h>

// Criar um algoritmo que armazene os nomes e o sexo de 50 pessoas.
// Deverá ser listado primeiro os nomes de todos os homens seguido de sua quantidade
// e em seguida o nome das mulheres seguido de sua quantidade

int main(void)
{
    int quant = 3, i;
    char nomes[quant][100], sexo[quant];
    int quant_h = 0, quant_m = 0;

    for (i = 0; i < quant; i++)
    {
        printf("\n%dº nome: ", i+1);
        gets(nomes[i]);
        setbuf(stdin, NULL);

        printf("Sexo: [H/M] ");
        //gets(sexo[i]);
        scanf(" %c", &sexo[i]);
        getchar();
        setbuf(stdin, NULL);
    }

    printf("\nHomens:");
    for (i = 0; i < quant; i++)
    {
        if (sexo[i] == 'H' || sexo[i] == 'h')
        {
            printf("\n%s", nomes[i]);
            quant_h++;
        }
    }
    printf("\nQuantidade: %d\n", quant_h);

    printf("\nMulheres:");
    for (i = 0; i < quant; i++)
    {
        if (sexo[i] == 'M' || sexo[i] == 'm')
        {
            printf("\n%s", nomes[i]);
            quant_m++;
        }
    }
    printf("\nQuantidade: %d\n", quant_m);

    return 0;
}