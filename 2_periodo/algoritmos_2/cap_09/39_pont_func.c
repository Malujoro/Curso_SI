#include <stdio.h>
#include <stdlib.h>

void func0(void), func1(void), func2(void); /* Protótipos */

void *RetornaPFunc(int op)
{
	switch(op)
	{
		case 0:
			return func0;

		case 1:
			return func1;

		case 2:
			return func2;
	}
}

const int true = 1; 

typedef void (*PFunc) (void); /* PFunc é ponteiro para função void */

int main()
{
    PFunc ptr;

    do
    {
        int i;
        printf("0 - ABRIR\n");
        printf("1 - FECHAR\n");
        printf("2 - SALVAR\n");
        printf("\nEscolha um item: ");
        scanf(" %d", &i);

        if(i < 0 || i > 2) break;

        ptr = RetornaPFunc(i);
        (ptr)(); /* Chama função */
    } while(true);
    return 0;
}

void func0()
{
    printf("\n*** Estou em func0() ***\n");
}

void func1()
{
    printf("\n*** Estou em func1() ***\n");
}

void func2()
{
    printf("\n*** Estou em func2() ***\n");
}