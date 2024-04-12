#include <stdio.h>
#include <stdlib.h>

int main()
{
    // São criadas as variáveis I X Y
    int i;
    int x; // total de linhas
    int y; // tamanho de cada linha (coluna)
    // É criado e alocado um ponteiro para ponteiro (um "vetor de ponteiros") do tipo int e de tamanho X
    int **matriz = (int**)(malloc(x*sizeof(int*)));
    for(i=0;i<x;i++)
        // É criado e alocado um ponteiro para int de tamanho Y
        matriz[i] = (int*)(malloc(y*sizeof(int)));
    // (Como não foram atribuidos valores para X e Y, a matriz terá tamanho equivalente ao "lixo de memória" presente nele)
    return 0;
}