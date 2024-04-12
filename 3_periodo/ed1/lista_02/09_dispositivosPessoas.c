#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct
{
    char *descricao;
    float valor;
} Eletronico;

typedef struct
{
    char *nome;
    char *cpf;
    Eletronico *dispositivos;
    int quantElet;
} Pessoa;

void limpaBuffer()
{
    while(getchar() != '\n');
}

char *alocarStr(char tam)
{
    char *vetor = (char *) malloc(tam * sizeof(char));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

int tamanhoStr(char *str)
{
    int tam;
    for(tam = 0; str[tam] != '\0'; tam++);
    return tam;
}

Eletronico *alocarEletronico(int tam)
{
    Eletronico *vetor = (Eletronico *) malloc(tam * sizeof(Eletronico));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tam; i++)
        vetor[i].descricao = alocarStr(MAX_STR);

    return vetor;
}

Eletronico *cadastrarEletronico(int quant)
{
    Eletronico *eletronicos = alocarEletronico(quant);

    for(int i = 0; i < quant; i++)
    {
        printf("\n%dº eletrônico: ", i+1);

        printf("\nDescrição: ");
        scanf("%[^\n]s", eletronicos[i].descricao);
        limpaBuffer();

        eletronicos[i].descricao = (char *) realloc(eletronicos[i].descricao, tamanhoStr(eletronicos[i].descricao) * sizeof(char));

        printf("Valor: R$");
        scanf(" %f", &eletronicos[i].valor);
        limpaBuffer();
    }

    return eletronicos;
}

void exibirEletronico(Eletronico *eletronicos, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        printf("\n--- %dº eletrônico ---", i+1);
        printf("\nDescrição: %s", eletronicos[i].descricao);
        printf("\nValor: R$%.2f\n", eletronicos[i].valor);
    }
}

void liberarEletronico(Eletronico *eletronicos, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        free(eletronicos[i].descricao);
        eletronicos[i].descricao = NULL;
    }
    free(eletronicos);
    eletronicos = NULL;
}

Pessoa *alocarPessoa(int tam)
{
    Pessoa *vetor = (Pessoa *) malloc(tam * sizeof(Pessoa));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tam; i++)
    {
        vetor[i].nome = alocarStr(MAX_STR);
        vetor[i].cpf = alocarStr(MAX_STR);
    }

    return vetor;
}

Pessoa *cadastrarPessoa(int quant)
{
    Pessoa *pessoas = alocarPessoa(quant);

    for(int i = 0; i < quant; i++)
    {
        printf("\n[%dº Pessoa]", i+1);
        printf("\nNome: ");
        scanf("%[^\n]s", pessoas[i].nome);
        limpaBuffer();

        pessoas[i].nome = (char *) realloc(pessoas[i].nome, tamanhoStr(pessoas[i].nome) * sizeof(char));


        printf("CPF: ");
        scanf("%[^\n]s", pessoas[i].cpf);
        limpaBuffer();

        pessoas[i].cpf = (char *) realloc(pessoas[i].cpf, tamanhoStr(pessoas[i].cpf) * sizeof(char));

        printf("Quantidade de eletrônicos: ");
        scanf(" %d", &pessoas[i].quantElet);
        limpaBuffer();

        pessoas[i].dispositivos = cadastrarEletronico(pessoas[i].quantElet);
    }
    return pessoas;
}

void exibirPessoa(Pessoa *pessoas, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        printf("\n-----[ %dº Pessoa ]-----", i+1);
        printf("\nNome: %s", pessoas[i].nome);
        printf("\nCPF: %s\n", pessoas[i].cpf);
        exibirEletronico(pessoas[i].dispositivos, pessoas[i].quantElet);
    }
}

void liberarPessoa(Pessoa *pessoas, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        free(pessoas[i].nome);
        pessoas[i].nome = NULL;

        free(pessoas[i].cpf);
        pessoas[i].cpf = NULL;

        liberarEletronico(pessoas[i].dispositivos, pessoas[i].quantElet);
    }
    free(pessoas);
    pessoas = NULL;
}

int main()
{
    int quant;

    printf("\nQuantidade de pessoas cadastradas: ");
    scanf(" %d", &quant);
    limpaBuffer();

    Pessoa *pessoas = cadastrarPessoa(quant);
    
    printf("\n[Pessoas cadastradas]\n");
    exibirPessoa(pessoas, quant);

    liberarPessoa(pessoas, quant);
    return 0;
}