#include <stdio.h>

int main()
{
    int x = 11;
    int b = 9;
    int *p = &x;
    p = &b;

    printf("\nValor: %d", x);
    printf("\nEndereço: %p\n", &x);
    
    printf("\nValor: %d", b);
    printf("\nEndereço: %p\n", &b);
    
    printf("\nValor: %d", *p);
    printf("\nEndereço: %p\n", p);

    return 0;
}