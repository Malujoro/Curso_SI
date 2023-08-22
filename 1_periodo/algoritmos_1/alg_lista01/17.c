#include <stdio.h>

//  Entrada:
//      Quantidade de Dvd
//      Valor por aluguel

// Atraso = multa de 10% no aluguel
// 1/3 dos Dvd são alugados ao mês
// 1/10 dos alugados são devolvidos no tempo certo

// 2% dos Dvd estragam ao mês
// 1/10 dos estragados são repostos

//  Exibir:
//      Faturamento anual da locadora
//      Quantidade de Dvds após um ano

int main(void)
{
    int quant_dvd, alugados_mes, quant_dvd_estragados, quant_dvd_final;
    float valor_aluguel, valor_atrasados, valor_devolvidos, total;

    printf("Quantidade de Dvds: ");
    scanf("%d", &quant_dvd);

    printf("Valor aluguel: R$");
    scanf("%f", &valor_aluguel);

    alugados_mes = quant_dvd/3;

    valor_devolvidos = (alugados_mes/10) * valor_aluguel;
    valor_atrasados = (alugados_mes * 9/10) * (valor_aluguel * 1.10);
    total = (valor_devolvidos + valor_atrasados) * 12;

    printf("\nFaturamento Anual: R$%.2f", total);
    
    quant_dvd_estragados = ((quant_dvd * 0.02) * 12) * 9 / 10;
    quant_dvd_final = quant_dvd - quant_dvd_estragados;

    printf("\nQuantidade de Dvds após um ano: %d", quant_dvd_final);

    return 0;
}