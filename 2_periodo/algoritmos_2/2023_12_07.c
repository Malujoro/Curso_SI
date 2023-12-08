#include <stdio.h>

int main()
{
    FILE *arquivo;
    int num, vetor[10], i;

    arquivo = fopen("inteiros.txt", "w");
    if(arquivo == NULL)
        printf("Erro ao abrir arquivo\n");
    else
    {
        for(i = 0; i < 10; i++)
        {
            printf("%dº número: ", i+1);
            scanf(" %d", &num);
            fprintf(arquivo, "%d\n", num);
        }
    }
    fclose(arquivo);

    arquivo = fopen("inteiros.txt", "r");
    if(arquivo == NULL)
        printf("Erro ao abrir arquivo\n");
    else
    {
        for(i = 0; i < 10; i++)
            fscanf(arquivo, "%d ", &vetor[i]);

        printf("\nValores digitados:\n");
        for(i = 0; i < 10; i++)
            printf("%2dº..........%2d\n",i+1, vetor[i]);
    }
}