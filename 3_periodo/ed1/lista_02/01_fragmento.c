#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Cria dois ponteiros para inteiros
    int *p, *q;
    // Aloca um ponteiro para inteiro P com espaço para 1 inteiro
    p = malloc (sizeof (int));
    // Atribui o valor 123 ao endereço que P aponta
    *p = 123;
    // Aloca um ponteiro para inteiro Q com espaço para 1 inteiro
    q = malloc (sizeof (int));
    // Atribui o valor apontado por P (123) ao endereço que Q aponta
    *q = *p;
    // Q recebe o endereço que P aponta
    q = p;
    // O endereço que P aponta é P liberado
    free(p);
    // Acontece um erro, pois P e Q possuiam o mesmo endereço, e o endereço já foi liberado anteriormente
    free(q);
    // Caso tudo ocorresse corretamente, Q receberia o valor nulo
    q = NULL;

    return 0;
}