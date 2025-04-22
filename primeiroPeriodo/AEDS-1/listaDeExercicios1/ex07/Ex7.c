#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor;
    char poupanca;
    scanf("%f",&valor);
    scanf(" %c",&poupanca);
    if(poupanca=='P'||poupanca=='p')
    {
    printf("%.2f\n",valor*1.03);
    }
    else if(poupanca=='F'||poupanca=='f')
    {
    printf("%.2f\n",valor*1.04);
    }
    else
    {
    printf("\nTipo de investimento invalido");
    }
    return 0;
}
