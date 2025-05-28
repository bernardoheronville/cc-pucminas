#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char frase[100],soma=0;
    scanf(" %[^\n]",frase);
    int len = strlen(frase);
    for(int i=0;i<len;i++)
    {
        if(frase[i] != ' ') soma++;
    }
    printf("Essa frase tem %d letras",soma);
    return 0;
}
