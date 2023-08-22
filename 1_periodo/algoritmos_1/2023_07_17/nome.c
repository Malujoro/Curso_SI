#include <stdio.h>

int main(void)
{
    char nomes[5][100];
    float notas[5][3], media[5];
    float soma;
    int l, c;

    for (l = 0; l < 5; l++)
    {
        printf("\nNome do %dº aluno: ", l+1);
        gets(nomes[l]);
        setbuf(stdin, NULL);

        soma = 0;
        for (c=0; c < 3; c++)
        {
            printf("%dª Nota: ", c+1);
            scanf("%f", &notas[l][c]);
            setbuf(stdin, NULL);
            soma += notas[l][c];
        }

        media[l] = soma / 3;
    }

    printf("\nAlunos Aprovados:");
    for (l = 0; l < 5; l++)
    {
        if (media[l] >= 7)
        {
            printf("\n%s", nomes[l]);
        }
        //for (c = 0; c < 3; c++)
        //{
            
        //}
    }
    return 0;
}