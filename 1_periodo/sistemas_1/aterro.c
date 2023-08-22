#include <stdio.h>

int main(void)
{
    int vida_util;
    float vida_aumentada, porcento;
    float toneladas_ano, capacidade_aterro;

    // Recebe os anos de vida do aterro
    printf("\nVida útil do aterro [anos]: ");
    scanf("%d", &vida_util);

    // Recebe as toneladas de resíduos ao ano
    printf("Toneladas ao ano: ");
    scanf("%f", &toneladas_ano); 

    // Recebe a porcentagem de redução dos resíduos
    printf("Redução do volume de resíduos ao ano [%%]:");
    scanf("%f", &porcento);

    // Calcula a capacidade em toneladas do aterro
    // 10 toneladas ao ano em 15 anos = capacidade de 150 toneladas
    capacidade_aterro = vida_util * toneladas_ano;

    // Aplica a redução das toneladas
    // Divide a capacidade do aterro pelas toneladas já reduzidas
    vida_aumentada = capacidade_aterro / (toneladas_ano - (toneladas_ano * porcento/100));

    // Exibe a nova vida útil do aterro
    printf("\nNova vida útil: %.2f anos\n", vida_aumentada);

    return 0;
}