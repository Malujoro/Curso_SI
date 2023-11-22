#include <stdio.h>
#define COL 5

void exibir(float matriz[][COL], int quant)
{
    int i;
    for(i = 0; i < quant; i++)
    {
        printf("%d  %.1f  %.1f  %.1f  %.1f\n", (int) matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4]);
    }
}

void insere_nota(float matriz[][COL], int pos)
{
    int i;
    float soma = 0;

    for(i = 1; i <= 3; i++)
    {
        printf("Nota %d: ", i);
        scanf(" %f", &matriz[pos][i]);
        soma += matriz[pos][i];
    }

    matriz[pos][4] = soma/3;
}

int cadastro(float matriz[][COL], int pos)
{
    printf("\n%dº Aluno:", pos+1);
    printf("\nMatrícula:");
    scanf(" %f", &matriz[pos][0]);
    matriz[pos][0] = (int) matriz[pos][0];

    insere_nota(matriz, pos);

    return pos+1;
}

void atualizar(float matriz[][COL], int tot)
{
    int i;
    float valor;

    printf("\nDigite o número da matrícula: ");
    scanf(" %f", &valor);

    for(i = 0; i < tot; i++)
    {
        if(matriz[i][0] == valor)
        {
            insere_nota(matriz, i);
            break;
        }
    }

    if(i == tot)
    {
        printf("\nMatrícula %.0f não encontrada!\n", valor);
    }
}

int main()
{
    int op, quant, i, tot = 0;

    printf("\nQuantos alunos serão cadastrados? ");
    scanf(" %d", &quant);

    float matriz[quant][COL];

    do
    {
        printf("\n----------MENU----------");
        printf("\n[1] Digitação de notas");
        printf("\n[2] Atualização de notas");
        printf("\n[0] Sair");
        printf("\n------------------------");
        printf("\nOpção: ");
        scanf(" %d", &op);

        switch(op)
        {
            case 1:
                if(tot == quant)
                    printf("\nTotal de alunos já cadastrados!\n");
                else
                {
                    for(i = 0; i < quant; i++)
                    {
                        tot = cadastro(matriz, tot);
                    }
                }
                break;

            case 2:
                atualizar(matriz, tot);
                break;

            case 3:
                exibir(matriz, tot);
                break;

            case 0:
                printf("\nFinalizando aplicação...\n");
                break;

            default:
                printf("\nErro! Digite uma opção válida!\n");
        }
    }while(op != 0);
    return 0;
}