#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int c;
    int h;
} Hidrocarboneto;

Hidrocarboneto *alocarHidrocarboneto(int tam)
{
    Hidrocarboneto *vetor = (Hidrocarboneto *) malloc(tam * sizeof(Hidrocarboneto));
    
    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void liberarVetor(Hidrocarboneto *vetor)
{
    free(vetor);
    vetor = NULL;
}


int main()
{
    Hidrocarboneto *hidrocarboneto = alocarHidrocarboneto(1);    

    printf("Quantidade de Carbonos: ");
    scanf(" %d", &hidrocarboneto[0].c);

    printf("Quantidade de Hidrogênios: ");
    scanf(" %d", &hidrocarboneto[0].h);

    int massa = (hidrocarboneto[0].c * 12) + (hidrocarboneto[0].h * 1);

    printf("Massa molecular do composto: %d", massa);

    liberarVetor(hidrocarboneto);
    return 0;
}