#include <stdio.h>
#include <stdlib.h>

int main()
{
    char texto[256];
    FILE *saida=fopen("saida.txt","w");
    fgets(texto,256,stdin);
    fprintf(saida,"%s",texto);
    fclose(saida);
    return 0;
}
