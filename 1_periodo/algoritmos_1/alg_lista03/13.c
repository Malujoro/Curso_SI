#include <stdio.h>

/*
    Fazer um algoritmo que dados dois números e um caractere.
    O caractere será uma opção escolhida pelo usuário de como
    manipular os dois números.
    O algoritmo deverá exibir o menu de opções abaixo:
    --------------------------------------------------
    MENU
    --------------------------------------------------
    A – Maior Número
    B – Menor Número
    C – Média Aritmética
    D – Finalizar
*/

int main(void)
{
    int n1, n2;
    char op, letra;

    printf("1º Número: ");
    scanf(" %d", &n1);

    printf("2º Número: ");
    scanf(" %d", &n2);

    do
    {
        printf("\n--------------------------------------------------");
        printf("\nMENU");
        printf("\n--------------------------------------------------");
        printf("\nA – Maior Número");
        printf("\nB – Menor Número");
        printf("\nC – Média Aritmética");
        printf("\nD – Finalizar");
        printf("\nOpção: ");
        scanf(" %c", &op);
        do
        {
            letra = getchar();
        } while (letra != '\n');

        if (op == 'a')
            op = 'A';

        else if (op == 'b')
            op = 'B';

        else if (op == 'c')
            op = 'C';

        else if (op == 'd')
            op = 'D';

        switch (op)
        {
            case 'A':
                printf("\nMaior número: ");
                if (n1 > n2)
                    printf("%d\n", n1);
                else if (n2 > n1)
                    printf("%d\n", n2);
                else
                    printf("%d (são iguais)", n1);
                break;

            case 'B':
                printf("\nMenor número: ");
                if (n1 < n2)
                    printf("%d\n", n1);
                else if (n2 < n1)
                    printf("%d\n", n2);
                else
                    printf("%d (são iguais)", n1);
                break;

            case 'C':
                printf("\nMédia: %.1f\n", (n1+n2)/2.0);
                break;

            case 'D':
                printf("\nFinalizando sessão...\n");
                break;
            
            default:
                printf("\nOpção inválida!\n");
        }
    } while (op != 'D');
    return 0;
}