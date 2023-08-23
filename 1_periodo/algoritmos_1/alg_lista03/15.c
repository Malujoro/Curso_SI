#include <stdio.h>

/*
    Entrar com os sexos de várias pessoas (m ou f). Exibir a quantidade de
    pessoas do sexo masculino e a quantidade de pessoas do sexo feminino.
    O algoritmo termina quando é digitado um sexo @.
*/

int main(void)
{
    char sexo, letra;
    int quant_m = 0, quant_f = 0;

    do
    {
        printf("Sexo [m/f] (@ sai): ");
        scanf(" %c", &sexo);

        do
        {
            letra = getchar();
        } while (letra != '\n');

        if (sexo == 'm' || sexo == 'M')
            quant_m ++;
        else if (sexo == 'f' || sexo == 'F')
            quant_f ++;

    } while (sexo != '@');
    printf("\n%d pessoas do sexo Masculino", quant_m);
    printf("\n%d pessoas do sexo Feminino\n", quant_f);
    return 0;
}