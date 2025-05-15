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
           printf("%c",texto[i]);
           i++;
        }
        printf("\n");
        contador++;
        fgetc(leitor);
    }
    printf("\n%d LINHAS\n",contador);
    fclose(leitor);
    return 0;
}
