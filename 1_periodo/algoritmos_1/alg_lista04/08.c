#include <stdio.h>


// Criar um algoritmo que entre com o nome e a idade de 20 pessoas e armazene em
// um vetor os nomes das pesssoas que são maiores de idade

int main(void)
{
    int quant = 20;
    char nome[100], vetor[quant][100];
    int idade, i, j, quant_maior=0;

    for (i = 0; i < quant; i++)
    {
        printf("\n%dº Nome: ", i+1);
        gets(nome);
        setbuf(stdin, NULL);

        printf("%dª Idade: ", i+1);
        scanf("%d", &idade);
        setbuf(stdin, NULL);

        if (idade >= 18)
        {
            for (j = 0; j < 100; j++)
            {
                vetor[quant_maior][j] = nome[j];
            }

            quant_maior ++;
        }
    }

    printf("Pessoas maiores de idade:");
    for (i = 0; i < quant_maior; i++)
    {
        printf("\n%s", vetor[i]);
    }

    return 0;
}