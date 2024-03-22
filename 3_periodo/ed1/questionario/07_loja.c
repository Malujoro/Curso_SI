#include <stdio.h>
#include <stdlib.h>

int *obtem_produtos_zerados(int *codigo, int *estoque, int quant, int *quantZerados)
{
    *quantZerados = 0;
    int *vetorZerados = (int *) malloc(quant * sizeof(int));

    for(int i = 0; i < quant; i++)
    {
        if(estoque[i] == 0)
        {
            vetorZerados[*quantZerados] = codigo[i];
            (*quantZerados)++;
            vetorZerados = realloc(vetorZerados, ((*quantZerados) + 1) * sizeof(int));
        }
    }

    return vetorZerados;
}

int main()
{
    int quant, quantZerados = 0;

    printf("Quantidade de produtos: ");
    scanf(" %d", &quant);
    
    int codigo[quant], estoque[quant];

    for(int i = 0; i < quant; i++)
    {
        printf("\n%dº produto:", i+1);
        printf("\nCódigo: ");
        scanf(" %d", &codigo[i]);
        printf("Quantidade em estoque: ");
        scanf(" %d", &estoque[i]);
    }

    int *vetorZerados = obtem_produtos_zerados(codigo, estoque, quant, &quantZerados);

    if(quantZerados > 0)
    {
        printf("\nCódigo dos produtos que não possuem estoque:");
        for(int i = 0; i < quantZerados; i++)
            printf("\n%d", vetorZerados[i]);
        printf("\n");
    }
    free(vetorZerados);
    return 0;
}