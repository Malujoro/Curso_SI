#include <stdio.h>
#include <stdlib.h>

struct Fone
{
    char codigo[3];
    char area[4];
    char numero[4];
};

void mostrarFone(void *telefone, int tam)
{
    char *telefone2 = (char *)telefone;
    for(int i = 0; i < tam; i++)
    {
        if(i == 0)
            printf("(");
        else if(i == 3)
            printf(") ");
        else if(i == 6)
            printf("-");
        
        printf("%c", telefone2[i]);
    }
}

int main()
{
    char s[11] = "0413301515";
    struct Fone f = {{"041"}, {"330"}, {"1563"}};
    mostrarFone(s, 11);
    printf("\n");
    mostrarFone(&f, 11);
    printf("\n");
    return 0; 
}