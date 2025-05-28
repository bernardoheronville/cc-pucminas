#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char frase[30];
    scanf(" %[^\n]",frase);
    for(int i=strlen(frase)-1;i>=0;i--)
    {
        char letra = tolower(frase[i]);
        if(letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u' && letra >= 'a' && letra <= 'z')
        {
            printf("#");
        }
        else
        {
            printf("%c",frase[i]);
        }
    }
    return 0;
}
