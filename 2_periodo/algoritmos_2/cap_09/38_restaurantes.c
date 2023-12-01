#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct restaurante
{
    char nome[100];
    char endereco[100];
    float preco;
    char tipo[100];
    struct restaurante *proximo;
} Restaurante;

Restaurante *cadastro(Restaurante *primeiro)
{
    Restaurante *novo = (Restaurante *) malloc(sizeof(Restaurante));
    Restaurante *atual;

    printf("Nome do restaurante: ");
    scanf(" %[^\n]s", novo->nome);
    
    printf("Endereço do restaurante: ");
    scanf(" %[^\n]s", novo->endereco);
    
    printf("Preço médio: R$");
    scanf(" %f", &novo->preco);
    
    printf("Tipo de comida: ");
    scanf(" %[^\n]s", novo->tipo);

    //  Se o primeiro item for nulo (não houver nenhum cadastrado)
    //  Ou o preço digitado for menor que o preço do primeiro item
    // Então o novo item vai ser se tornar o primeiro elemento da lista
    if(primeiro == NULL || novo->preco < primeiro->preco)
    {
        // O próximo endereço vai ser Nulo (caso seja o primeiro) ou o valor do "antigo primeiro"
        novo->proximo = primeiro;
        primeiro = novo;
    }
    else
    {
        // Atual recebe o endereço do primeiro item.
        //  Se o endereço não for do último item (não existe um seguinte)
        //  E o preço do item seguinte for menor que o do novo
        // Então Atual recebe o endereço do próximo item (percorrendo assim a lista e encontrando a posição certa para o novo item)
        for(atual = primeiro; (atual->proximo != NULL) && ((atual->proximo)->preco < novo->preco); atual = atual->proximo);

        // O próximo endereço vai ser Nulo (caso seja o último) ou o valor do "antigo" item dessa posição
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    return primeiro;
}

void exibir_item(Restaurante *primeiro)
{
    printf("Restaurante: %s", primeiro->nome);
    printf("\nEndereço: %s", primeiro->endereco);
    printf("\nPreço médio: R$%.2f", primeiro->preco);
    printf("\nTipo de comida: %s", primeiro->tipo);
    printf("\n-------------------------\n");
}

void exibir_tudo(Restaurante *primeiro)
{
    Restaurante *atual;
    for(atual = primeiro; atual != NULL; atual = atual->proximo)
        exibir_item(atual);
}

void exibir_especifico(Restaurante *primeiro, char *tipo)
{
    Restaurante *atual;
    for(atual = primeiro; atual != NULL; atual = atual->proximo)
    {
        if(strcasecmp(atual->tipo, tipo) == 0)
            exibir_item(atual);
    }
}

int main()
{
    Restaurante *primeiro = NULL;
    char op, tipo[100];

    do
    {
        primeiro = cadastro(primeiro);
        printf("\nContinuar? [s/n] ");
        scanf(" %c", &op);
        printf("-------------------------\n");
    }while(op != 'N' && op != 'n');

    printf("Qual tipo de comida deseja? ");
    scanf(" %[^\n]s", tipo);
    printf("-------------------------\n");
    exibir_especifico(primeiro, tipo);

    return 0;
}