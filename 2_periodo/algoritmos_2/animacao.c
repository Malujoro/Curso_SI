#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIN 20
#define COL 21
#define LADO 80

int main()
{
	int i, j, k, repet = 0; // Declaração das variáveis de controle
    char espaco = '+'; // Variável que vai indicar se o movimento deve ser feito pra direita (+) ou esquerda (-)
	char *pont[LIN], *temp; // Vetor de ponteiros para ter o endereço referente as linhas do desenho | Ponteiro auxiliar temporário
	// Matriz contendo todo o desenho
    char nave[LIN][COL] = { {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', 'O', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '/', '|', '\\', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '/', '*', '\\', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'A', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '<', '|', '_', '|', '>', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'V', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', 'M', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '<', '[', '_', ']', '>', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', 'W', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'M', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '<', '[', '_', ']', '>', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
							{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};
	// char base[COL] = {'=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '='};

    // Preenche o vetor de ponteiros com o endereço de cada linha
	for(i = 0; i < LIN; i++)
	{
		*(pont+i) = *(nave + i);
	}
    // Looping infinito
	while(1)
	{
		system("clear"); // Limpa a tela todo início
        // Looping para printar os espaços e o desenho
		for(i = 0; i < LIN; i++)
		{
            // Analisa se é pra "mover" o desenho para direita ou esquerda (printar os espaços)
            if(espaco == '+')
            {
                for(k = 0; k < repet; k++)
                {
                    printf(" ");
                }
            }
            else if(espaco == '-')
            {
                for(k = repet; k > 0; k--)
                {
                    printf(" ");
                }
            }
            // Imprime o desenho
			for(j = 0; j < COL; j++)
			{
				printf("%c", *(*(pont + i) + j));
			}
			printf("\n");
		}
        // Mudança na quantidade de espaços de cada linha
        if(espaco == '+')
            repet++;
        else if(espaco == '-')
            repet --;
        // Troca de lado (quando atingir o limite, o desenho vai "andar" pro outro lado)
        if(repet == LADO)
            espaco = '-';
        else if(repet == 0)
            espaco = '+';

		// printf("%s ", base);
		// printf("\n");
        // Efetua a troca das linhas (bota a primeira no final)
		temp = *pont;
		for(i = 0; i < LIN-1; i++)
		{
			*(pont+i) = *(pont+i+1);
		}
		*(pont+LIN-1) = temp;
        // usleep(125000);
        usleep(65000);
	}
	return 0;
}