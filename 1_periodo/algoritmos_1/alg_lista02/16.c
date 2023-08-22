#include <stdio.h>

/*
    Faça um algoritmo que informe a quantidade total de calorias em uma
    refeição a partir da escolha do usuário que deverá informar o prato, a
    sobremesa e a bebida, conforme a tabela a seguir:
*/

int main(void)
{
    int op, total = 0;

    printf("\n[Prato]");
    printf("\n1- Vegetariano: 180cal");
    printf("\n2- Peixe: 230cal");
    printf("\n3- Frango: 250cal");
    printf("\n4- Carne: 350cal");
    printf("\nOpção: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            total += 180;
            break;
        case 2:
            total += 230;
            break;
        case 3:
            total += 250;
            break;
        case 4:
            total += 350;
            break;
    }


    printf("\n[Sobremesa]");
    printf("\n1- Abacaxi: 75cal");
    printf("\n2- Sorvete diet: 110cal");
    printf("\n3- Mousse diet: 170cal");
    printf("\n4- Mousse de chocolate: 200cal");
    printf("\nOpção: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            total += 75;
            break;
        case 2:
            total += 110;
            break;
        case 3:
            total += 170;
            break;
        case 4:
            total += 200;
            break;
    }

    printf("\n[Bebida]");
    printf("\n1- Chá: 20cal");
    printf("\n2- Suco de laranja: 70cal");
    printf("\n3- Suco de melão: 100cal");
    printf("\n4- Refrigerante diet: 65cal");
    printf("\nOpção: ");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            total += 20;
            break;
        case 2:
            total += 70;
            break;
        case 3:
            total += 100;
            break;
        case 4:
            total += 65;
            break;
    }

    printf("Total de calorias: %dcal\n", total);
    return 0;
}