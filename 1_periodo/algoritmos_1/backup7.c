#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    Desenvolver uma aplicação em Linguagem C, utilizando os conceitos de
    estrutura de seleção, repetição, vetor, matriz e funções, opcionalmente registros.

    A aplicação deverá possuir um menu para selecionar a opção desejada, que deverá
    possuir as seguintes opções:

  x 1– Definição da quantidade de dados a serem inseridos;
  x 2– Inserção dos dados;
  x 3– Apresentar os dados armazenados;
  x 4– Gerar relatórios por palavras-chave;
  x 5– Atualização de algum dado, a ser informado pelo usuário;
  x 6– Mostrar a quantidade de dados armazenados;
  x 0– Finalização da aplicação.
*/

#define LIMITE 100
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

char sabores[MAX_SABORES][15] = {"Salgado", "Doce", "Apimentado", "Amargo"};
char categorias[MAX_CATEGORIAS][20] = {"Prato principal", "Acompanhamento", "Sobremesa"};

void titulo(char str1[], char str2[]);
void linha(void);
int leia_int(char texto[]);
float leia_float(char texto[]);

void mostrar_sabores(void);
void mostrar_categorias(void);

int menu(void);
int menu2(void);
int aumentar_espaco(int tot);
void cadastrar_prato(int quant, int id, int tot);
void mostrar_prato(int pos);
void buscar_prato(int quant);
void editar_prato(int quant, int tot);

/////////////////////////////////////////////
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
                if (quant_cadast == total)
                {
                    printf("\nNão há espaço disponível para cadastro!\n");
                }
                else
                {
                    printf("\n---------------[%dº Prato]---------------", quant_cadast+1);
                    for (i = 1; i < 7; i++)
                    {
                        cadastrar_prato(quant_cadast, i, total);
                    }
                    printf("\n[Prato cadastrado com sucesso!]\n");
                    quant_cadast++;
                }
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

            case 4: // Buscar pratos
                if (quant_cadast == 0)
                {
                    printf("\n[Buscar pratos]\n");
                    printf("\nNão há nenhum prato cadastrado\n");
                }
                else
                {
                    buscar_prato(quant_cadast);
                }
                break;
            
            case 5: // Atualizar/editar prato
                printf("\n[Atualizar/editar prato]\n");
                if (quant_cadast == 0)
                {
                    printf("\nNão há nenhum prato cadastrado\n");
                }
                else
                {
                    editar_prato(quant_cadast, total);
                }
                break;

            case 6: // Quantidade de pratos cadastrados
                printf("\n[Quantidade de pratos cadastrados]\n");

                printf("\nJá foram cadastrados %d pratos", quant_cadast);
                printf("\nEspaço disponível para cadastro: %d", total-quant_cadast);
                printf("\nEspaço total alocado para cadastro: %d", total);
                printf("\nEspaço não alocado: %d", LIMITE-total);
                printf("\nEspaço total do sistema: %d\n", LIMITE);
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
/////////////////////////////////////////////


// Função para converter string em "Título" (Primeira letra maiúscula)
// Recebe a string original e a string pra "guardar o resultado"
void titulo(char str1[], char str2[])
{
    int i = 1;
    
    str2[0] = toupper(str1[0]); // Primeira letra maiúscula
    while (str1[i] != '\0') // \0 é o Caractere nulo (fica no final da string)
    {
        str2[i] = tolower(str1[i]); // Restante das letras minúsculas
        i++;
    }
    str2[i] = '\0'; // Caractere nulo no final da string
}

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
        printf("%s", texto); // Exibe o texto recebido
        retorno = scanf(" %d", &num); // Recebe 1 se o digitado for inteiro
        
        do // Limpa o buffer do teclado
        {
            letra = getchar();
        } while (letra != '\n');

        if (retorno == 0)
        {
            printf("\nEntrada inválida! Digite um número inteiro");
        }
    } while (retorno == 0);

    return num;
}

// Função para ler apenas números reais (verifica se o que foi inserido foi realmente um float)
// Recebe o texto a ser mostrado e Retorna o número lido
float leia_float(char texto[])
{
    float num;
    int retorno;
    char letra;

    do
    {
        printf("%s", texto); // Exibe o texto recebido
        retorno = scanf(" %f", &num); // Recebe 1 se o digitado for float

        do // Limpa o buffer do teclado
        {
            letra = getchar(); 
        } while(letra != '\n');

        if (retorno == 0)
        {
            printf("Entrada inválida! Digite um número real");
        }
    } while (retorno == 0);

    return num;
}


// Função para exibir os sabores de prato disponíveis
void mostrar_sabores(void)
{
    int i;

    printf("\n-----[Sabores]-----");
    for (i = 0; i < MAX_SABORES; i++)
    {
        printf("\n%d- %s", i+1, sabores[i]);
    }
    printf("\n");
} 

// Função para exibir as categorias de prato disponíveis
void mostrar_categorias(void)
{
    int i;

    printf("\n-----[Categoria]-----");
    for (i = 0; i < MAX_CATEGORIAS; i++)
    {
        printf("\n%d- %s", i+1, categorias[i]);
    }
    printf("\n");
}


// Função para exibir o menu de opções do programa
// Retorna a opção escolhida do menu
int menu(void)
{
    int opcao;

    linha();
    printf("\n\n-------------------[Menu de opções]-------------------");
    printf("\n1- Aumentar quantidade de pratos a serem cadastrados");
    printf("\n2- Cadastrar prato");
    printf("\n3- Visualizar todos os pratos cadastrados");
    printf("\n4- Buscar pratos");
    printf("\n5- Atualizar/editar prato");
    printf("\n6- Quantidade de pratos cadastrados");
    printf("\n0- Sair da aplicação\n");

    opcao = leia_int("\nOpção: ");
    return opcao;
}

// Função para exibir o menu de "categorias" do programa
// Retorna a opção escolhida do menu
int menu2(void)
{
    int opcao;

    printf("\n1- Código");
    printf("\n2- Nome");
    printf("\n3- Categoria");
    printf("\n4- Sabor");
    printf("\n5- Quantidade");
    printf("\n6- Preço");
    printf("\n0- Cancelar\n");
    opcao = leia_int("\nOpção: ");
    linha();
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
// Recebe quantos pratos já foram cadastrados, e qual o "id de cadastro
void cadastrar_prato(int quant, int id, int tot)
{
    int i, cod, cat, sab, qnt;
    float preco;
    char nome[100];

    switch (id)
    {
        case 1:
            do // Cadastro do código do prato, não aceita números repetidos
            {
                cod = leia_int("\nCódigo do prato: ");

                if (cod <= 0)
                {
                    printf("Erro! Código inválido\n");
                }
                else
                {
                    for (i = 0; i < tot; i++) // Verifica se o código digitado já existe no cadastro
                    {
                        if (cod == prato[i].codigo)
                        {
                            printf("\nErro! Código já existente\n");
                            cod = -1;
                            break;
                        }
                    }
                    if (i == tot) // Significa que passou por todo o looping sem encontrar repetido
                    {
                        prato[quant].codigo = cod;
                    }
                }
            } while (cod <= 0); // Repete enquanto o código digitado for repetido/inválido
            break;
        
        case 2:
            do // Cadastro do nome do prato, não aceita nomes repetidos
            {
                printf("\nNome do prato: ");
                scanf(" %[^\n]s", nome);
                titulo(nome, nome); // Transforma o nome em "título"

                for (i = 0; i < tot; i++) // Verifica se o nome digitado já existe no cadastro
                    {
                        if (strcmp(nome, prato[i].nome) == 0)
                        {
                            printf("\nErro! Nome já existente\n");
                            break;
                        }
                    }
                    if (i == tot) // Significa que passou por todo o looping sem encontrar repetido
                    {
                        strcpy(prato[quant].nome, nome);
                    }
            } while (i != tot); // Repete enquanto o nome digitado for repetido
            break;

        case 3:
            do // Cadastro da categoria do prato
            {
                mostrar_categorias();
                cat = leia_int("\nCategoria do prato: ");
                if (cat <= 0 || cat > MAX_CATEGORIAS)
                {
                    printf("\nCategoria inválida!");
                }
                else
                {                
                    prato[quant].categoria = cat-1;
                }
            } while (cat <= 0 || cat > MAX_CATEGORIAS); // Repete até digitar uma categoria válida
            break;

        case 4:            
            do // Cadastro do sabor do prato
            {
                mostrar_sabores();
                sab = leia_int("\nSabor do prato: ");
                if (sab <= 0 || sab > MAX_SABORES)
                {
                    printf("\nSabor inválido!\n");
                }
                else
                {
                    prato[quant].sabor = sab-1;
                }
            } while (sab <= 0 || sab > MAX_SABORES); // Repete até digitar um sabor válido
            break;
        
        case 5:
            do // Cadastro da quantidade do prato
            {
                qnt = leia_int("\nQuantidade disponível: ");
                if (qnt < 0)
                {
                    printf("\nQuantidade inválida!\n");
                }
                else
                {
                    prato[quant].quantidade = qnt;
                }
            } while (qnt < 0);
            break;
        
        case 6:
            do // Cadastro do preço do prato
            {
                preco = leia_float("\nPreço do prato: R$");
                if (preco <= 0)
                {
                    printf("\nPreço inválido!\n");
                }
                else
                {
                    prato[quant].preco = preco;
                }
            } while (preco <= 0);
            break;

        case 0:
            printf("\n[Cancelar]\n");
            printf("\nVoltando ao menu\n");
            break;

        default:
            printf("\nOpção inválida!\n");
    }
}

// Função para exibir um prato
// Recebe a posição dele
void mostrar_prato(int pos)
{
    printf("\n---------------[%dº Prato]---------------", pos+1);
    printf("\nCódigo:        %d", prato[pos].codigo);
    printf("\nNome:          %s", prato[pos].nome);
    printf("\nCategoria:     %s", categorias[prato[pos].categoria]);
    printf("\nSabor:         %s", sabores[prato[pos].sabor]);
    printf("\nQuantidade:    %d", prato[pos].quantidade);
    printf("\nPreço:         R$%.2f\n", prato[pos].preco);
}

// Função para buscar um prato cadastrado
// Recebe quantos pratos já foram cadastrados
void buscar_prato(int quant)
{
    int i, opcao, encont, cod, cat, sab, qnt;
    char nome[100];
    float preco;

    do
    {
        encont = 0;
        printf("\n------------[Buscar prato por]------------");
        opcao = menu2();
        switch (opcao)
        {
            case 1:
                printf("\n[Código]\n");

                cod = leia_int("\nCódigo do prato: ");

                if (cod <= 0)
                {
                    printf("\nErro! Código inválido\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (cod == prato[i].codigo)
                        {
                            encont++;
                        }
                    }
                    
                    if (encont > 0)
                    {
                        printf("\n%d prato encontrado:\n", encont);
                        for (i = 0; i < quant; i++)
                        {
                            if (cod == prato[i].codigo)
                            {
                                mostrar_prato(i);
                            }
                        }
                    }
                }
                
                break;
                
            case 2:
                printf("\n[Nome]\n");

                printf("\nNome do prato: ");
                scanf(" %[^\n]s", nome);
                titulo(nome, nome);

                for (i = 0; i < quant; i++)
                {
                    if (strcmp(nome, prato[i].nome) == 0)
                    {
                        encont ++;
                    }
                }

                if (encont > 0)
                {
                    printf("\n%d prato encontrado:\n", encont);
                    for (i = 0; i < quant; i++)
                    {
                        if (strcmp(nome, prato[i].nome) == 0)
                        {
                            mostrar_prato(i);
                        }
                    }
                }

                break;

            case 3:
                mostrar_categorias();

                cat = leia_int("\nCategoria do prato: ");

                if (cat <= 0 || cat > MAX_CATEGORIAS)
                {
                    printf("\nCategoria inválida!\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (cat-1 == prato[i].categoria)
                        {
                            encont++;
                        }
                    }

                    if (encont > 0)
                    {
                        printf("\n%d prato(s) encontrado(s):\n", encont);
                        for (i = 0; i < quant; i++)
                        {
                            if (cat-1 == prato[i].categoria)
                            {
                                mostrar_prato(i);
                            }
                        }
                    }
                }
                break;
                
            case 4:
                mostrar_sabores();

                sab = leia_int("\nSabor do prato: ");

                if (sab <= 0 || sab > MAX_SABORES)
                {
                    printf("\nSabor inválido!\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (sab-1 == prato[i].sabor)
                        {
                            encont++;
                        }
                    }

                    if (encont > 0)
                    {
                        printf("\n%d prato(s) encontrado(s):\n", encont);
                        for (i = 0; i < quant; i++)
                        {
                            if (sab-1 == prato[i].sabor)
                            {
                                mostrar_prato(i);
                            }
                        }
                    }
                }
                break;

            case 5:
                printf("\n[Quantidade]\n");
                
                qnt = leia_int("\nQuantidade disponível: ");

                if (qnt < 0)
                {
                    printf("\nQuantidade inválida!\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (qnt == prato[i].quantidade)
                        {
                            encont++;
                        }
                    }
                    
                    if (encont > 0)
                    {
                        printf("\n%d prato(s) encontrado(s):\n", encont);
                        for (i = 0; i < quant; i++)
                        {
                            if (qnt == prato[i].quantidade)
                            {
                                mostrar_prato(i);
                            }
                        }
                    }
                }
                break;
                
            case 6:
                printf("\n[Preço]\n");

                preco = leia_float("\nPreço do prato: R$");

                if (preco <= 0)
                {
                    printf("\nPreço inválido!\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (preco == prato[i].preco)
                        {
                            encont++;
                        }
                    }
                    
                    if (encont > 0)
                    {
                        printf("\n%d prato(s) encontrado(s):\n", encont);
                        for (i = 0; i < quant; i++)
                        {
                            if (preco == prato[i].preco)
                            {
                                mostrar_prato(i);
                            }
                        }
                    }
                }
                break;

            case 0:
                encont = -1;
                printf("\n[Cancelar]\n");
                printf("\nVoltando ao menu\n");
                break;

            default:
                encont = -1;
                printf("\nOpção inválida!\n");
        }

        if (encont == 0)
        {
            printf("\nNão foi possível encontrar esse prato\n");
        }
    } while (opcao < 0 || opcao > 6);
}

// Função para editar um prato cadastrado
// Recebe quantos pratos já foram cadastrados
void editar_prato(int quant, int tot)
{
    int i, opcao, opcao2, cod, posicao;
    char nome[100];

    do
    {
        posicao = -1;
        printf("\n----------[Encontrar prato por]----------");
        printf("\n1- Código");
        printf("\n2- Nome");
        printf("\n0- Cancelar\n");
        opcao = leia_int("\nOpção: ");
        linha();
        switch (opcao)
        {
            case 1:
                printf("\n[Código]\n");

                cod = leia_int("\nCódigo do prato: ");

                if (cod <= 0)
                {
                    printf("\nErro! Código inválido\n");
                }
                else
                {
                    for (i = 0; i < quant; i++)
                    {
                        if (cod == prato[i].codigo)
                        {
                            posicao = i;
                            mostrar_prato(i);
                        }
                    }
                }
                break;

            case 2:
                printf("\n[Nome]\n");

                printf("\nNome do prato: ");
                scanf(" %[^\n]s", nome);
                titulo(nome, nome);

                for (i = 0; i < quant; i++)
                {
                    if (strcmp(nome, prato[i].nome) == 0)
                    {
                        posicao = i;
                        mostrar_prato(i);
                    }
                }
                break;

            case 0:
                posicao = -2;
                printf("\n[Cancelar]\n");
                printf("\nVoltando ao menu\n");
                break;

            default:
                posicao = -2;
                printf("\nOpção inválida!\n");
            
        }
        if (posicao >= 0)
        {
            do
            {
                printf("\n----------------[Editar:]----------------");
                opcao2 = menu2();
                cadastrar_prato(posicao, opcao2, tot);
                if (opcao2 >= 1 && opcao2 <= 6)
                {
                    printf("\n[Prato editado com sucesso!]\n");
                }
            } while (opcao2 < 0 || opcao2 > 6);
        }
        else if (posicao == -1)
        {
            printf("\nNão foi possível encontrar esse prato\n");
        }
    } while (opcao < 0 || opcao > 2);
}