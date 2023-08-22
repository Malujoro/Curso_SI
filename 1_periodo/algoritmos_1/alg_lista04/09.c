#include <stdio.h>

// Armazenar nome e salário de 30 pessoas.
// Reajustar o salário de todos os funcionários em 8%.
// Exibir uma lista enumerada dos funcionários com nome e novo salário

int main(void)
{
    int quant = 30, i;
    char nomes[quant][100];
    // 0 - Salário 
    // 1 - Salário com aumento
    float salario[quant][2];
    
    for (i = 0; i < quant; i++)
    {
        printf("\n%dº nome: ", i+1);
        gets(nomes[i]);
        setbuf(stdin, NULL);

        printf("Salário: R$");
        scanf("%f", &salario[i][0]);
        setbuf(stdin, NULL);

        salario[i][1] = salario[i][0] * 1.08; // Aumento de 8%
    }

    printf("\nNúmero \t Nome \t Salário");
    for (i = 0; i < quant; i++)
    {
        printf("\n%d \t %s \t %.2f", i+1, nomes[i], salario[i][1]);
    }
    return 0;
}