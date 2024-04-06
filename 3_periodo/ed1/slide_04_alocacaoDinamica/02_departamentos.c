#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *nome;
    int mat;
    int idade;
} Pessoa;

typedef struct
{
    Pessoa pessoa;
    float salario;
} Funcionario;

typedef struct
{
    Funcionario *funcionarios;
} Departamento;

int lerString(char *string)
{
    int tam = 0;
    
    while(getchar() != '\n');
    do
    {
        string[tam] = getchar();
        tam++;
        string = (char *) realloc(string, (tam+1) * sizeof(char));
    }while(string[tam-1] != '\n');
    
    tam--;
    string[tam] = '\0';
    return tam;
}

int main()
{
    int quant;

    printf("Quantos departamentos serão cadastrados? ");
    scanf(" %d", &quant);

    Departamento departamento;
    Funcionario *funcionario = (Funcionario *) malloc(quant * sizeof(Funcionario));
    
    for(int i = 0; i < quant; i++)
    {
        funcionario[i].pessoa.nome = (char *) malloc(sizeof(char));
        printf("\n%dº Departamento: ", i+1);
        printf("\nNome do funcionário: ");
        lerString(funcionario[i].pessoa.nome);
        
        printf("Mat do funcionário: ");
        scanf("%d", &funcionario[i].pessoa.mat);

        printf("Idade do funcionário: ");
        scanf("%d", &funcionario[i].pessoa.idade);

        printf("Salário do Funcionário: R$");
        scanf("%f", &funcionario[i].salario);
    }

    departamento.funcionarios = funcionario;
    printf("\nDepartamentos cadastrados:\n");

    for(int i = 0; i < quant; i++)
    {
        printf("\n%dº Departamento: ", i+1);
        printf("\nNome do funcionário: %s", departamento.funcionarios[i].pessoa.nome);
        printf("\nMat do funcionário: %d", departamento.funcionarios[i].pessoa.mat);
        printf("\nIdade do funcionario: %d", departamento.funcionarios[i].pessoa.idade);
        printf("\nSalário do Funcionário: R$%.2f\n", departamento.funcionarios[i].salario);
    }

    for(int i = 0; i < quant; i++)
        free(funcionario[i].pessoa.nome);
    free(funcionario);
    return 0;
}