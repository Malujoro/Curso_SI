#include <stdio.h>

int main()
{
    int i, j, mat[2][2], det, diag1=1, diag2=1;

    for(i=0; i < 2; i++)
    {
        for(j=0; j < 2; j++)
        {
            printf("(%d, %d): ", i, j);
            scanf(" %d", &mat[i][j]);
        }
    }
    
    for(i=0; i < 2; i++)
    {
        for(j=0; j < 2; j++)
        {
            if(i == j)
            {
                diag1 *= mat[i][j];
            }
            if(i + j == 1)
            {
                diag2 *= mat[i][j];
            }
        }
    }
    det = diag1 - diag2;
    printf("Diagonal principal: %d\n", diag1);
    printf("Diagonal secundária: %d\n", diag2);
    printf("Determinante: %d\n", det);
    return 0;
}

/*
#include <stdio.h>
#include <string.h>

struct aluno
{
    char nome[80];
    int idade;
    float notas[3];
};

int main()
{
    struct aluno al1;

    strcpy(al1.nome, "Iago Roberto");
    al1.idade = 19;
    al1.notas[0] = 6;
    al1.notas[1] = 10;
    al1.notas[2] = 10;

    printf("Nome = %s, Idade = %d, Notas =", al1.nome, al1.idade);
    
    return 0;
}
*/