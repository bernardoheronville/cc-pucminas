#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salariom,kilowatt,vk,vt,desconto;
    printf("\nDigite o salario minimo: ");
    scanf("%f",&salariom);
    printf("\A quantidade de kilowatt gasta por uma residencia: ");
    scanf("%f",&kilowatt);
    vk=salariom/7/100;
    vt=vk*kilowatt;
    desconto=vt*0.9;
    printf("\nO valor em reais de cada kilowatt eh %.2f",vk);
    printf("\no valor em reais a ser pago eh %.2f",vt);
    printf("\nO novo valor a ser pago por essa residencia com o desconto eh %.2f",desconto);
    return 0;
}
