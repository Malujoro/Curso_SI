#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct
{
    char *nome;
    int idade;
    char *posicao;
    int numero_camisa;
} Jogador;

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

int menu()
{
    int op;
    printf("\nMenu");
    printf("\n[1] - Cadastrar jogador principal");
    printf("\n[2] - Cadastrar jogador reserva");
    printf("\n[3] - Exibir todos os jogadores");
    printf("\n[0] - Sair");
    printf("\nOpção: ");
    scanf(" %d", &op);
    return op;
}

Jogador *alocarJogador(char tam)
{
    Jogador *vetor = (Jogador *) malloc(tam * sizeof(Jogador));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tam; i++)
    {
        vetor[i].nome = alocarStr(MAX_STR);
        vetor[i].posicao = alocarStr(MAX_STR);
    }

    return vetor;
}

Jogador *cadastrarJogadores(int quant)
{
    Jogador *time = alocarJogador(quant);

    for(int i = 0; i < quant; i++)
    {
        printf("\n%dº jogador: ", i+1);
        printf("\nNome: ");
        scanf(" %[^\n]s", time[i].nome);
        time[i].nome = (char *) realloc(time[i].nome, tamanhoStr(time[i].nome) * sizeof(char));

        printf("Idade: ");
        scanf(" %d", &time[i].idade);

        printf("Posição: ");
        scanf(" %[^\n]s", time[i].posicao);
        time[i].posicao = (char *) realloc(time[i].posicao, tamanhoStr(time[i].posicao) * sizeof(char));

        printf("Número da camisa: ");
        scanf(" %d", &time[i].numero_camisa);
    }
    return time;
}

void exibirJogadores(Jogador *time, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        printf("\n%dº jogador: ", i+1);
        printf("\nNome: %s", time[i].nome);
        printf("\nIdade: %d", time[i].idade);
        printf("\nPosição: %s", time[i].posicao);
        printf("\nNúmero da camisa: %d\n", time[i].numero_camisa);
    }
}

void liberarJogadores(Jogador *time, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        free(time[i].nome);
        time[i].nome = NULL;

        free(time[i].posicao);
        time[i].posicao = NULL;
    }
    free(time);
    time = NULL;
}

int main()
{
    int op, quantPrin, quantRes;
    Jogador *principal = NULL;
    Jogador *reserva = NULL;
    do
    {
        op = menu();
        switch(op)
        {
            case 1:
                if(!principal)
                {
                    printf("\nQuantidade de jogadores principais: ");
                    scanf(" %d", &quantPrin);
                    principal = cadastrarJogadores(quantPrin);
                }
                else
                    printf("\nEsses jogadores já foram cadastrados\n");
                break;
            case 2:
                if(!reserva)
                {
                    printf("\nQuantidade de jogadores reservas: ");
                    scanf(" %d", &quantRes);
                    reserva = cadastrarJogadores(quantRes);
                }
                else
                    printf("\nEsses jogadores já foram cadastrados\n");
                break;
            case 3:
                if(principal)
                {
                    printf("\nJogadores principais: \n");
                    exibirJogadores(principal, quantPrin);
                }

                if(reserva)
                {
                    printf("\nJogadores reservas: \n");
                    exibirJogadores(reserva, quantRes);
                }

                break;
            case 0:
                printf("\nSaindo...\n");
                break;
        }

    }while(op != 0);
    liberarJogadores(principal, quantPrin);
    liberarJogadores(reserva, quantRes);
    return 0;
}