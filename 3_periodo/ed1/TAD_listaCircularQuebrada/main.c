#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"
#include "listaCircular.c"

int main()
{

    Elemento *lista;
    lista = criaLista();

    for(int i = 0; i < 5; i++)
    {
        lista = addOrdenadoCrescente(lista);
        mostrarLista(lista);
        
    }
    printf("Looping For finalizado");

    int var = tamanhoDaLista(lista);
    printf("\nTamanho da lista: %d\n", var);
    mostrarLista(lista);

    return 0;
}