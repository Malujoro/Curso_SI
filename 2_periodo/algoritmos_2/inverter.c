#include <stdio.h>

int main()
{
	int num, inv = 0; // Variáveis do número e do inverso dele
    int i, quant = 1, aux = 0; // Variável de controle, "quantidade de casas" e uma auxiliar

    // Lê um número inteiro (Ex. 123)
    printf("\nDigite um número inteiro: ");
    scanf(" %d", &num);
    aux = num; // As operações serão realizadas com a auxiliar

    // "Conta" quantas casas tem o número digitado (Ex. 3 casas = 100 = centena)
    for(i = 10; i <= num; i *= 10)
        quant *= 10;

    // Começa as operações.
    for(i = 1; i <= num; i *= 10, quant /= 10)
    {
        // aux / quant = Divisão inteira entre o número auxiliar e o da maior casa  (Ex. 123 / 100 = 1) (Ex. 23 / 10 = 2) (Ex. 3 / 1 = 3)
        // aux / quant * i = Multiplica o resultado pela menor casa                 (Ex. 1 * 1) (Ex. 2 * 10 = 20) (Ex. 3 * 100 = 300)
        inv += aux / quant * i;
        // aux / quant * i = Multiplica o resultado pela maior casa                 (Ex. 1 * 100) (Ex. 2 * 10 = 20) (Ex. 3 * 1 = 3)
        // aux -= Subtrai o valor da maior casa, para continuar as contas           (Ex. 123 - 100 = 23) (Ex. 23 - 20 = 3) (Ex. 3 - 3 = 0)
        aux -= aux / quant * quant;

        //printf("\nQuantidade: [%d] | Aux = [%d]", quant, aux);
        //printf("\nInverso: [%d] | I = [%d]\n", inv, i);
    }
    printf("\nSeu número invertido é: [%d]\n", inv);
	return 0;
}