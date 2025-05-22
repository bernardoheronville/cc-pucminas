#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *palavra;
    int N=30,contaVogal=0,contaConsoante=0;
    palavra = (char*)malloc(N*sizeof(char));
    scanf(" %[^\n]",palavra);
    for(int i=0;i<strlen(palavra);i++)
    {
            char letra = tolower(*(palavra+i));
            if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') contaVogal++;
            else if(letra > 'a' && letra <= 'z') contaConsoante++;
    }
    printf("Vogais: %d\n",contaVogal);
    printf("Consoantes: %d\n",contaConsoante);
    free(palavra);
    return 0;
}
