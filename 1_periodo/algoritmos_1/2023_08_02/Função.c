#include <stdio.h>

// Nomes - char
// Codigo - int
//Salario -float
//Dependente - int
//Acrescimo - float
//Salario final - float

char nomes[20][80]; 

int cod_dep[20][2];
//colunas:
//0- codigo
//1- dependentes

float sal_acres_SF[20][3];
//colunas:
//0- salario
//1- acrescimo
//2- salario final


//Declarar Funções:
int cadastro (int q);

void consulta (int q);
//Fim da declaração


int main (){
    int opc, quant = 0;

    do{
        printf("Digite:\n1- Cadastro\n2- Consulta\n3- Sair\nOpção: ");
        scanf("%d", &opc);
        setbuf (stdin, NULL);

        switch (opc)
        {
            case 1: quant = cadastro(quant);
                    break;

            case 2: consulta (quant);
                    break;

            
        }

    } while (opc != 3);
}


//Função Cadastro:
 int cadastro (int q){
    printf("Informe o nome do %d funcionario: ", q+1);
    gets(nomes[q]);
    setbuf (stdin, NULL);
    printf("Digite seu codigo: ");
    scanf("%d", & cod_dep[q] [0]);
    printf("Informe o seu salario: ");
    scanf("%f", & sal_acres_SF[q] [0]);
    printf("Digite a quantidade de depndentes: ");
    scanf("%d", & cod_dep[q] [1]);
    sal_acres_SF[q] [1] = cod_dep[q] [1] * 0.10 * sal_acres_SF[q] [0];
    sal_acres_SF[q] [2] = sal_acres_SF[q] [0] + sal_acres_SF[q] [1];
    q++;
    return q;
}

//Função Consulta:
void consulta (int q){
    int n;

    printf("dados cadastrados:\n");
    for (n = 0; n < q; n++){
        printf("Nome: %s\n\n", nomes[n]);

    }
}
