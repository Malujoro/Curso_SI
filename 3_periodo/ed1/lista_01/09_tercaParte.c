#include <stdio.h>
#include <stdlib.h>

void tercaParte(float *v)
{
    for(int i = 0; i < 10; i++)
        v[i] *= (v[i] / 3);
}

int main()
{
    float *v = (float *) malloc(10 * sizeof(float));

    for(int i = 0; i < 10; i++)
        v[i] = i;

    tercaParte(v);
    
    for(int i = 0; i < 10; i++)
        printf("%f ", v[i]);

    free(v);
    return 0;
}