#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, *p1, *p2;
    
    a = 2;
    b = 2;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;
    printf(" %d %d \n", *p1, *p2);
    printf(" %d %d \n", a, b);

    return 0;
}