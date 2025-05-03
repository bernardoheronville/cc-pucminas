#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *contador=fopen("contador.txt","w");
    for(int i=1;i<=10;i++)
    {
        printf("%d\n",i);
        fprintf(contador,"%d\n",i);
    }
    fclose(contador);
    return 0;
}
