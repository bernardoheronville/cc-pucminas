#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caracteres;
    FILE *leitor1=fopen("arquivo1.txt","r");
    FILE *leitor2=fopen("arquivo2.txt","r");
    FILE *saida=fopen("arquivo3.txt","a");
    while((caracteres=fgetc(leitor1)) != EOF)
    {
        fprintf(saida,"%c",caracteres);
    }
    fprintf(saida,"\n");
    while((caracteres=fgetc(leitor2)) != EOF)
    {
        fprintf(saida,"%c",caracteres);
    }
    fclose(leitor1);
    fclose(leitor2);
    fclose(saida);
    return 0;
}
