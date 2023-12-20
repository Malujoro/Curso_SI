#include <stdio.h>

int main()
{
    int i=5;
    int *p = &i;
    // printf(" %d %d %d \n", *p+1, &p, 4*(*p*(*(*p)-2)));
    printf(" %d %d %d \n", (*p)+2, *p, *p*9);
}