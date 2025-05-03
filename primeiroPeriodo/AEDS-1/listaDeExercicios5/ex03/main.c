#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    char letraA;
    FILE *leitor=fopen("saida.txt","r");
    while((letraA=fgetc(leitor)) != EOF)
    {
        if(letraA=='a' || letraA=='A') contador++;
    }
    printf("%d\n",contador);
    fclose(leitor);
    return 0;
}
