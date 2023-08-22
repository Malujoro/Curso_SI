#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    Desenvolver uma aplicação em Linguagem C, utilizando os conceitos de
    estrutura de seleção, repetição, vetor, matriz e funções, opcionalmente registros.

    A aplicação deverá possuir um menu para selecionar a opção desejada, que deverá
    possuir as seguintes opções:

  x 1– Definição da quantidade de dados a serem inseridos;
    2– Inserção dos dados;
    3– Apresentar os dados armazenados;
    4– Gerar relatórios por palavras-chave;
    5– Atualização de algum dado, a ser informado pelo usuário;
  x 6– Mostrar a quantidade de dados armazenados;
  x 0– Finalização da aplicação.
*/

#define LIMITE 5
#define MAX_SABORES 4
#define MAX_CATEGORIAS 3

struct tipo_prato
{
    int codigo;         // Código do prato
    char nome[100];     // Nome do prato
    int categoria;      // Categoria do prato [Principal, Acompanhamento, Sobremesa]
    int sabor;          // Sabor do prato [Salgado, Doce, Apimentado, Amargo]
    int quantidade;     // Quantidade de pratos disponíveis
    float preco;        // Preço unitário do prato
} prato[LIMITE];

char sabor[MAX_SABORES][15] = {"Salgado", "Doce", "Apimentado", "Amargo"};
char categoria[MAX_CATEGORIAS][20] = {"Prato principal", "Acompanhamento", "Sobremesa"};

// Função para printar uma linha
void linha(void)
{
    printf("--------------------------------------------------------");
}

// Função para ler apenas números inteiros (verifica se o que foi inserido foi realmente um inteiro)
// Recebe o texto a ser mostrado e Retorna o número lido
int leia_int(char texto[])
{
    int num, retorno;
    char letra;

    do
    {
        printf("%s", texto);
        retorno = scanf( "%d", &num);
        
        do
        {
            letra = getchar();
        } while (letra != '\n');

        if (retorno == 0)
        {
            //linha();
            printf("\nEntrada inválida! Digite um número inteiro");
        }
    } while (retorno == 0);

    return num;
}

// Função para exibir os sabores de prato disponíveis
// Retorna a opção escolhida do sabor
int mostrar_sabores(void)
{
    int i, opcao;

    printf("\n------Sabores------");
    for (i = 0; i < MAX_SABORES; i++)
    {
        printf("\n%d- %s", i+1, sabor[i]);
    }
    opcao = leia_int("\n\nOpção: ");
    //printf("\n\nOpção: ");
    return opcao;
} 

// Função para exibir as categorias de prato disponíveis
// Retorna a opção escolhida da categoria
int mostrar_categorias(void)
{
    int i, opcao;

    printf("\n------Categoria------");
    for (i = 0; i < MAX_CATEGORIAS; i++)
    {
        printf("\n%d- %s", i+1, categoria[i]);
    }
    opcao = leia_int("\n\nOpção: ");
    //printf("\n\nOpção: ");
    return opcao;
}

// Função para exibir o menu de opções do programa
// Retorna a opção escolhida do menu
int menu(void)
{
    int opcao;

    linha();
    printf("\n\n--------------------Menu de opções--------------------");
    printf("\n1- Aumentar quantidade de pratos a serem cadastrados");
    printf("\n2- Cadastrar prato");
    printf("\n3- Visualizar todos os pratos cadastrados");
    printf("\n4- Buscar prato");
    printf("\n5- Atualizar prato");
    printf("\n6- Quantidade de pratos cadastrados");
    printf("\n0- Sair da aplicação\n");

    opcao = leia_int("\nOpção: ");
    return opcao;
}

// Função para "alocar" espaço para cadastro (limite definido pela constante)
int aumentar_espaco(int tot)
{
    int aumento;

    if (tot == LIMITE) // Verifica se "tem espaço" disponível
    {
        printf("\nCapacidade máxima atingida! Não é possível aumentar\n");
    }
    else // Se ainda "tiver espaço", aumentar ele
    {
        // Repete até o usuário digitar uma quantidade válida para o aumento:
        // Inteiros maiores que 0 que não excedem o limite, nem mesmo somados com o espaço já alocado
        do 
        {
            printf("\nEspaço livre no sistema: %d", LIMITE-tot);
            aumento = leia_int("\nQuantos pratos serão cadastrados? ");
            if (tot + aumento > LIMITE)
            {
                printf("\nQuantidade digitada excede o limite!");
                printf("\nDigite um número menor ou igual a %d\n", LIMITE-tot);
                //linha();
            }
            else if (aumento <= 0)
            {
                printf("\nNúmero inválido! Digite apenas números maiores que 0\n");
                //linha();
            }
            else
            {
                printf("\nAdicionado %d espaço(s) para cadastro de pratos\n", aumento);
                tot += aumento;
                break;
            }
        } while (tot + aumento > LIMITE || aumento <= 0);
    }
    return tot;
}

// Função para cadastrar um prato
// Recebe quantos pratos já foram cadastrados, e o "espaço disponível"
// Retorna o total de pratos cadastrados
int cadastrar_prato(int quant, int tot)
{
    int cod, i;

    if (quant == tot)
    {
        printf("\nNão há espaço disponível para cadastro!\n");
    }
    else
    {   
        printf("\n--------%dº Prato--------", quant+1);

        do // Cadastro do código do prato, não aceita números repetidos
        {
            cod = leia_int("\nCódigo do prato: ");

            if (cod <= 0)
            {
                printf("Erro! Código inválido\n");
            }
            else
            {
                for (i = 0; i < quant; i++) // Verifica se o código digitado já existe no cadastro
                {
                    if (cod == prato[i].codigo)
                    {
                        printf("\nErro! Código já existente");
                        cod = -1;
                        break;
                    }
                }
                if (i == quant) // Significa que passou por todo o looping sem encontrar repetido
                {
                    prato[quant].codigo = cod;
                }
            }
        } while (cod <= 0);

        // Cadastro do nome do prato, não aceita nomes repetidos
        // Cadastro da categoria do prato
        // Cadastro do sabor do prato
        // Cadastro da quantidade do prato
        // Cadastro do preço do prato

        /*
        printf("\nNome do prato:");
        printf("\nCategoria do prato:");
        printf("\nSabor do prato:");
        printf("\nQuantidade disponível:");
        printf("\nPreço do prato: R$");
        */
        


        printf("\nPrato cadastrado com sucesso!\n");
        quant++;
    }
    return quant;
}
void mostrar_prato(int pos)
{
    printf("\n--------%dº Prato--------", pos+1);
    printf("\nCódigo do prato: %d", prato[pos].codigo);
    printf("\nNome do prato: %s", prato[pos].nome);
    printf("\nCategoria do prato: %s", categoria[prato[pos].categoria]);
    printf("\nSabor do prato: %s", sabor[prato[pos].sabor]);
    printf("\nQuantidade disponível: %d", prato[pos].quantidade);
    printf("\nPreço do prato: R$%.2f\n", prato[pos].preco);
}
void buscar_prato();
void editar_prato();

int main(void)
{
    int op, i;
    int total = 0, quant_cadast = 0;
    
    linha();
    // Programa inicia com o usuário definindo a quantidade inicial de pratos que serão cadastrados
    total = aumentar_espaco(0);
    
    do // Inicia o menu, opção 0 sai do programa
    {
        op = menu();
        linha();

        switch (op)
        {
            case 1: // Aumentar quantidade de pratos a serem cadastrados
                printf("\n[Aumentar quantidade de pratos a serem cadastrados]\n");
                total = aumentar_espaco(total);
                break;

            case 2: // Cadastrar prato
                printf("\n[Cadastrar prato]\n");
                quant_cadast = cadastrar_prato(quant_cadast, total);
                break;

            case 3: // Visualizar todos os pratos cadastrados
                printf("\n[Visualizar todos os pratos cadastrados]\n");
                if (quant_cadast == 0)
                {
                    printf("\nNão há nenhum prato cadastrado\n");
                }
                else
                {
                    for (i = 0; i < quant_cadast; i++)
                    {
                        mostrar_prato(i);
                    }
                }
                break;

            case 4: // Buscar prato
                printf("\n[Buscar prato]\n");
                break;
            
            case 5: // Atualizar prato
                printf("\n[Atualizar prato]\n");
                break;

            case 6: // Quantidade de pratos cadastrados
                printf("\n[Quantidade de pratos cadastrados]\n");
                printf("\nJá foram cadastrados %d pratos", quant_cadast);
                printf("\nEspaço disponível para cadastro: %d", total-quant_cadast);
                printf("\nEspaço total alocado para cadastro: %d", total);
                printf("\nEspaço não alocado: %d", LIMITE-total);
                printf("\nEspaço total: %d\n", LIMITE);
                break;

            case 0: // Sair da aplicação
                printf("\n[Sair da aplicação]\n");
                printf("\nEncerrando programa...\n");
                break;
            
            default:
                printf("\nOpção inválida, tente novamente\n");
        }
    } while (op != 0);
    return 0;
}