#include <stdio.h>

// Faça um algoritmo que mostra a forma que o personagem "Cebolinha" da turma da Mônica fala,
// ou seja, troca a letra "R" por "L".
// Esse programa deve receber uma palavra de até 20 caracteres, realizar a referida troca e
// informar o número do(s) caractere(s) onde ocorrem(m) trocas, da seguinte forma:

// Informe uma palavra: errado
// Cebolinha falaria: ellado
// Houve troca nos caracteres: 2, 3

// Informe uma palavra: coracao
// Cebolinha falaria: colacao
// Houve troca nos caracteres: 3

// Informe uma palavra: amizade
// Cebolinha falaria: amizade
// Houve troca nos caracteres:

int main(void)
{
    char palavra[100];
    int letras[100], i, quant;

    printf("\nInforme uma palavra: ");
    gets(palavra);
    setbuf(stdin, NULL);

    quant = 0;
    for (i = 0; i < 100; i++)
    {
        if (palavra[i] == 'R')
        {
            palavra[i] = 'L';
            letras[quant] = i+1;
            quant++;
        }
        if (palavra[i] == 'r')
        {
            palavra[i] = 'l';
            letras[quant] = i+1;
            quant++;
        }
    }

    printf("Cebolinha falaria: %s", palavra);

    printf("\nHouve troca nos caracteres: ");
    for (i = 0; i < quant; i++)
    {
        if (i >= 1)
        {
            printf(", ");
        }

        printf("%d", letras[i]);
    }
    printf("\n\n");
    return 0;
}