#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool calculaValor(int valor)
{
    if(valor>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N,valor;
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&valor);
        if(calculaValor(valor))
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
    }
    return 0;
}
