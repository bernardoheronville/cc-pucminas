#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char frase[50];
    scanf(" %[^\n]",frase);
    for(int i=0;i<strlen(frase);i++)
    {
        if(frase[i] == ' ') printf("\n");
        else printf("%c",frase[i]);
    }
    return 0;
}
