#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num,den,decimal;
    printf("\nDigite o numerador e o denominador de uma fracao: ");
    scanf("%f%f",&num,&den);
    decimal=num/den;
    if(den==0)
    {
    printf("\nNao eh possivel dividir por zero.");
    }
    else
    {
    printf("\nEssa fracao em decimal eh %.2f",decimal);
    }
    return 0;
}
