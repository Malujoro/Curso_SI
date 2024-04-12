#include <stdio.h>
#include <stdlib.h>

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
///////////////////////////////////////////////////////////////
void print(int x)
{
    if(x > 0)
    {
        print(x-1);
        printf("%d ", x);
    }
}

int multiplicacao(int m, int n)
{
    if(n == 0)
        return 0;
    return m + multiplicacao(m, n-1);
}

int fatorialRecursivo(int num)
{
    if (num > 0)
        return num * fatorialRecursivo(num-1);
    return 1;
}

int somaVetor(int *vetor, int tam)
{
    if(tam == 0)
        return 0;
    return vetor[tam-1] + somaVetor(vetor, tam-1);
}

int fibonacci(int num)
{
    if(num == 0 || num == 1)
        return num;
    return fibonacci(num-1) + fibonacci(num-2);
}

int main()
{
    // int m = 5;
    // int n = 7;
    int tam = 5;
    int *vetor = alocarVetor(5);

    for(int i = 0; i < tam; i++)
        vetor[i] = i+1;

    // print(5);
    // printf("\n%d x %d = %d", m, n, multiplicacao(m, n));
    // printf("\n%d! = %d", m, fatorialRecursivo(m));
    // printf("\n%d = %d", n, fibonacci(n));
    exibirVetor(vetor, tam);
    printf("\nSoma: %d", somaVetor(vetor, tam));
    printf("\n");

    free(vetor);
}