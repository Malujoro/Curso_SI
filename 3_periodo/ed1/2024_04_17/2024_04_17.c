#include <stdio.h>
#include <stdlib.h>

// TODO Talvez modificar o exibir funcionários / clientes (para cadastrar ID) e o ID da organização é pega pelo próprio funcionário (modificar o exibir funcionários para exibir por "classe")
// TODO Cadastro Cliente possui vetor de pedidos
// TODO Cadastro Organização possui pedidos efetuados
// TODO Criar um "adicionar pedido" (adiciona na organização e cliente)
// TODO Criar um "buscar pedido por organização"

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
int quant_cliente = 0;
int quant_organizacao = 0;
int quant_pedido = 0;


typedef struct
{
    char nome[MAX_STR];
    int id;
    int idade;
} Pessoa;


typedef struct
{
    int id_pedido;
    int id_cliente;
    int id_vendedor;
    int id_organizacao;
    int quant_itens;
    float valor;
    char **itens;
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
    int quant_funcionarios;
    Funcionario *funcionario;
    int quant_pedidos;
    Pedido *pedidos_efetuados;
} Organizacao;

//===========   FUNÇÕES ALOCAR/LIBERAR MEMÓRIA   ===========
Organizacao *alocarOrganizacao(int tam)
{
    Organizacao *vetor = (Organizacao *)malloc(tam * sizeof(Organizacao));

    if(!vetor)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

Cliente *alocarCliente(int tam)
{
    Cliente *vetor = (Cliente *)malloc(tam * sizeof(Cliente));

    if(!vetor)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

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

Pedido *alocarPedido(int tam)
{
    Pedido *vetor = (Pedido *)malloc(tam * sizeof(Pedido));

    if(!vetor)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

char **alocarMatrizStr(int lin, int col)
{
    char **matriz = (char **)malloc(lin * sizeof(char *));

    if(!matriz)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < lin; i++)
    {
        matriz[i] = (char *)malloc(col * sizeof(char));
        if(!matriz)
        {
            printf("Erro ao alocar memória!");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}

void liberarVetor(void *vetor)
{
    free(vetor);
    vetor = NULL;
}

void liberarMatriz(void **matriz, int lin)
{
    for(int i = 0; i < lin; i++)        
        liberarVetor(matriz[i]);
        
    free(matriz);
    matriz = NULL;
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

//================   FUNÇÕES DE MENU   =================

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

int menu_exibir()
{
    int op;

    do
    {
        printf("\n------[ Menu ]-----");
        printf("\n[1] - Exibir Organizações");
        printf("\n[2] - Exibir Cliente");
        printf("\n[3] - Exibir Pedidos por Organização");
        printf("\n[4] - Exibir Pedidos por Cliente");
        printf("\n[0] - Sair");
        printf("\nOpção: ");
        scanf(" %d", &op);
        limpa_buffer();
    }
    while(!validar(0, 2, op));
    
    return op;
}

int menu()
{
    int op;

    do
    {
        printf("\n------[ Menu ]-----");
        printf("\n[1] - Cadastrar");
        printf("\n[2] - Exibir");
        printf("\n[0] - Sair");
        printf("\nOpção: ");
        scanf(" %d", &op);
        limpa_buffer();
    }
    while(!validar(0, 2, op));
    
    return op;
}

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

Pedido cadastrar_pedido(Organizacao *organizacao, int id_cliente)
{
    // Modificar talvez o void cadastrar_pedido pra receber o Cliente *cliente, e já adicionar ele ao vetor da organização e do cliente
    Pedido pedido;
    
    do
    {
        printf("\nQuantidade de pedidos realizada: ");
        scanf("%d", &pedido.quant_itens);
    }while(pedido.quant_itens  <= 0);

    pedido.itens = alocarMatrizStr(pedido.quant_itens, MAX_STR);

    for(int i = 0; i < pedido.quant_itens; i++)
    {
        printf("%d item: ", i + 1);
        scanf("%[^\n]", pedido.itens[i]);
    }

    printf("Valor do Pedido: ");
    scanf("%f", &pedido.valor);

    // TODO Exibir os funcionários e escolher o "vendedor"
    // TODO Criar a função de busca de funcionário
    // TODO Adicionar o pedido na organização
    // TODO Adicionar ao faturamento da organização

    // pedido.id_vendedor = ;
    pedido.id_cliente = id_cliente;
    // pedido.id_organizacao = funcionario.id_organizacao;
    

    quant_pedido++;

    pedido.id_pedido = quant_pedido;

    return pedido;
}

Cliente cadastrar_cliente(){
    Cliente cliente;

    cliente.pedidos = alocarPedido(1);
    cliente.quant_pedidos = 0;

    cliente.pessoa = cadastrar_pessoa();
    printf("Digite o valor do credito disponivel: ");
    scanf("%f", &cliente.limite_credito);

    quant_cliente++;
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

    organizacao.pedidos_efetuados = alocarPedido(1);
    organizacao.quant_pedidos = 0;

    printf("\nNome da organização: ");
    scanf("%[^\n]s", organizacao.nome);

    quant_organizacao++;
    organizacao.id = quant_organizacao;
    printf("Id da organização: %d", quant_organizacao);

    organizacao.faturamento = 0;

    do
    {
        printf("\nQuantidade de funcionarios da organização: ");
        scanf(" %d", &organizacao.quant_funcionarios);
    }while(organizacao.quant_funcionarios <= 0);

    organizacao.funcionario = alocarFuncionario(organizacao.quant_funcionarios);

    for(int i = 0; i < organizacao.quant_funcionarios; i++){ 
        printf("\nInserir dados do %dº funcionario: \n", i+1);
        organizacao.funcionario[i] = cadastrar_funcionario(organizacao.id); 
    }

    return organizacao;
}

void cadastrar(Organizacao *organizacao, Cliente *cliente)
{
    int op;
    
    do
    {
        op = menu_cadastro();

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
    }while(op != 0);
}
//==========================================================

//=============   FUNÇÕES EXIBIR INFORMAÇÕES   =============
void exibir_pessoa(Pessoa pessoa)
{
    printf("\nNome: %s", pessoa.nome);
    printf("\nID: %d", pessoa.id);
    printf("\nIdade: %d", pessoa.idade);
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
            printf("\nID da organização: %d", id);
    }
}
void exibir_pedidos(Pedido *pedido, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        printf("ID DO PEDIDO:\t %05d\n", pedido->id_pedido);
        printf("ID DO CLIENTE:\t %d\n", pedido->id_cliente);
        printf("ID DO FUNCIONARIO:\t %d\n", pedido->id_vendedor);
        printf("ITENS: %d\n", pedido->id_pedido);
        
        for(int i = 0; i < pedido->quant_itens; i++)
            printf("%d° - %s\n", i + 1, pedido->itens[i]);
        
        printf("VALOR DO PEDIDO:\t %.2f\n", pedido->valor);
    }
}

void exibir_cliente(Cliente cliente)
{
    if(quant_cliente)
    {
        exibir_pessoa(cliente.pessoa);
        printf("\nLimite de crédito: R$%.2f", cliente.limite_credito);
        
        printf("\n----- [ PEDIDOS REALIZADOS ] -----\n");
        exibir_pedidos(cliente.pedidos, cliente.quant_pedidos);
    }
    else
        printf("Não existem clientes cadastrados");
}

void exibir_organizacao(Organizacao organizacao)
{
    if(quant_organizacao)
    {
        printf("\n----- [ %s ] -----\n", organizacao.nome);
        printf("\nCódigo da organização: %d", organizacao.id);
        
        printf("\n----- [ PEDIDOS REALIZADOS ] -----\n");
        exibir_pedidos(organizacao.pedidos_efetuados, organizacao.quant_pedidos);

        printf("\nFuncionários cadastrados");
        printf("\n----- [ FUNCIONÁRIOS CADASTRADOS ] -----\n");
        exibir_funcionarios(organizacao.funcionario, organizacao.quant_funcionarios, organizacao.id);
    }    
    else
        printf("Não existem organizações cadastradas");
}

void exibir(Organizacao *organizacao, Cliente *cliente)
{
    int op;

    do
    {
        op = menu_exibir();
        
        switch(op)
        {
            case 1:
                exibir_organizacao(*organizacao);
                break;
            case 2:
                exibir_cliente(*cliente);
                break;
        }

    }while(op != 0);
}
//==========================================================



//=========================//================================

int main()
{
    int op;
    Cliente *cliente = alocarCliente(1);
    Organizacao *organizacao = alocarOrganizacao(1);

    do
    {
        op = menu();

        switch(op)
        {
            case 1:
                cadastrar(organizacao, cliente);
                break;
            case 2:
                exibir(organizacao, cliente);
                break;
        }
    }while(op != 0);
    return 0;
}