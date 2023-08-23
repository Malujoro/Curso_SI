#include <stdio.h>

/*
    Entrar com o nome, idade e sexo de 20 pessoas. Exibir o nome da pessoa
    se ela for do sexo masculino e tiver mais que 21 anos.
*/

int main(void)
{
    char nome[100], sexo[10];
    int idade, quant = 3, i;

    for (i = 0; i < quant; i++)
    {    
        printf("\n%dª Pessoa\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]s", nome);

        printf("Idade: ");
        scanf(" %d", &idade);

        do
        {
            printf("Sexo [m/f]: ");
            scanf(" %[^\n]s", sexo);
            if (sexo[0] == 'M')
            {
                sexo[0] = 'm';
            }
            else if (sexo[0] == 'F')
            {
                sexo[0] = 'f';
            }
        } while (sexo[0] != 'm' && sexo[0] != 'f');

        if (sexo[0] == 'm' && idade >= 21)
        {
            printf("\nHomem maior de 21 [%s]\n", nome);
        }
    }
    return 0;
}