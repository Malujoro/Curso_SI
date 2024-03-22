#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int m = 200, n = 100, x;
    int matriz[m][n];
    
    srand(time(NULL));

    do
    {
        printf("Números gerados de 0 a ");
        scanf(" %d", &x);
    }while(x <= 0);

    int *vetor = (int *) calloc(x+1, sizeof(int));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % (x+1);
            vetor[matriz[i][j]]++;
        }
    }

    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //         printf("%d ", matriz[i][j]);

    //     printf("\n");
    // }

    // for(int i = 0; i <= x; i++)
    //     printf("%d ", vetor[i]);

    for(int i = 0; i <= x; i++)
    {
        if(vetor[i] == 1)
            printf("\nO número %d ocorreu %d vez", i, vetor[i]);
        else if(vetor[i] > 1)
            printf("\nO número %d ocorreu %d vezes", i, vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}