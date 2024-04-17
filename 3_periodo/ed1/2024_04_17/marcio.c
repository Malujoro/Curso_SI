#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

// Tipos do Funcionário
#define GERENTE 0
#define SUPERVISOR 1
#define VENDEDOR 2

// Tipos do Organizacao
#define PUBLICA 0
#define PRIVADA 1

typedef struct
{
    char nome[MAX_STR];
    int id;
    int idade
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
    float limite_credito;
    Pedido *pedidos;
} Cliente;

typedef struct
{
    Pessoa pessoa;
    int tipo_funcionario;
} Funcionario;

typedef struct {
    Funcionario *funcionario;
    int quant_funcionario;
    char nome[MAX_STR];
    int id;
    float faturamento;
    Pedido *pedidos_efetuados;
} Organizacao;

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

int menu()
{
    int op;

    return op;
}

Pessoa cadastrar_pessoa()
{
    Pessoa pessoa;

    printf("Nome da pessoa: ");
    scanf(" %[^\n]s", pessoa.nome);  //%[^\n]s
    
    printf("ID pessoa: ");
    printf("Idade da pessoa: ");

    

}

// void cadastrar_pedido();
void  cadastrar_cliente(int *quant,){
    Cliente *cliente;
    
}
Funcionario cadastrar_funcionario(){
    Funcionario funcionario;
    
    cadastrar_pessoa(funcionario);

    do
    {
        /* code */
    } 
    while ();
    

    printf("[0] - Gerente\n");
    printf("[1] - Supervisor\n");
    printf("[2] - Vendedor\n");
}

Organizacao cadastrar_organizacao(){
    Organizacao organizacao;

    printf("Nome da organização: ");
    scanf("%[^\n]s", organizacao.nome);

    organizacao.id = i; //num sabo como fica (ainda);
    printf("Id da organização: %d", i);

    organizacao.faturamento = 0;

    printf("Quantidade de funcionarios da organização: ");
    scanf("%d", &organizacao.quant_funcionario);

    organizacao.funcionario = alocarFuncionario(organizacao.quant_funcionario);

    for(int i = 0; i < organizacao.quant_funcionario; i++)
        organizacao.funcionario[i] = cadastrar_funcionario(); 

}

void cadastrar();

int main()
{

    return 0;
}