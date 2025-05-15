#include <stdio.h>
#include <stdlib.h>

int main()
{
    char texto[256];
    FILE *saida=fopen("saida.txt","w");
    scanf(" %[^\n]",texto);
    fprintf(saida,"%s\n",texto);
    fclose(saida);
    return 0;
}
