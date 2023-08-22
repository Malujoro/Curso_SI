#include <stdio.h>
#include <string.h>

// Ler nome e profissão de 100 pessoas
// Exibir qual das profissões que mais se repete,
// quantas pessoas tem essa profissão e os nomes dessas pessoas

int main(void)
{
    int quant = 5, quant_prof = 3, i, j, op;
    char nomes[quant][100], nome_profissoes[quant_prof][100];
    int cod_profissoes[quant], quant_pessoas[quant_prof];

    printf("\nCadastro de profissões:\n");
    for (i = 0; i < quant_prof; i++)
    {
        printf("%dº Profissão: ", i+1);
        gets(nome_profissoes[i]);
        setbuf(stdin, NULL);
        quant_pessoas[i] = 0;
    }

    for (i = 0; i < quant; i++)
    {
        printf("\n%dª pessoa:", i+1);

        printf("\nNome: ");
        gets(nomes[i]);
        setbuf(stdin, NULL);
        
        do
        {
            printf("\nProfissão:\n");
            for(j = 0; j < quant_prof; j++)
            {
                printf("%d - %s\n", j+1, nome_profissoes[j]);
            }
            printf("\nOpção: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
                        
            cod_profissoes[i] = op-1;
        } while (op <= 0 || op > quant_prof);
    }

    printf("\nNome \t Profissão\n");
    for (i = 0; i < quant; i++)
    {
        printf("[%s] \t [%s]\n", nomes[i], nome_profissoes[cod_profissoes[i]]);
    }
    return 0;
}