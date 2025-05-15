#include <stdio.h>
#include <stdlib.h>

int main()
{
    char texto[100];
    FILE *leitor1=fopen("arquivo1.txt","r");
    FILE *leitor2=fopen("arquivo2.txt","r");
    FILE *saida=fopen("arquivo3.txt","a");
    while(fscanf(leitor1," %[^\n]",texto) == 1)
    {
        int i=0;
        while(texto[i] != '\0')
        {
           fprintf(saida,"%c",texto[i]);
           i++;
        }
        fprintf(saida,"\n");
    }
    while(fscanf(leitor2," %[^\n]",texto) == 1)
    {
        int i=0;
        while(texto[i] != '\0')
        {
           fprintf(saida,"%c",texto[i]);
           i++;
        }
        fprintf(saida,"\n");
    }
    fclose(leitor1);
    fclose(leitor2);
    fclose(saida);
    return 0;
}
