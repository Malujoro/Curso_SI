#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    float preco;
} Produto;

// Função para critério de ordenação do qsort()
int ordena_preco(const void *a, const void *b)
{
    // n1 e n2 recebem o valor do preço de 2 itens(Ponteiro para Produto apontando para Preco)
    float n1 = ((Produto *) a)->preco;
    float n2 = ((Produto *) b)->preco;
    // Para ter precisão de 2 casas decimais, multiplica-se os números por 100
    // (Ex: 1.5 - 0.5 == 150 - 50)
    return (int) ((n1*100) - (n2*100));
}

int ordena_nome(const void *a, const void *b)
{
    return strcmp(((Produto *) a)->nome, ((Produto *) b)->nome);
}

int main()
{
    int i;
    Produto matriz[10] = {
        {"Arroz", 20},
        {"Feijao", 30},
        {"Macarrao", 25},
        {"Caneta", 1.57},
        {"Lapis", 1.56},
        {"Detergente", 15},
        {"Cadeira", 50},
        {"Sabao em po", 40},
        {"Bala", 0.55},
        {"Caderno", 35},
    };

    qsort(matriz, 10, sizeof(Produto), ordena_preco);
    printf("\nLista ordenada por Preço:\n");
    printf("\n%-12s | %s\n", "Nome", "Preço");
    for(i = 0; i < 10; i++)
    {
        printf("%-12s | R$%.2f\n", matriz[i].nome, matriz[i].preco);
    }

    qsort(matriz, 10, sizeof(Produto), ordena_nome);
    printf("\nLista ordenada por Nome:\n");
    printf("\n%-12s | %s\n", "Nome", "Preço");
    for(i = 0; i < 10; i++)
    {
        printf("%-12s | R$%.2f\n", matriz[i].nome, matriz[i].preco);
    }
    return 0;
}