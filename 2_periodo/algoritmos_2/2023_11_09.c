#include <stdio.h>

void preencher(int vetor[], int tam)
{
    int i;

    for(i = 0; i < tam; i ++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }
}

int buscar(int vetor[], int tam, int valor)
{
    int i;

    printf("\nValor %d ", valor);
    for(i = 0; i < tam; i++)
    {
        if(vetor[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

void exibir(int vetor[], int tam)
{
    int i;

    printf("\n");
    for(i = 0; i < tam; i ++)
    {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}

void ordena_vetor(int vetor[], int tam)
{
    int i, j, aux, menor, posicao;

    if(tam >= 0)
    {
        for(i = 0; i < tam; i++)
        {
            menor = vetor[i];
            posicao = i;
            for(j = i+1; j < tam; j++)
            {
                if(vetor[j] < menor)
                {
                    posicao = j;
                    menor = vetor[j];
                }
            }
            aux = vetor[posicao];
            vetor[posicao] = vetor[i];
            vetor[i] = aux;
        }
    }
}

void ordena_vetor2(int vetor[], int tam, int vetor2[])
{
    int i, j, aux, menor, posicao;

    if(tam >= 0)
    {
        for(i = 0; i < tam; i++)
        {
            menor = vetor[i];
            posicao = i;
            for(j = i+1; j < tam; j++)
            {
                if(vetor[j] < menor)
                {
                    posicao = j;
                    menor = vetor[j];
                }
            }
            aux = vetor[posicao];
            vetor[posicao] = vetor[i];
            vetor[i] = aux;
        }
    }
}

int main()
{
    int tam;
    // int valor, posicao; 
    
    printf("\nTamanho do vetor: ");
    scanf(" %d", &tam);

    int vetor[tam], vetor2[tam];

    preencher(vetor, tam);
    ordena_vetor(vetor, tam);
    exibir(vetor, tam);

    ordena_vetor2(vetor, tam, vetor2);
    exibir(vetor2, tam);

    // printf("\nQual valor deseja buscar? ");
    // scanf(" %d", &valor);

    // posicao = buscar(vetor, tam, valor);

    // if(posicao >= 0)
    //     printf("encontrado na posição %d\n", posicao);
    // else
    //     printf("não foi encontrado\n");
    
    return 0;
}