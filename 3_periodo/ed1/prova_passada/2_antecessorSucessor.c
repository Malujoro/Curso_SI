#include <stdio.h>

int sucessor(int x) {return x+1;}
int antecessor(int x) {return x-1;}

int soma(int n1, int n2)
{
    if(n2 == 0)
        return n1;
    
    return soma(sucessor(n1), antecessor(n2));
}

int main()
{
    printf("%d\n", soma(10, 5));

    return 0;
}