#include <stdio.h>

// A taxa é em porcentagem
float jurosCompostos(float valorInicial, int meses, float taxa)
{
    valorInicial += valorInicial * taxa/100;

    if(meses <= 1)
        return valorInicial;
    
    return jurosCompostos(valorInicial, meses-1, taxa);
}

int main()
{
    float valorInicial = 1000, taxa = 10;
    int meses = 3;

    printf("R$%.2f a %.1f%% de juros por %d meses = R$%.2f\n", valorInicial, taxa, meses, jurosCompostos(valorInicial, meses, taxa));

    return 0;
}