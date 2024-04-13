#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct
{
    char itinerario[MAX_STR];
    char horario[MAX_STR];
    float preco;
} Onibus;

Onibus **alocarOnibus(int lin, int col)
{
    Onibus **matriz = (Onibus **) malloc(lin * sizeof(Onibus *));
    if(!matriz)
    {
        printf("\nErro! Não foi possível alocar a matriz\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < lin; i++)
    {
        matriz[i] = (Onibus *) malloc(col * sizeof(Onibus));
        if(!matriz[i])
        {
            printf("\nErro! Não foi possível alocar a matriz\n");
            exit(EXIT_FAILURE);
        }
    }


    return matriz;
}

void desalocarOnibus(Onibus **onibus, int lin)
{
    for(int i = 0; i < lin; i++)
    {
        free(onibus[i]);
        onibus[i] = NULL;
    }

    free(onibus);
    onibus = NULL;
}


int main()
{
    int quantCidade, quantParada;

    printf("Quantidade de cidades que a empresa trabalha: ");
    scanf(" %d", &quantCidade);

    printf("Quantidade de paradas por cidade: ");
    scanf(" %d", &quantParada);

    Onibus **onibus = alocarOnibus(quantCidade, quantParada);

    for(int i = 0; i < quantCidade; i++)
    {
        printf("\n----- [%dª cidade] -----", i+1);
        for(int j = 0; j < quantParada; j++)
        {
            printf("\n%dª parada: ", j+1);
            scanf(" %[^\n]s", onibus[i][j].itinerario);

            printf("Horário: ");
            scanf(" %[^\n]s", onibus[i][j].horario);

            printf("Preço: R$");
            scanf(" %f", &onibus[i][j].preco);
        }
    }
    
    printf("\nParadas do ônibus: ");
    for(int i = 0; i < quantCidade; i++)
    {
        printf("\n----- [%dª cidade] -----", i+1);
        for(int j = 0; j < quantParada; j++)
        {
            printf("\n%dª parada: %s", j+1, onibus[i][j].itinerario);
            printf("\nHorário: %s", onibus[i][j].horario);
            printf("\nPreço: R$%.2f\n", onibus[i][j].preco);
        }
    }
    desalocarOnibus(onibus, quantCidade);
    return 0;
}