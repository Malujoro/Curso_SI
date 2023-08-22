#include <stdio.h>

int main(void)
{
    char nomes[100][100];
    int l, quant=0, op;
    
    do
    {
    printf("\n----------Menu----------");
    printf("\n1 - Cadastrar\n2 - Consultar\n3 - Sair\n\nOpção: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    switch (op)
    {
        case 1:
            printf("\nCadastrar %dº nome: ", quant+1);
            gets(nomes[quant]);
            setbuf(stdin, NULL);
            quant++;
            break;
        case 2:
            printf("\nListar nomes cadastrados:\n");
            for (l = 0; l <= quant; l++)
            {
                printf("%s\n", nomes[l]);
            }
            break;
        case 3:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\n Opção inválida!!");
    }
    } while (op != 3);
    return 0;
}