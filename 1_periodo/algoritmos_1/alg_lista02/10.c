#include <stdio.h>

/*
    Dadas as quatro notas de um aluno, exibir a média das notas e a situação do aluno:
    aprovado, de final ou reprovado
*/

int main(void)
{
    float n1, n2, n3, n4, media;

    printf("Nota 1: ");
    scanf(" %f", &n1);

    printf("Nota 2: ");
    scanf(" %f", &n2);

    printf("Nota 3: ");
    scanf(" %f", &n3);

    printf("Nota 4: ");
    scanf(" %f", &n4);

    media = (n1 + n2 + n3 + n4) / 4;

    printf("\nMédia: %.1f", media);
    if (media >= 7)
    {
        printf("\nAprovado\n");
    }
    else if (media >= 4)
    {
        printf("\nDe final\n");
    }
    else
    {
        printf("\nReprovado\n");
    }
    
    return 0;
}