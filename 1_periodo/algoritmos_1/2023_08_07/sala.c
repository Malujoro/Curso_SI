#include <stdio.h>

struct funcionario
{
    char nome[80];
    char cargo[40];
    float salario;
};

int main(void)
{
    struct funcionario func[5];
    int n, quant = 2;

    for (n = 0; n < quant; n++)
    {
        printf("\n%dº Funcionário:\n", n+1);
        printf("Nome: ");
        scanf("%[^\n]", func[n].nome);
        setbuf(stdin, NULL);

        printf("Cargo: ");
        scanf("%[^\n]", func[n].cargo);
        setbuf(stdin, NULL);
        
        printf("Salário: R$");
        scanf("%f", &func[n].salario);
        setbuf(stdin, NULL);
    }

    for (n = 0; n < quant; n++)
    {
        printf("\n%dº Funcionário:", n+1);
        printf("\nNome: %s", func[n].nome);
        printf("\nCargo: %s", func[n].cargo);
        printf("\nSalário: R$%.2f\n", func[n].salario);
    }
    return 0;
}