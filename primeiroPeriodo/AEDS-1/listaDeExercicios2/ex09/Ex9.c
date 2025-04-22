#include <stdio.h>
#include <stdlib.h>

int main()
{
    float compra,venda,lucro,porcent,compratotal,vendatotal,lucrototal;
    int qmenor=0,qentre=0,qmaior=0;
    scanf("%f%f",&compra,&venda);
    while(compra>0)
    {
        lucro=venda-compra;
        porcent=lucro/compra*100;
        compratotal+=compra;
        vendatotal+=venda;
        lucrototal+=lucro;
        if(porcent<10)
        {
            qmenor++;
        }
        else if(porcent>=10&&porcent<=20)
        {
            qentre++;
        }
        else
        {
            qmaior++;
        }
        scanf("%f%f",&compra,&venda);
    }
    printf("%d\n",qmenor);
    printf("%d\n",qentre);
    printf("%d\n",qmaior);
    printf("%.2f\n",compratotal);
    printf("%.2f\n",vendatotal);
    printf("%.2f\n",lucrototal);
    return 0;
}
