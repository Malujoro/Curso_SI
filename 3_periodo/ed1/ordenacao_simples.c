#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int pos1, int pos2)
{
    int aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}

void exibir_vetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d -> ", vetor[i]);
    printf("Fim\n");
}

void bubble_sort(int *vetor, int tam)
{
    int trocou;
    for(int i = 0; i < tam; i++)
    {
        trocou = 0;
        for(int j = 0; j < tam-1-i; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                troca(vetor, j, j+1);
                trocou = 1;
            }
        }
        if(trocou == 0)
            break;
    }
}

void selection_sort(int *vetor, int tam)
{
    int pos_menor;
    for(int i = 0; i < tam-1; i++)
    {
        pos_menor = i;
        for(int j = i+1; j < tam; j++)
        {
            if(vetor[j] < vetor[pos_menor])
                pos_menor = j;
        }
        if(pos_menor != i)
            troca(vetor, i, pos_menor);
    }
}

void insertion_sort(int *vetor, int tam)
{
    for(int i = 1; i < tam; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(vetor[j] < vetor[j-1])
                troca(vetor, j-1, j);
        }
    }
}

int main()
{
    int tam = 10;
    int vetor1[] = {12, 1, 3, 2, 9, 5, 45, 7, 12, 0};
    int vetor2[] = {12, 1, 3, 2, 9, 5, 45, 7, 12, 0};
    int vetor3[] = {12, 1, 3, 2, 9, 5, 45, 7, 12, 0};

    printf("Vetor antes de ordenar\n");
    exibir_vetor(vetor1, tam);

    bubble_sort(vetor1, 10);
    selection_sort(vetor2, 10);
    insertion_sort(vetor3, 10);
    
    printf("\nVetor ordenado com Bubble\n");
    exibir_vetor(vetor1, tam);

    printf("\nVetor ordenado com Selection\n");
    exibir_vetor(vetor2, tam);

    printf("\nVetor ordenado com Insertion\n");
    exibir_vetor(vetor3, tam);
    return 0;
}