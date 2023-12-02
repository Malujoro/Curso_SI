#include <stdio.h>
#include <stdlib.h>

void menu(int *op)
{
    printf("\n------------------Menu------------------");
    printf("\n[1] - Ordenar vetor em ordem crescente");
    printf("\n[2] - Ordenar vetor em ordem decrescente");
    printf("\n[0] - Sair do programa");
    printf("\nOpção: ");
    scanf(" %d", op);
}

void preencher(int *vetor, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", (vetor + i));
    }
}

void exibir(int *vetor, int tam)
{
    int i;

    printf("\n");
    for(i = 0; i < tam; i++)
        printf("%d ", *(vetor + i));

    printf("\n");
}

void ordena_crescente(int *vetor, int tam)
{
    int aux;
    int *pos_vetor, *pos_vetor2, *menor;

    for(pos_vetor = vetor; pos_vetor != (vetor + tam-1); pos_vetor++)
    {
        menor = pos_vetor;
        for(pos_vetor2 = pos_vetor+1; pos_vetor2 <= (vetor + tam-1); pos_vetor2++)
        {
            if(*pos_vetor2 < *menor)
                menor = pos_vetor2;
        }
        aux = *pos_vetor;
        *pos_vetor = *menor;
        *menor = aux;
    };
}

void ordena_decrescente(int *vetor, int tam)
{
    int aux;
    int *pos_vetor, *pos_vetor2, *maior;

    for(pos_vetor = vetor; pos_vetor != (vetor + tam-1); pos_vetor++)
    {
        maior = pos_vetor;
        for(pos_vetor2 = pos_vetor+1; pos_vetor2 <= (vetor + tam-1); pos_vetor2++)
        {
            if(*pos_vetor2 > *maior)
                maior = pos_vetor2;
        }
        aux = *pos_vetor;
        *pos_vetor = *maior;
        *maior = aux;
    }
}

int main()
{
    int tam, op;

    printf("Tamanho do vetor: ");
    scanf(" %d", &tam);
    
    int *vetor = (int *) malloc(tam * sizeof(int));

    if(vetor == NULL)
        printf("\nNão foi possível alocar memória para um vetor desse tamanho!\n");
    else
    {
        preencher(vetor, tam);

        do
        {
            menu(&op);
            switch(op)
            {
                case 1:
                    ordena_crescente(vetor, tam);
                    exibir(vetor, tam);
                    break;

                case 2:
                    ordena_decrescente(vetor, tam);
                    exibir(vetor, tam);
                    break;
                
                case 0:
                    printf("\nSaindo do programa...\n");
            }
        }while(op != 0);

        free(vetor);
    }

    return 0;
}