#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){

    Elemento *lista;
    lista = criaLista();

    for(int i = 0; i < 5; i++)
    {
        lista = addOrdenadoCrescente(lista);
        printf("\nTamanho da lista: %d\n", tamanhoDaLista(lista));
        mostrarLista(lista);
    }

    return 0;
}