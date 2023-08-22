#include <stdio.h>

/*
    Dado três números, exibi-los em ordem crescente.
*/

int main(void)
{
    int n1, n2, n3;

    printf("N1: ");
    scanf(" %d", &n1);

    printf("N2: ");
    scanf(" %d", &n2);

    printf("N3: ");
    scanf(" %d", &n3);

    if (n1 <= n2 && n1 <= n3)
    {
        printf("\n%d - ", n1);

        if (n2 <= n3)
        {
            printf("%d - %d", n2, n3);
        }
        else
        {
            printf("%d - %d", n3, n2);
        }
    }
    else if (n2 <= n1 && n2 <= n3)
    {
        printf("\n%d - ", n2);

        if (n1 <= n3)
        {
            printf("%d - %d", n1, n3);
        }
        else
        {
            printf("%d - %d", n3, n1);
        }
    }
    else
    {
        printf("\n%d - ", n3);

        if (n1 <= n2)
        {
            printf("%d - %d", n1, n2);
        }
        else
        {
            printf("%d - %d", n2, n1);
        }
    }
    printf("\n");
    return 0;
}