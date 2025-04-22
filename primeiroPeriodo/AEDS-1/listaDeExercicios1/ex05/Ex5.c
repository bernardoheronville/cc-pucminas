#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario,aumento;
    scanf("%f",&salario);
    aumento=salario*1.30;
    if(salario<500)
    {
    printf("%.2f",aumento);
    }
    else
    {
    printf("Sem reajuste");
    }
    return 0;
}
