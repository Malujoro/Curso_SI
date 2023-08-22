#include <stdio.h>

int main(void)
{
    int altura;
    int contador_linhas=0, estrelas=0;

    printf("Linhas: ");
    scanf("%d", &altura);

    while (contador_linhas < altura)
    {
        estrelas = 0;
        while (estrelas <= contador_linhas)
        {
            printf("*");
            estrelas++;
        }
        printf("\n");
        contador_linhas++;
    }   
    return 0;
}
