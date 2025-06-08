#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    char resultado[6];
    for(int i=0; i<6; i++)
    {
        scanf(" %c",&resultado[i]);
    }
    for(int i=0; i<6; i++)
    {
        if(resultado[i] == 'V') contador++;
    }
    if(contador == 5 || contador == 6) printf("1\n");
    else if(contador == 3 || contador == 4) printf("2\n");
    else if(contador == 1 || contador == 2) printf("3\n");
    else printf("-1\n");
    return 0;
}
