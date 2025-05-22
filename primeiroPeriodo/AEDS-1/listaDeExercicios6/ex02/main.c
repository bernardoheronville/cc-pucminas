#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    float temp[31],maiorTemp=FLT_MIN,menorTemp=FLT_MAX,soma=0,media;
    int diasJaneiro=31,qDias=0;
    for(int i=0;i<diasJaneiro;i++)
    {
        scanf("%f",&temp[i]);
        if(temp[i] > maiorTemp) maiorTemp = temp[i];
        if(temp[i] < menorTemp) menorTemp = temp[i];
        soma += temp[i];
    }
    media = (float) soma/diasJaneiro;
    for(int i=0;i<diasJaneiro;i++)
    {
        if(temp[i] < media) qDias++;
    }
    printf("Menor e maior temperatura: %.0f e %.0f\n",menorTemp,maiorTemp);
    printf("Media de temperatura: %.2f\n",media);
    printf("Numero de dias nos quais a temperatura foi inferior a temperatura media: %d\n",qDias);
    return 0;
}


