#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    
    do
    {
        scanf("%d %d", &n, &x);
    }while(!(1 <= n && n <= 3 * 10 * 10 * 10 * 10 * 10 && 1 <= x && x <= 10 * 10 * 10 * 10 * 10));
    
    char string[n];
    scanf("%s", string);
    
    int p, m, g;
    do
    {
        scanf("%d %d %d", &p, &m, &g);
    }while(!(1 <= p && p <= m && m <= g && g <= x));
    
    int quant = 1, tamanhoTita = 0, morreu;
    int *muralha = (int*) malloc(sizeof(int));
    muralha[0] = x;
    
    for(int i = 0; i < n; i++)
    {
        morreu = 0;
        
        if(string[i] == 'P')
            tamanhoTita = p;
        else if(string[i] == 'M')
            tamanhoTita = m;
        else if(string[i] == 'G')
            tamanhoTita = g;
        
        for(int j = 0; j < quant; j++)
        {
            if(muralha[j] >= tamanhoTita)
            {
                muralha[j] -= tamanhoTita;
                morreu = 1;
                break;
            }
        }
        
        if(morreu)
            continue;
        
        quant++;
        muralha[quant-1] = x - tamanhoTita;
    }
    
    printf("%d", quant);
    free(muralha);
    
    return 0;
}
