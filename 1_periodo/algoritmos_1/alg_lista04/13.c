#include <stdio.h>
#include <string.h>

// Ler nome e profissão de 100 pessoas
// Exibir qual das profissões que mais se repete,
// quantas pessoas tem essa profissão e os nomes dessas pessoas

int main(void)
{
    int quant = 100, quant_prof = 3, i, j, op;
    char nomes[quant][100], nome_profissoes[quant_prof][100];
    int cod_profissoes[quant], quant_pessoas[quant_prof];
    int maior, pos_maior;

    printf("\nCadastro de profissões:\n");
    for (i = 0; i < quant_prof; i++)
    {
        printf("%dº Profissão: ", i+1);
        scanf(" %[^\n]s", nome_profissoes[i]);
        quant_pessoas[i] = 0;
    }

    // Cadastro de pessoas e suas profissões
    for (i = 0; i < quant; i++)
    {
        printf("\n%dª pessoa:", i+1);

        printf("\nNome: ");
        scanf(" %[^\n]s", nomes[i]);
        setbuf(stdin, NULL);
        
        do
        {
            printf("\nProfissão:\n");
            for(j = 0; j < quant_prof; j++)
            {
                printf("%d - %s\n", j+1, nome_profissoes[j]);
            }
            printf("\nOpção: ");
            scanf(" %d", &op);
            setbuf(stdin, NULL);
                        
            cod_profissoes[i] = op-1;
        } while (op <= 0 || op > quant_prof);
    }

    // Busca a profissão que mais se repete
    for (i = 0; i < quant_prof; i++)
    {
        quant_pessoas[i] = 0;

        for (j = 0; j < quant; j++)
        {
            if (i == cod_profissoes[j])
            {
                quant_pessoas[i] ++;
            }
        }
    }

    maior = quant_pessoas[0];
    pos_maior = 0;
    for (i = 1; i < quant_prof; i++)
    {
        if (quant_pessoas[i] > maior)
        {
            maior = quant_pessoas[i];
            pos_maior = i;
        }
    }

    printf("\nProfissão mais escolhida [%s]", nome_profissoes[pos_maior]);
    printf("\nEscolhido por %d pessoas", maior);

    for (i = 0; i < quant; i++)
    {
        if (cod_profissoes[i] == pos_maior)
        {
            printf("\nNome: [%s]", nomes[i]);
        }
    }
    return 0;
}