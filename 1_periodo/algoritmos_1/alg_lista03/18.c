#include <stdio.h>

/*
    Entra com o nome e as três notas de 20 alunos. Exibir o nome, a média e
    a situação do aluno: aprovado, de final o reprovado.
*/

int main(void)
{
    char nome[100];
    float nota, media;
    int quant = 20, i, j;

    for (i = 0; i < quant; i++)
    {
        printf("\n%dº aluno:", i+1);
        printf("\nNome: ");
        scanf(" %[^\n]s", nome);

        media = 0;
        for (j = 0; j < 3; j++)
        {
            printf("%dª Nota: ", j+1);
            scanf(" %f", &nota);
            media += nota;
        }
        media /= 3;

        printf("\nNome: %s", nome);
        printf("\nMédia: %.1f", media);
        printf("\nSituação: ");
        if (media >= 7)
            printf("Aprovado\n");
        
        else if (media >= 4)
            printf("De final\n");

        else
            printf("Reprovado\n");
    }
    return 0;
}