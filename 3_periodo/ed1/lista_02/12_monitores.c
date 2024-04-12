#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct
{
    char nome[MAX_STR];
    int matricula;
    int quant;
    int *questoes;
} Aluno;

int *alocarInt(int quant)
{
    int *vetor = (int *) calloc(quant, sizeof(int));

    if(!vetor)
    {
        printf("\nErro! Não foi possível alocar o vetor\n");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

Aluno *alocarAlunos(int quantAlunos, int quantQuestoes)
{
    Aluno *alunos = (Aluno *) malloc(quantAlunos * sizeof(Aluno));

    if(!alunos)
    {
        printf("\nErro! Não foi possível alocar o vetor\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < quantAlunos; i++)
        alunos[i].questoes = alocarInt(quantQuestoes);

    return alunos;
}

void desalocarQuestoes(int *questoes)
{
    free(questoes);
    questoes = NULL;
}

void desalocarAlunos(Aluno *alunos, int quantAlunos)
{
    for(int i = 0; i < quantAlunos; i++)
        desalocarQuestoes(alunos[i].questoes);
    
    free(alunos);
    alunos = NULL;
}

int menu()
{
    int op;

    printf("\nMenu");
    printf("\n[1] - Cadastrar aluno");
    printf("\n[2] - Atribuir questoes");
    printf("\n[3] - Questões que um aluno teve dificuldade");
    printf("\n[4] - Alunos que tiveram dificuldade com uma questão");
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

void atribuirQuestoes(Aluno *alunos, int pos, int quantQuestoes)
{
    alunos[pos].quant = 0;

    printf("\nAluno: %s\n", alunos[pos].nome);
    for(int i = 0; i < quantQuestoes; i++)
    {
        printf("Dificuldade na questão %d? [0 - Não | 1 - Sim] ", i+1);
        scanf(" %d", &alunos[pos].questoes[i]);
        if(alunos[pos].questoes[i])
            alunos[pos].quant++;
    }
}

int buscarAluno(Aluno *alunos, int quant)
{
    int matricula;

    printf("\nMatricula do aluno: ");
    scanf(" %d", &matricula);

    for(int i = 0; i < quant; i++)
    {
        if(alunos[i].matricula == matricula)
            return i;
    }

    return -1;
}

int verificaQuestao(int quantQuestoes)
{
    int questao;

    printf("\nNúmero da questão: ");
    scanf(" %d", &questao);

    if(questao > 0 && questao <= quantQuestoes)
            return questao-1;
    return -1;
}

void imprimirQuestoes(Aluno *alunos, int pos, int quantQuestoes)
{
    printf("\nO aluno [%s] teve dificuldade em %d questões:", alunos[pos].nome, alunos[pos].quant);
    for(int i = 0; i < quantQuestoes; i++)
    {
        if(alunos[pos].questoes[i])
            printf(" %d", i+1);
    }
    printf("\n");
}

void imprimirAlunos(Aluno *alunos, int questao, int quantAlunos)
{
    printf("\nAlunos que tiveram dificuldade com a questão %d:", questao+1);
    for(int i = 0; i < quantAlunos; i++)
    {
        if(alunos[i].questoes[questao])
            printf("\n%s", alunos[i].nome);
    }
    printf("\n");
}

int main()
{
    int op, tot, quantAlunos = 0, quantQuestoes, pos, questao;

    printf("Quantidade de alunos: ");
    scanf(" %d", &tot);

    printf("Quantidade de questões: ");
    scanf(" %d", &quantQuestoes);

    Aluno *alunos = alocarAlunos(tot, quantQuestoes);
    
    do
    {
        op = menu();
        
        switch(op)
        {
            case 1:
                if(quantAlunos == tot)
                    printf("\nTodos os alunos já foram cadastrados\n");
                else
                {
                    for(quantAlunos = 0; quantAlunos < tot; quantAlunos++)
                        cadastrarAluno(alunos, quantAlunos);
                }
                break;
            case 2:
                for(int i = 0; i < tot; i++)
                    atribuirQuestoes(alunos, i, quantQuestoes);
                break;
            case 3:
                pos = buscarAluno(alunos, quantAlunos);

                if(pos != -1)
                    imprimirQuestoes(alunos, pos, quantQuestoes);
                else
                    printf("\nMatrícula inválida\n");

                break;
            case 4:
                questao = verificaQuestao(quantQuestoes);

                if(questao != -1)
                    imprimirAlunos(alunos, questao, quantAlunos);
                else
                    printf("\nQuestão inválida\n");

                break;
            case 0:
                printf("\nSaindo...\n");
                break;
        }

    }while(op != 0);

    desalocarAlunos(alunos, quantAlunos);
    return 0;
}