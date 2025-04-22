#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int razao,primeiro,decimo;
    printf("\nDigite a razao e o primeiro termo de uma PA: ");
    scanf("%d%d",&razao,&primeiro);
    decimo=primeiro+razao+razao+razao+razao+razao+razao+razao+razao+razao;
    printf("O decimo numero da PA eh %d",decimo);
    return 0;
}
