#include <stdio.h>

/*
    Reescreva o algoritmo da questão anterior para que caso o aluno esteja de final seja
    dada a nota da prova final e seja calculado e exibido se ele passou ou não
*/

int main(void)
{
    float n1, n2, n3, n4, media, n5;

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

        printf("\nNota da Prova Final: ");
        scanf(" %f", &n5);

        media = (media + n5) / 2;

        if (media >= 6)
        {
            printf("\nAprovado com Prova Final\n");
        }
        else
        {
            printf("\nReprovado\n");
        }

    }
    else
    {
        printf("\nReprovado\n");
    }
    
    return 0;
}