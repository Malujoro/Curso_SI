#include <stdio.h>
#include <string.h>

struct funcionario
{
    char nome[80], cargo[40];
    float sal_bruto, sal_final;
    int depen;
};


struct funcionario func[50];

int menu()
{
    int esc;
    printf("\n------Menu de opções------");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Sair");

    printf("\n\nDigite sua opção: ");
    scanf("%d", &esc);
    return esc;
}

int cadastro(int quant)
{
    float acrescimo;

    printf("\nNome do funcionário: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", func[quant].nome);
    
    printf("Cargo: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", func[quant].cargo);

    printf("Salário: R$");
    setbuf(stdin, NULL);
    scanf("%f", &func[quant].sal_bruto);

    printf("Quantidade de dependentes: ");
    setbuf(stdin, NULL);
    scanf("%d", &func[quant].depen);

    // Aumenta 10% de salário por dependente
    acrescimo = (func[quant].depen * 0.10) * func[quant].sal_bruto;
    func[quant].sal_final = func[quant].sal_bruto + acrescimo;

    printf("\nCadastro realizado com sucesso!\n");

    quant++;
    return quant;
}

void consulta(int quant)
{
    int l;
    if (quant == 0)
    {
        printf("\nNão há nenhum dado cadastrado");
    }
    else
    {
        for (l = 0; l < quant; l++)
        {
            printf("\nDados do %dº funcionário:", l+1);
            printf("\nNome: %s", func[l].nome);
            printf("\nCargo: %s", func[l].cargo);
            printf("\nSalário bruto: R$%.2f", func[l].sal_bruto);
            printf("\nQuantidade de dependentes: %d", func[l].depen);
            printf("\nSalário final: R$%.2f", func[l].sal_final);
            printf("\n---Fim dados do %dº funcionário---\n", l+1);
        }
    }
    return 0;
}

int main(void)
{
    int n = 0, op;

    do
    {
        printf("\nHá %d funcionários cadastrados!", n);
        op = menu();

        switch (op)
        {
            case 1:
                n = cadastro(n);
                break;
            
            case 2:
                consulta(n);
                break;
            
            case 3:
                printf("\nSaindo...\n");
                break;
            
            default:
                printf("\nOpção inválida");
        }
    } while (op != 3);
    return 0;
}