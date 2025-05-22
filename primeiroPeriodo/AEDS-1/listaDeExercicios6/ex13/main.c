#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *alfabeto;
    int letras= 'A';
    alfabeto = (char*)malloc(26*sizeof(char));
    for(int i=0;i<26;i++)
    {
        *(alfabeto+i) = letras;
        letras++;
    }
    for(int i=0;i<26;i++)
    {
        printf("%c ",*(alfabeto+i));
    }
    free(alfabeto);
    return 0;
}
