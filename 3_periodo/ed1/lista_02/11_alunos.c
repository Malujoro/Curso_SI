#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100
#define QUANT_NOTAS 3

typedef struct
{
    char nome[MAX_STR];
    int matricula;
    float notas[QUANT_NOTAS];
    float media;
} Aluno;

Aluno *alocarAlunos(int quant)
{
    Aluno *alunos = (Aluno *) malloc(quant * sizeof(Aluno));

    if(!alunos)
    {
        printf("\nErro! Não foi possível alocar o vetor\n");
        exit(EXIT_FAILURE);
    }

    return alunos;
}

void desalocarAlunos(Aluno *alunos)
{
    free(alunos);
    alunos = NULL;
}

int menu()
{
    int op;

    printf("\nMenu");
    printf("\n[1] - Cadastrar aluno");
    printf("\n[2] - Atribuir notas");
    printf("\n[3] - Imprimir aprovados");
    printf("\n[4] - Imprimir reprovados");
    printf("\n[0] - Sair");
    printf("\nOpção: ");
    scanf(" %d", &op);

    return op;
}

void cadastrarAluno(Aluno *alunos, int pos)
{
    printf("\n%dº Aluno: \n", pos+1);

    printf("\nNome: ");
    scanf(" %[^\n]s", alunos[pos].nome);

    printf("Matrícula: ");
    scanf(" %d", &alunos[pos].matricula);
}

void atribuirNotas(Aluno *alunos, int pos)
{
    alunos[pos].media = 0;

    printf("\nAluno: %s\n", alunos[pos].nome);
    for(int i = 0; i < QUANT_NOTAS; i++)
    {
        printf("%dª Nota: ", i+1);
        scanf(" %f", &alunos[pos].notas[i]);
        alunos[pos].media += alunos[pos].notas[i];
    }

    alunos[pos].media /= QUANT_NOTAS;
}

void imprimirAprovados(Aluno *alunos, int quant)
{
    printf("\nAlunos aprovados: \n");
    for(int i = 0; i < quant; i++)
    {
        if(alunos[i].media >= 7)
        {
            printf("\n%dº Aluno: \n", i+1);
            printf("\nNome: %s", alunos[i].nome);
            printf("\nMatrícula: %d", alunos[i].matricula);
            printf("\nNotas:");
            for(int j = 0; j < QUANT_NOTAS; j++)
                printf(" %.1f", alunos[i].notas[j]);
            printf("\nMédia: %.1f\n", alunos[i].media);
        }
    }
}

void imprimirReprovados(Aluno *alunos, int quant)
{
    printf("\nAlunos reprovados: \n");
    for(int i = 0; i < quant; i++)
    {
        if(alunos[i].media < 7)
        {
            printf("\n%dº Aluno: \n", i+1);
            printf("\nNome: %s", alunos[i].nome);
            printf("\nMatrícula: %d", alunos[i].matricula);
            printf("\nNotas:");
            for(int j = 0; j < QUANT_NOTAS; j++)
                printf(" %.1f", alunos[i].notas[j]);
            printf("\nMédia: %.1f\n", alunos[i].media);
        }
    }
}

int main()
{
    int op, tot, quant = 0;

    printf("Quantidade de alunos: ");
    scanf(" %d", &tot);

    Aluno *alunos = alocarAlunos(tot);
    
    do
    {
        op = menu();
        
        switch(op)
        {
            case 1:
                if(quant == tot)
                    printf("\nTodos os alunos já foram cadastrados\n");
                else
                {
                    for(quant = 0; quant < tot; quant++)
                        cadastrarAluno(alunos, quant);
                }
                break;
            case 2:
                for(int i = 0; i < tot; i++)
                    atribuirNotas(alunos, i);
                break;
            case 3:
                imprimirAprovados(alunos, quant);
                break;
            case 4:
                imprimirReprovados(alunos, quant);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
        }

    }while(op != 0);

    desalocarAlunos(alunos);
    return 0;
}