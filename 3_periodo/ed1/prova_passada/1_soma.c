#include <stdio.h>

int soma(int num)
{
    if(num < 10)
        return num;

    return num % 10 + soma(num / 10);
}

int main()
{
    printf("%d\n", soma(1234));
    
    return 0;
}