#include <stdio.h>

int main(void)
{
    int linhas, colunas;
    int contador_linhas=0, contador_colunas=0;

    printf("Linhas: ");
    scanf("%d", &linhas);

    printf("Colunas: ");
    scanf("%d", &colunas);

    while (contador_linhas < linhas)
    {
        contador_colunas = 0;
        while (contador_colunas < colunas)
        {
            if ((contador_colunas == 0) || (contador_colunas == colunas-1))
                printf("|");
            else
                printf("*");
            contador_colunas++;
        }
        printf("\n");
        contador_linhas++;
    }
    
    return 0;
}