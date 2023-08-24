#include <stdio.h>

/*
    Um colégio tem 5 turmas e cada turma tem N alunos.
    Criar um algoritmo que exiba, por turma, total de alunos com média superior a 7 e média geral da escola.
*/

int main(void)
{
    int turmas = 5, n, tot_notas = 3;
    int i, j, k;
    float nota, media, tot_media = 0;
    int media_0, media_1, media_2, media_3, media_4, media_5, tot_alunos = 0;

    for (i = 0; i < turmas; i++)
    {
        printf("\nAlunos da %dª turma: ", i+1);
        scanf(" %d", &n);
        tot_alunos += n;

        media_0 = 0;
        for (j = 0; j < n; j++)
        {
            printf("\n%dº aluno:\n", j+1);

            media = 0;
            for (k = 0; k < tot_notas; k++)
            {
                printf("%dª Nota: ", k+1);
                scanf(" %f", &nota);
                media += nota;
            }
            media /= tot_notas;

            tot_media += media;
            
            if (media >= 7)
                media_0++;
        }
        
        switch (i)
        {
            case 0:
                media_1 = media_0;
                break;

            case 1:
                media_2 = media_0;
                break;
            
            case 2:
                media_3 = media_0;
                break;

            case 3:
                media_4 = media_0;
                break;
            
            case 4:
                media_5 = media_0;
                break;
        }
    }
    if (tot_alunos > 0)
    {
        tot_media /= tot_alunos;
    }
    printf("\nAlunos com média superior a 7:");
    printf("\nTurma 1: %d", media_1);
    printf("\nTurma 2: %d", media_2);
    printf("\nTurma 3: %d", media_3);
    printf("\nTurma 4: %d", media_4);
    printf("\nTurma 5: %d", media_5);
    printf("\nMédia geral da escola (%d alunos): %.1f\n", tot_alunos, tot_media);
    return 0;
}