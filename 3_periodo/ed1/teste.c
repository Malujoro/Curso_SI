#include <stdio.h>
#include <string.h>

int main()
{
    char lista[] = {"abc\0"};
    int tam = strlen(lista);

    char lista2[] = {"Mateus\0"};
    int tam2 = strlen(lista2);

    printf("\n[%d]\n", 'a' == 'b');

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam2; j++)
        {
            printf("\n%c < %c? %d", lista[i], lista2[j], lista[i] < lista2[j]);
            printf("\n%c > %c? %d", lista[i], lista2[j], lista[i] > lista2[j]);
            printf("\n%c == %c? %d\n", lista[i], lista2[j], lista[i] == lista2[j]);
        }
    }

    return 0;
}