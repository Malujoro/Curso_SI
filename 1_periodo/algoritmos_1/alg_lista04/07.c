#include <stdio.h>
#include <time.h>
#include <string.h>

// Dados três vetores (Nota01, Nota02, Nota03) que contém as notas de 50 alunos,
// construir um quarto vetor (Media) que conterá as médias de cada aluno
// e construir um quinto vetor (Situacao) que contém a situação do aluno:
// aprovado, de final ou reprovado

int main(void)
{
    int quant = 10, i;
    float nota1[quant], nota2[quant], nota3[quant], media[quant];
    char situacao[quant][15];

    srand(time(NULL));

    for (i = 0; i < quant; i++)
    {
        nota1[i] = rand() % 101;
        nota1[i] /= 10;
        
        nota2[i] = rand() % 101;
        nota2[i] /= 10;

        nota3[i] = rand() % 101;
        nota3[i] /= 10;
    }

    for (i = 0; i < quant; i++)
    {
        media[i] = (nota1[i] + nota2[i] + nota3[i]) / 3;
        if (media[i] >= 7)
        {
            strcpy(situacao[i], "Aprovado");
        }
        else if (media[i] >= 4)
        {
            strcpy(situacao[i], "Prova Final");
        }
        else
        {
            strcpy(situacao[i], "Reprovado");
        }

        printf("\n%dº aluno: \t %.2f \t %s", i+1, media[i], situacao[i]);
    }
    return 0;
}