#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    float nota;
} Aluno;

typedef struct
{
    Aluno *alunos;
    int tamanho;
} Escola;

Escola inicializarEscola()
{
    Escola escola;
    escola.alunos = NULL;
    escola.tamanho = 0;
    return escola;
}

void adicionarAluno(Escola *escola, const char *nome, int idade, float nota)
{
    int pos = escola->tamanho, i;
    Aluno *aux = (Aluno *) realloc(escola->alunos, pos+1 * sizeof(Aluno));
    
    if(!aux)
        exit(1);

    for(i = 0; nome[i] != '\0' && i < 50; i++)
        aux[pos].nome[i] = nome[i];
    
    aux[pos].nome[i] = '\0';
    aux[pos].idade = idade;
    aux[pos].nota = nota;
    escola->tamanho++;
    escola->alunos = aux;
}

void imprimirEscola(const Escola *escola)
{
    printf("A escola %d alunos\n", escola->tamanho);
    for(int i = 0; i < escola->tamanho; i++)
    {
        printf("%dº aluno\n", i+1);
        printf("Nome: %s\n", escola->alunos[i].nome);
        printf("Idade: %d\n", escola->alunos[i].idade);
        printf("Nota: %f\n\n", escola->alunos[i].nota);
    }
}

void liberarEscola(Escola *escola)
{
    free(escola->alunos);
    escola->alunos = NULL;
}

int main()
{
    Escola minhaEscola = inicializarEscola();
    adicionarAluno(&minhaEscola, "Joao", 20, 8.5);
    adicionarAluno(&minhaEscola, "Maria", 22, 7.9);
    adicionarAluno(&minhaEscola, "Carlos", 21, 9.2);

    printf("Detalhes da escola: \n");
    imprimirEscola(&minhaEscola);
    liberarEscola(&minhaEscola);
}