#include <stdio.h>

// Criar uma matriz que armazene a matrícula, notas e média de uma turma de 50 alunos
// Cada linha da matriz armazenará a matrícula, notas e média de um aluno
// Para cada linha, a primeira coluna possuirá a matrícula, a segunda coluna a primeira nota,
// a terceira a segunda nota, a quarta a terceira nota e a quinta coluna terá a média das três
// notas do aluno.
// Veja o exemplo abaixo [Imagem]
// A matrícula e as notas devem ser digitadas por um usuário
// Ao final deve ser exibida a matrícula, a média e a situação do aluno
// (aprovado, reprovado ou de final)

int main(void)
{
    int quant = 50, l, c;
    float matriz[quant][5];
    // 0 - Matrícula
    // 1, 2, 3 - Notas
    // 4 - Média

    for (l = 0; l < quant; l++)
    {
        printf("\n%dº Aluno: ", l+1);

        printf("\nMatrícula: ");
        scanf("%f", &matriz[l][0]);
        setbuf(stdin, NULL);

        matriz[l][4] = 0;
        for (c = 1; c < 4; c++)
        {
            printf("%dª nota: ", c);
            scanf("%f", &matriz[l][c]);
            setbuf(stdin, NULL);

            matriz[l][4] += matriz[l][c];
        }
        matriz[l][4] /= 3;
    }

    printf("\nMatrícula \t Nota 1 \t Nota 2 \t Nota 3 \t Média \t \t Situação\n");
    for (l = 0; l < quant; l++)
    {
        printf("%.0f", matriz[l][0]);
        for (c = 1; c < 4; c++)
        {
            printf("\t \t %.1f", matriz[l][c]);
        }
        printf("\t \t %.1f", matriz[l][4]);
        if (matriz[l][4] >= 7)
        {
            printf("\t \t Aprovado\n");
        }
        else if (matriz[l][4] >= 4)
        {
            printf("\t \t Prova Final\n");
        }
        else
        {
            printf("\t \t Reprovado\n");
        }
    }
    return 0;
}