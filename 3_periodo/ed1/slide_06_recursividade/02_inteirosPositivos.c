#include <stdio.h>

void inteirosPositivos(int k)
{
    if(k >= 0)
    {
        printf("%d ", k);
        inteirosPositivos(k-1);
    }
}

int main()
{
    inteirosPositivos(5);
    return 0;
}