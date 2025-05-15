#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    char texto[100];
    FILE *leitor=fopen("entrada.txt","r");
    while(fscanf(leitor," %[^\n]",texto) == 1)
    {
        int i=0;
        while(texto[i] != '\0')
        {
            if(texto[i]=='a' || texto[i]=='A') contador++;
            i++;
        }
    }
    printf("%d CARACTERES\n",contador);
    fclose(leitor);
    return 0;
}
