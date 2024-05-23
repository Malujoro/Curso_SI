#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

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
    elemento->prox = elemento;

    return elemento;
}


Elemento *addInicio(Elemento *l)
{
    Elemento *novo = addElemento();

    if(l != NULL)
    {
        novo->prox = l;

        Elemento *aux = l;
        while(aux->prox != l)
            aux = aux->prox;

        aux->prox = novo;
    }

    return novo;
}

Elemento *addFinal(Elemento *l)
{
    Elemento *novo = addElemento();

    if(l == NULL)
        return novo;

    Elemento *aux = l;
    while(aux->prox != l)
        aux = aux->prox;
    aux->prox = novo;
    novo->prox=l;

    return l;
}

Elemento *addOrdenadoCrescente(Elemento *l)
{
    Elemento *novo = addElemento();

    if(l == NULL)
        return novo;
    
    Elemento *aux = l;

    while(aux->prox != l && aux->prox->info < novo->info)
        aux = aux->prox;
    
    if(aux->info < novo->info)
    {
        novo->prox = aux->prox;
        aux->prox = novo;
        return l;
    }

    novo->prox = aux;
    
    while(aux->prox != l)
        aux = aux->prox;

    aux->prox = novo;
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

    Elemento *aux = l;

    if(l->info == elemento)
    {
        while(aux->prox != l)
            aux = aux->prox;
        
        aux->prox = l->prox;

        l->prox = NULL;
        free(l);
        
        return aux->prox;
    } 

    Elemento *anterior = l;

    while(aux->prox != l)
    {
        
        if(aux->info == elemento)
        {
            if(aux->prox == l)
                anterior->prox = l;
            else
                anterior->prox = aux->prox;
            
            aux->prox = NULL;
            free(aux);
            return l;
        }

        anterior = aux;
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

    while(l->prox != l)
    {
        cont++;
        l = l->prox;
    }
    
    return cont;
}

void mostrarLista(Elemento *l){
    if (l == NULL)
        printf("Lista vazia ");
    else
    {
        Elemento *aux = l;
        do
        {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
        while (aux != l);
    }
}