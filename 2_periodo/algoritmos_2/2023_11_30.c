#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *pont, *pont2;
    int n, i;

    printf("Quantidade de elementos: ");
    scanf(" %d", &n);

    pont = (int *) malloc(n * sizeof(int));
    pont2 = (int *) calloc(n, sizeof(int));
    pont2 = (int *) realloc(pont2, 10*sizeof(int));

    if(pont == NULL)
    {
        printf("\nMemória não alocada\n");
        exit(0);
    }
    else
    {
        printf("\nMemória alocada com sucesso\n");

        // for(i = 0; i < n; i++)
        // {
        //     pont[i] = i+1;
        // }

        // printf("\nVetor criado:\n");
        printf("\nMalloc:\n");
        for(i = 0; i < 10; i++)
        {
            printf("%d ", pont[i]);
        }
        printf("\n");

        printf("\nCalloc:\n");
        for(i = 0; i < 10; i++)
        {
            printf("%d ", pont2[i]);
        }
        printf("\n");
    }

    return 0;
}