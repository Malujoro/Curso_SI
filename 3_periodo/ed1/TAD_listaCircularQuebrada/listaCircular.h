#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

typedef struct elemento{
    int info;
    struct elemento *prox;
} Elemento;

Elemento *criaLista();

Elemento *addElemento();

Elemento *addInicio(Elemento *l);

Elemento *addFinal(Elemento *l);

Elemento *addOrdenadoCrescente(Elemento *l);

Elemento *removerElemento(Elemento *l);

int tamanhoDaLista(Elemento *l);

void mostrarLista(Elemento *l);

#endif