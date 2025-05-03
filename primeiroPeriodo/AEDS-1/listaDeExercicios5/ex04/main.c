#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=1;
    char caracteres;
    FILE *leitor=fopen("entrada.txt","r");
    while((caracteres=fgetc(leitor)) != EOF)
    {
        printf("%c",caracteres);
        if(caracteres=='\n') contador++;
    }
    printf("\n");
    printf("%d LINHAS\n",contador);
    fclose(leitor);
    return 0;
}
