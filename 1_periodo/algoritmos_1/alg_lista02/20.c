#include <stdio.h>

/*
    Um endocrinologista deseja controlar a saúde de seus pacientes e, para
    isso, se utiliza do Índice de Massa Corporal (ICM). Sabendo-se que o IMC
    é calculado através da seguinte fórmula:
    
    IMC = peso / altura²

    Onde:
    * peso é dado em Kg;
    * altura é dada em metros.

    Criar um algoritmo que apresente o nome do paciente, seu IMC e sua
    faixa de risco, conforme a seguinte tabela:
*/

int main(void)
{
    float peso, altura, imc;
    char nome[100];

    printf("Nome: ");
    scanf(" %[^\n]s", nome);

    printf("Peso [kg]: ");
    scanf(" %f", &peso);

    printf("Altura [m]: ");
    scanf(" %f", &altura);

    imc = peso / (altura * altura);

    printf("\nPaciente: %s", nome);
    printf("\nIMC: %.1f", imc);    

    if (imc < 20)
        printf("\nAbaixo do peso\n");
    else if (imc < 25)
        printf("\nNormal\n");
    else if (imc < 30)
        printf("\nExcesso de peso\n");
    else if (imc < 35)
        printf("\nObesidade\n");
    else
        printf("\nObesidade Mórbida\n");

    return 0;
}
