#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,cent,dez,uni,invertido;
    printf("\nDigite um numero inteiro com tres digitos: ");
    scanf("%d",&num);
    cent = num/100;
    dez = (num/10)%10;
    uni = num%10;
    invertido = (uni*100)+(dez*10)+cent;
    printf("\nO numero invertido eh %d",invertido);
    return 0;
}
