#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int razao,primeiro,quinto;
    printf("\nDigite a razao e o primeiro termo de uma PG: ");
    scanf("%d%d",&razao,&primeiro);
    quinto=primeiro*razao*razao*razao*razao;
    printf("O quinto numero da PG eh %d",quinto);
    return 0;
}
