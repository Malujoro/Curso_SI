#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){

    Elemento *lista;
    lista = criaLista();

    lista = addOrdenadoCrescente(lista);
    lista = addOrdenadoCrescente(lista);
    lista = addOrdenadoCrescente(lista);
    lista = addOrdenadoCrescente(lista);
    lista = addInicio(lista);
    lista = addFinal(lista);

    mostrarLista(lista);
    printf("\nTamanho da lista: %d\n", tamanhoDaLista(lista));

    lista = removerElemento(lista);
    lista = removerElemento(lista);
    mostrarLista(lista);
    printf("\nTamanho da lista: %d\n", tamanhoDaLista(lista));
    return 0;
}