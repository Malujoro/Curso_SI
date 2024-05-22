#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Elemento *criaLista(){
    return NULL;
}

Elemento *addElemento()
{
    Elemento *elemento = (Elemento *) malloc(sizeof(Elemento));

    if(!elemento)
    {
        printf("Erro ao criar elemento");
        exit(1);
    }
    
    scanf(" %d", &elemento->info);
    elemento->prox = NULL;

    return elemento;

}

Elemento *addInicio(Elemento *l){
    //criar novo elemento
    Elemento *novo = addElemento();
    //ajustar o valor do ponteiro para o prox elemento
    novo->prox = l;
    return novo;
}

Elemento *addFinal(Elemento *l)
{
    Elemento *novo = addElemento();

    if(l == NULL)
        return novo;

    Elemento *aux = l;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;

    return l;
}

Elemento *addOrdenadoCrescente(Elemento *l)
{
    Elemento *novo = addElemento();

    if(l == NULL)
        return novo;
    
    Elemento *aux = l;

    while(aux->prox != NULL && aux->prox->info < novo->info)
        aux = aux->prox;
    
    if(aux->info < novo->info)
    {
        novo->prox = aux->prox;
        aux->prox = novo;
        return l;
    }

    novo->prox = aux;
    return novo;

}

Elemento *removerElemento(Elemento *l)
{
    if(l == NULL)
    {
        printf("\nNão é possível remover o elemento, a lista está vazia\n");
        return l;
    }

    int elemento;
    scanf(" %d", &elemento);

    Elemento *auxiliar;

    if(l->info == elemento)
    {
        auxiliar = l->prox;
        free(l);
        return auxiliar;
    }

    Elemento *aux = l;

    while(aux->prox != NULL)
    {
        if(aux->prox->info == elemento)
        {
            auxiliar = aux->prox;
            aux->prox = aux->prox->prox;
            free(auxiliar);
            return l;
        }
        aux = aux->prox;
    }
    
    printf("\nElemento não encontrado\n");
    return l;
}

int tamanhoDaLista(Elemento *l)
{
    if(l == NULL)
        return 0;

    int cont = 1;
    while(l->prox != NULL)
    {
        cont++;
        l = l->prox;
    }
    return cont;
}

void mostrarLista(Elemento *l){
    if (l == NULL)
        printf("Lista vazia ");
    else{
        Elemento *aux = l;
        while (aux != NULL)
        {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
    }
}