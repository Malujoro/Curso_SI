#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocarVetor(int tam)
{
    int *vetor = (int *) malloc(tam * sizeof(int));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void preencherVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i+1);
        scanf(" %d", &vetor[i]);
    }
}

void exibirVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
}

void ler_aposta(int *aposta, int n)
{
    int quant = 0;

    do
    {
        printf("\n%dº Número: ", quant+1);
        scanf(" %d", &aposta[quant]);

        if(!(aposta[quant] >= 0 && aposta[quant] <= 100))
        {
            printf("\nErro! Digite números 0 e 100\n");
            continue;
        }

        for(int i = 0; i < quant; i++)
        {
            if(aposta[i] == aposta[quant])
            {
                printf("\nErro! Número já digitado anteriormente\n");
                quant--;
                break;
            }
        }

        quant++;
    }while(quant < n);
}

// void sorteia_valores(int *sorteio, int n)
void sorteia_valores(int *sorteio)
{
    int quant = 0;

    do
    {
        sorteio[quant] = rand() % 101;

        for(int i = 0; i < quant; i++)
        {
            if(sorteio[i] == sorteio[quant])
            {
                quant--;
                break;
            }
        }

        quant++;
    }while(quant < 20);
    // }while(quant < n);
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
    *qtdacertos = 0;
    int *acertos = alocarVetor(na);

    for(int i = 0; i < na; i++)
    {
        for(int j = 0; j < ns; j++)
        {
            if(aposta[i] == sorteio[j])
            {
                acertos[*qtdacertos] = aposta[i];
                (*qtdacertos)++;
                break;
            }
        }
    }

    acertos = (int *) realloc(acertos, (*qtdacertos) * sizeof(int));
    return acertos;
}

int main()
{
    int quant, quantAcertos;

    srand(time(NULL));

    do
    {
        printf("Quantidade de números apostados (entre 1 e 20): ");
        scanf(" %d", &quant);
    }while(!(quant >= 1 && quant <= 20));

    int *aposta = alocarVetor(quant);
    ler_aposta(aposta, quant);

    int *sorteio = alocarVetor(20);
    sorteia_valores(sorteio);

    int *acertos = compara_aposta(aposta, sorteio, &quantAcertos, quant, 20);

    printf("\nNúmeros apostados: ");
    exibirVetor(aposta, quant);

    printf("\nValores sorteados: ");
    exibirVetor(sorteio, 20);

    printf("\nNúmeros acertados: ");
    exibirVetor(acertos, quantAcertos);

    free(aposta);
    free(sorteio);
    free(acertos);
    return 0;
}