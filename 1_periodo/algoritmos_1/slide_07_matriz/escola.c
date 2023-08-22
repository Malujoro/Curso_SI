#include <stdio.h>

int main(void)
{
    int alunos = 3;
    float matriz[alunos][5];
    int l, c;

    for (l = 0; l < alunos; l++)
    {
        printf("\nMatrícula do %dº aluno: ", l+1);
        scanf("%f", &matriz[l][0]);
        setbuf(stdin, NULL);

        matriz[l][4] = 0;
        for (c = 1; c < 4; c++)
        {
            printf("Nota %d: ", c);
            scanf("%f", &matriz[l][c]);
            setbuf(stdin, NULL);
            matriz[l][4] += matriz[l][c];
        }
        matriz[l][4] /= 3;
    }

    for (l = 0; l < alunos; l++)
    {
        printf("\nMatrícula: %.0f", matriz[l][0]);
        printf("\nMédia: %.2f", matriz[l][4]);
        printf("\nSituação: ");
        if (matriz[l][4] >= 7)
            printf("Aprovado\n");
        else if (matriz[l][4] >= 4)
            printf("Prova Final!\n");
        else
            printf("Reprovado!!\n");
    }

    return 0;
}