#include <stdio.h>
#include <stdlib.h>

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
    Pedido **pedidos;
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
    Pedido **pedidos_efetuados;
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


Pedido *alocarPedidoVetor(int tam)
{
    Pedido *vetor = (Pedido *)malloc(tam * sizeof(Pedido));

    if(!vetor)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}


Pedido **alocarPedidoMatriz(int tam)
{
    Pedido **matriz = (Pedido **)malloc(tam * sizeof(Pedido *));

    if(!matriz)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tam; i++)
        matriz[i] = alocarPedidoVetor(1);

    return matriz;
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

Pedido **realocarPedido(Pedido **ponteiro, int novoTam)
{
    Pedido **aux = (Pedido **) realloc(ponteiro, novoTam * sizeof(Pedido *));

    if(!aux)
    {
        printf("\nErro ao realocar memória");
        return ponteiro;   
    }
    return aux;
}


Cliente *realocarCliente(Cliente *ponteiro, int novoTam)
{
    Cliente *aux = (Cliente *) realloc(ponteiro, novoTam * sizeof(Cliente));

    if(!aux)
    {
        printf("\nErro ao realocar memória");
        return ponteiro;   
    }
    return aux;
}

Organizacao *realocarOrganizacao(Organizacao *ponteiro, int novoTam)
{
    Organizacao *aux = (Organizacao *) realloc(ponteiro, novoTam * sizeof(Organizacao));

    if(!aux)
    {
        printf("\nErro ao realocar memória");
        return ponteiro;   
    }
    return aux;
}

//==========================================================

void limpa_buffer() { while(getchar() != '\n'); }

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
        printf("\n--------[ Menu ]--------");
        printf("\n[1] - Cadastrar Organização");
        printf("\n[2] - Cadastrar Cliente");
        printf("\n[3] - Cadastrar Pedido");
        printf("\n[0] - Sair");
        printf("\nOpção: ");
        scanf(" %d", &op);
        limpa_buffer();
    }
    while(!validar(0, 3, op));
    
    return op;
}

int menu_exibir()
{
    int op;

    do
    {
        printf("\n------------------ [ Menu ] ---------------------");
        printf("\n[1] - Exibir Todas as Organizações, seus funcionários e pedidos");
        printf("\n[2] - Exibir Todos os Clientes e seus pedidos");
        printf("\n[3] - Exibir Todos os Pedidos por Organização");
        printf("\n[0] - Sair");
        printf("\nOpção: ");
        scanf(" %d", &op);
        limpa_buffer();
    }
    while(!validar(0, 3, op));
    
    return op;
}

int menu()
{
    int op;

    do
    {
        printf("\n---------[ Menu ]--------");
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

//================   FUNÇÕES DE BUSCA   =================

int buscar_organizacao(Organizacao *organizacao, int id_org)
{   
    for(int i = 0; i < quant_organizacao; i++)
    {
        if(organizacao[i].id == id_org)
            return i;
    }
    printf("\nNão existe organização com esse id!\n");
    return -1;
}

// RETORNA A POSIÇÃO DO FUNCIONARIO NA ORGANIZAÇÃO
int buscar_funcionario(Funcionario *funcionario, int id_func, int quant_func)
{   
    for(int i = 0; i < quant_func; i++)
    {
        if(funcionario->pessoa.id == id_func)
            return i;
    }
    printf("\nNão existe funcionario com esse id!\n");
    return -1;
}


int buscar_cliente(Cliente *cliente, int id_cli)
{   
    for(int i = 0; i < quant_organizacao; i++)
    {
        if(cliente[i].pessoa.id == id_cli)
            return i;
    }
    printf("\nNão existe cliente com esse id!\n");
    return -1;
}

//=============   FUNÇÕES EXIBIR INFORMAÇÕES   =============
void exibir_pessoa(Pessoa pessoa)
{
    printf("\n\nNome: %s", pessoa.nome);
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
        printf("\nCargo: ");
        if(funcionario[i].tipo_funcionario == GERENTE)
            printf("%s", "Gerente");
        else if(funcionario[i].tipo_funcionario == SUPERVISOR)
            printf("%s", "Supervisor");
        else if(funcionario[i].tipo_funcionario == VENDEDOR)
            printf("%s", "Vendedor");
        printf("\nSalário: R$%.2f", funcionario[i].salario);

        if(id)
            printf("\nID da organização: %d", id);
        printf("\n");
    }
}

void exibir_pedidos(Pedido **pedido, int quant)
{
    for(int i = 0; i < quant; i++)
    {
        printf("\nID DO PEDIDO............. %05d\n", pedido[i]->id_pedido);
        printf("ID DO CLIENTE............ %d\n", pedido[i]->id_cliente);
        printf("ID DO FUNCIONARIO........ %d\n", pedido[i]->id_vendedor);
        printf("VALOR DO PEDIDO..........R$%.2f\n", pedido[i]->valor);
        printf("ITENS: \n");
        
        for(int j = 0; j < pedido[i]->quant_itens; j++)
            printf("%d° - %s\n", j + 1, pedido[i]->itens[j]);
        
    }
}

void exibir_cliente(Cliente cliente, int pedidos)
{
    if(quant_cliente)
    {
        printf("\n----- [ CLIENTE ] -----");
        exibir_pessoa(cliente.pessoa);
        printf("\nLimite de crédito: R$%.2f\n", cliente.limite_credito);
        
        if(pedidos)
        {
            printf("\n----- [ PEDIDOS REALIZADOS ] -----\n");
            exibir_pedidos(cliente.pedidos, cliente.quant_pedidos);
        }
    }
    else
        printf("\nNão existem clientes cadastrados\n");
}

void exibir_todos_clientes(Cliente *cliente, int pedidos)
{
    if(quant_cliente)
    {
        for(int i = 0; i < quant_cliente; i++)
            exibir_cliente(cliente[i], pedidos);
    }
    else
        printf("\nNão existem clientes cadastrados\n");
}

// Função para exibir uma organização
// Recebe a organização e "se deve exibir os pedidos e funcionários" (0 para não exibir)
void exibir_organizacao(Organizacao organizacao, int pedidos, int funcionarios)
{
    if(quant_organizacao)
    {
        printf("\n----- [ %s ] -----\n", organizacao.nome);
        printf("\nCódigo da organização: %d\n", organizacao.id);
        
        if(pedidos)
        {
            printf("\nFaturamento da organização: R$%.2f\n", organizacao.faturamento);
            printf("\n----- [ PEDIDOS REALIZADOS ] -----\n");
            exibir_pedidos(organizacao.pedidos_efetuados, organizacao.quant_pedidos);
        }

        if(funcionarios)
        {
            printf("\n----- [ FUNCIONÁRIOS CADASTRADOS ] -----\n");
            exibir_funcionarios(organizacao.funcionario, organizacao.quant_funcionarios, organizacao.id);
        }
    }    
    else
        printf("\nNão existem organizações cadastradas\n");
}

void exibir_todas_organizacoes(Organizacao *organizacao, int pedidos, int funcionarios)
{
    if(quant_organizacao)
    {
        for(int i = 0; i < quant_organizacao; i++)
            exibir_organizacao(organizacao[i], pedidos, funcionarios);
    }
    else
        printf("\nNão existem organizações cadastradas\n");
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
                exibir_todas_organizacoes(organizacao, organizacao->quant_pedidos, 1);
                break;
            case 2:
                exibir_todos_clientes(cliente, cliente->quant_pedidos);
                break;
            case 3:
                exibir_todas_organizacoes(organizacao, 1, 0);
                break;
        }

    }while(op != 0);
}
//==========================================================

//================   FUNÇÕES DE ESCOLHA   =================

int escolha_cliente(Cliente *cliente)
{
    int pos_cli, id;
    printf("\nLISTA DE CLIENTES!");
    do{
        exibir_todos_clientes(cliente, 0);
        printf("\nQual o ID do cliente que realizou o pedido?\n-> ");
        scanf("%d", &id);

        pos_cli = buscar_cliente(cliente, id);
    }
    while(pos_cli == -1);
    
    return pos_cli;
}

int escolha_organizacao(Organizacao *organizacao)
{
    int pos_org, id;
    printf("\nLISTA DE ORGANIZAÇÕES!\n");
    do{
        exibir_todas_organizacoes(organizacao, 0, 0);
        printf("\nQual o ID da organização em que foi realizado o pedido?\n-> ");
        scanf("%d", &id);

        pos_org = buscar_organizacao(organizacao, id);
    }
    while(pos_org == -1);
    
    return pos_org;
}

int escolha_funcionario(Funcionario *funcionario, int quant)
{
    int id, pos_func;
    do{
        printf("\nLISTA DE FUNCIONARIOS!\n");
        exibir_funcionarios(funcionario, quant, 0);
        
        printf("\nQual ID do funcionario que realizou o atendimento?\n-> ");
        scanf("%d", &id);

        pos_func = buscar_funcionario(funcionario, id, quant);
    }
    while(pos_func == -1);
 
    return pos_func;
}

//================   FUNÇÕES DO CADASTRO   =================

Pessoa cadastrar_pessoa()
{
    Pessoa pessoa;

    printf("\nNome da pessoa: ");
    scanf(" %[^\n]s", pessoa.nome);

    quant_pessoas++;

    pessoa.id = quant_pessoas;
    printf("Seu ID é: %d", quant_pessoas);

    printf("\nIdade da pessoa: ");
    scanf(" %d", &pessoa.idade);

    return pessoa;
}


void cadastrar_pedido(Organizacao *organizacao, Cliente *cliente)
{

    if(quant_organizacao && quant_cliente)
    {
        Pedido *pedido = alocarPedidoVetor(1);
        int pos_cli = escolha_cliente(cliente);

        printf("\nValor do Pedido: R$");
        scanf("%f", &pedido->valor);
        if (pedido->valor > cliente[pos_cli].limite_credito)
        {
            printf("\nO cliente não tem crédito suficiente!\n");
            liberarVetor(pedido);
        }
        else{
            do
            {
                printf("\nQuantidade de produtos do pedido: ");
                scanf("%d", &pedido->quant_itens);
                limpa_buffer();
            }while(pedido->quant_itens  <= 0);
            
            pedido->itens = alocarMatrizStr(pedido->quant_itens, MAX_STR);

            for(int i = 0; i < pedido->quant_itens; i++)
            {
                printf("%d° item: ", i + 1);
                scanf("%[^\n]s", pedido->itens[i]);
                limpa_buffer();
            }
            
            int pos_org = escolha_organizacao(organizacao);
            int pos_func = escolha_funcionario(organizacao[pos_org].funcionario, organizacao[pos_org].quant_funcionarios);

            quant_pedido++;

            pedido->id_pedido = quant_pedido;

            pedido->id_vendedor = organizacao[pos_org].funcionario[pos_func].pessoa.id;
            pedido->id_cliente = cliente[pos_cli].pessoa.id;
            pedido->id_organizacao = organizacao[pos_org].id;

            organizacao[pos_org].pedidos_efetuados = realocarPedido(organizacao[pos_org].pedidos_efetuados, organizacao[pos_org].quant_pedidos + 2);

            organizacao[pos_org].pedidos_efetuados[organizacao[pos_org].quant_pedidos] = pedido;
            organizacao[pos_org].quant_pedidos += 1;
            organizacao[pos_org].faturamento += pedido->valor;

            cliente[pos_cli].pedidos = realocarPedido(cliente[pos_cli].pedidos, cliente[pos_cli].quant_pedidos + 2);

            cliente[pos_cli].pedidos[cliente[pos_cli].quant_pedidos] = pedido;
            cliente[pos_cli].quant_pedidos += 1;
        }
    }
}

Cliente cadastrar_cliente()
{
    Cliente cliente;

    cliente.pedidos = alocarPedidoMatriz(1);
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
        printf("\n[0] - Gerente\n");
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

Organizacao cadastrar_organizacao()
{
    Organizacao organizacao;

    organizacao.pedidos_efetuados = alocarPedidoMatriz(1);
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

void cadastrar(Organizacao **organizacao, Cliente **cliente)
{
    int op;
    
    do
    {
        op = menu_cadastro();

        switch (op)
        {
        case 1:
            *organizacao = realocarOrganizacao(*organizacao, quant_organizacao + 2);
            (*organizacao)[quant_organizacao] = cadastrar_organizacao();
            break;

        case 2:
            *cliente = realocarCliente(*cliente, quant_cliente + 2 );
            (*cliente)[quant_cliente] = cadastrar_cliente();
            break;
        case 3:
            cadastrar_pedido(*organizacao, *cliente);
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
                cadastrar(&organizacao, &cliente);
                break;
            case 2:
                exibir(organizacao, cliente);
                break;
        }
    }while(op != 0);

    for(int i = 0; i < quant_cliente; i++)
        liberarMatriz((void **) cliente[i].pedidos, cliente[i].quant_pedidos);

    for(int i = 0; i < quant_organizacao; i++)
    {
        for(int j = 0; j < organizacao[i].quant_pedidos; i++)
            liberarMatriz((void **) organizacao[i].pedidos_efetuados[j]->itens, organizacao[i].pedidos_efetuados[j]->quant_itens);
        
        liberarVetor((void *) organizacao[i].funcionario);
        liberarMatriz((void **) organizacao[i].pedidos_efetuados, organizacao[i].quant_pedidos);
    }

    return 0;
}