#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("teste.txt", "r");
    if(fp == NULL)
        printf("Erro ao abrir arquivo\n");
    else
    {
        printf("Arquivo aberto com sucesso\n");
    }
    fclose(fp);
}