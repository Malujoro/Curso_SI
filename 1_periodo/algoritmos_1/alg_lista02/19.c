#include <stdio.h>

/*
    Dados o destino de um passageiro e se sua passagem será apenas de
    ida ou de ida e volta, informar o preço se sua passagem conforme a tabela
    abaixo:
*/

int main(void)
{
    int op1, op2;
    float valor;

    printf("\n[Destino]");
    printf("\n1- Região Norte");
    printf("\n2- Região Nordeste");
    printf("\n3- Região Centro-Oeste");
    printf("\n4- Região Sul");
    printf("\nOpção: ");
    scanf(" %d", &op1);

    printf("\n[Tipo de passagem]");
    printf("\n1- Somente ida");
    printf("\n2- Ida e volta");
    printf("\nOpção: ");
    scanf(" %d", &op2);

    switch(op1)
    {
        case 1:
            if (op2 == 1)
            {
                valor = 500;
            }
            else if (op2 == 2)
            {
                valor = 900;
            }
            break;

        case 2:
            if (op2 == 1)
            {
                valor = 350;
            }
            else if (op2 == 2)
            {
                valor = 650;
            }
            break;

        case 3:
            if (op2 == 1)
            {
                valor = 350;
            }
            else if (op2 == 2)
            {
                valor = 600;
            }
            break;

        case 4:
            if (op2 == 1)
            {
                valor = 300;
            }
            else if (op2 == 2)
            {
                valor = 550;
            }
            break;
    }
    printf("\nValor da passagem: R$%.2f\n", valor);
    return 0;
}