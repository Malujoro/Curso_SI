#include <stdio.h>

int main(void)
{
    float valor, porcento, sal;
    int quant;

    printf("Valor da hora aula: R$");
    scanf("%f", &valor);

    printf("Quantidade de horas de aula: ");
    scanf("%d", &quant);

    printf("Desconto do INSS [%%]: ");
    scanf("%f", &porcento);

    sal = (valor * quant) * (1 - porcento/100);

    printf("Salário: R$%.2f", sal);
    
    return 0;
}