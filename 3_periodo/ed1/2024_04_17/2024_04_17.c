#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR 100
#define TRUE 1
#define FALSE 0

// Tipos do Funcionário
#define GERENTE 0
#define SUPERVISOR 1
#define VENDEDOR 2

// Tipos do Organizacao
#define PUBLICA 0
#define PRIVADA 1


int quant_pessoas = 0;
int quant_organizacao = 0;


typedef struct
{
    char nome[MAX_STR];
    int id;
    int idade;
} Pessoa;


typedef struct
{
    int id_cliente;
    int id_vendedor;
    int codigo;
    float valor;
} Pedido;


typedef struct
{
    Pessoa pessoa;
    Pedido *pedidos;
    float limite_credito;
    int quant_pedidos;
} Cliente;


typedef struct
{
    int tipo_funcionario;
    int id_organizacao;
    float salario;
    Pessoa pessoa;
} Funcionario;


typedef struct {
    int id;
    char nome[MAX_STR];
    float faturamento;
    int quant_funcionario;
    Funcionario *funcionario;
    Pedido *pedidos_efetuados;
} Organizacao;

//===========   FUNÇÕES ALOCAR/LIBERAR MEMÓRIA   ===========
Funcionario *alocarFuncionario(int tam)
{
    Funcionario *vetor = (Funcionario *)malloc(tam * sizeof(Funcionario));

    if(!vetor)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}


void liberarVetor(void *vetor)
{
    free(vetor);
    vetor = NULL;
}
//==========================================================

void limpa_buffer()
{
    while(getchar() != '\n');
}

// Retorna a validade de uma escolha feita pelo user
// VALOR MIN / VALOR MAX / ESCOLHA_CLIENTE
int validar(int min, int max, int escolha)
{
    if(escolha > max || escolha < min) return FALSE;
        
    return TRUE;
}
//----------------------------------------------------------

//================   FUNÇÕES DO CADASTRO   =================
Pessoa cadastrar_pessoa()
{
    Pessoa pessoa;

    printf("Nome da pessoa: ");
    scanf(" %[^\n]s", pessoa.nome);

    quant_pessoas++;
    pessoa.id = quant_pessoas;
    printf("Seu ID é: %d", quant_pessoas);

    printf("\nIdade da pessoa: ");
    scanf(" %d", &pessoa.idade);

    return pessoa;
}

// void cadastrar_pedido();

Cliente cadastrar_cliente(){
    Cliente cliente;
    // Pedido pedido;   
    cliente.pessoa = cadastrar_pessoa();
    printf("digite o valor do credito disponivel: ");
    scanf("%f", &cliente.limite_credito);
    return cliente;
}

Funcionario cadastrar_funcionario(int id_org)
{
    Funcionario funcionario;

    int escolha = 0;
    float salario = 0.0;

    funcionario.pessoa = cadastrar_pessoa();

    do{
        printf("[0] - Gerente\n");
        printf("[1] - Supervisor\n");
        printf("[2] - Vendedor\n");
        printf("Opção: ");
        scanf(" %d", &escolha);
    } 
    while(!validar(0, 2, escolha));

    printf("\nSalario do funcionario: "), scanf("%f", &salario);

    funcionario.salario = salario;

    funcionario.id_organizacao = id_org;

    if(escolha == 0) funcionario.tipo_funcionario = GERENTE;
    else if(escolha == 1) funcionario.tipo_funcionario = SUPERVISOR;
    else funcionario.tipo_funcionario = VENDEDOR;
    
    return funcionario;
}

Organizacao cadastrar_organizacao(){
    Organizacao organizacao;

    printf("\nNome da organização: ");
    scanf("%[^\n]s", organizacao.nome);

    quant_organizacao++;
    organizacao.id = quant_organizacao;
    printf("Id da organização: %d", quant_organizacao);

    organizacao.faturamento = 0;

    printf("\nQuantidade de funcionarios da organização: ");
    scanf(" %d", &organizacao.quant_funcionario);

    organizacao.funcionario = alocarFuncionario(organizacao.quant_funcionario);

    for(int i = 0; i < organizacao.quant_funcionario; i++){ 
        printf("\nInserir dados do %dº funcionario: \n", i+1);
        organizacao.funcionario[i] = cadastrar_funcionario(organizacao.id); 
    }

    return organizacao;
}

int menu_cadastro()
{
    int op;

    do
    {
        printf("\n------[ Menu ]-----");
        printf("\n[1] - Cadastrar Organização");
        printf("\n[2] - Cadastrar Cliente");
        printf("\n[0] - Sair");
        printf("\nOpção: ");
        scanf(" %d", &op);
        limpa_buffer();
    }
    while(!validar(0, 2, op));
    
    return op;
}

void cadastrar(Organizacao *organizacao, Cliente *cliente)
{
    int op = menu_cadastro();

    switch (op)
    {
    case 1:
        *organizacao = cadastrar_organizacao();
        break;

    case 2:
        *cliente = cadastrar_cliente();
        break;
    
    default:
        break;
    }
}
//==========================================================

//=============   FUNÇÕES EXIBIR INFORMAÇÕES   =============
void exibir_pessoa(Pessoa pessoa)
{
    printf("\nNome: %s", pessoa.nome);
    printf("\nID: %d", pessoa.id);
    printf("\nIdade: %d", pessoa.idade);
}


void exibir_cliente(Cliente cliente)
{
    exibir_pessoa(cliente.pessoa);
    printf("\nLimite de crédito: R$%.2f", cliente.limite_credito);
    // printf("\nPedidos: ")
}


// Função para exibir os funcionários
// Recebe o endereço do(s) funcionario(s), a quantidade a ser exibida e o ID da organização
void exibir_funcionarios(Funcionario *funcionario, int quant, int id)
{
    for(int i = 0; i < quant; i++)
    {
        exibir_pessoa(funcionario[i].pessoa);
        if(funcionario[i].tipo_funcionario == GERENTE)
            printf("\n%s", "Gerente");
        else if(funcionario[i].tipo_funcionario == SUPERVISOR)
            printf("\n%s", "Supervisor");
        else if(funcionario[i].tipo_funcionario == VENDEDOR)
            printf("\n%s", "Vendedor");
        printf("\nSalário: R$%.2f", funcionario[i].salario);

        if(id)
            printf("ID da organização: %d", id);
    }
}

void exibir_organizacao(Organizacao organizacao)
{
    printf("\n-----[%s]-----", organizacao.nome);
    printf("\nCódigo da organização: %d", organizacao.id);
    // printf("\nPedidos efetuados: %d", );

    printf("\nFuncionários cadastrados");
    exibir_funcionarios(organizacao.funcionario, organizacao.quant_funcionario, organizacao.id);
}
//==========================================================



//=========================//================================

int main()
{
    Cliente cliente;
    Organizacao organizacao;
    cadastrar(&organizacao, &cliente);
    cadastrar(&organizacao, &cliente);
    exibir_organizacao(organizacao);
    exibir_cliente(cliente);


    return 0;
}