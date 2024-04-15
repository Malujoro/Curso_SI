#include <stdio.h>

int procuraSequencial(int *vetor, int tam, int valor)
{
    if(tam <= 0)
        return -1;

    if(vetor[tam-1] == valor)
        return tam-1;
    
    return procuraSequencial(vetor, tam-1, valor);
        
}

int main()
{
    int tam = 5, valor = 14;
    int vetor[] = {10, 11, 12, 13, 14};
    int pos = procuraSequencial(vetor, tam, valor);

    if(pos == -1)
        printf("O valor %d não foi encontrado", valor);
    else
        printf("O valor %d foi encontrado na posição %d", valor, pos);
    printf("\n");
    
    return 0;
}