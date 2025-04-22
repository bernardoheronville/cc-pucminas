#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float base,altura,perimetro,area,diagonal;
    printf("\nDigite a base e a altura de um retangulo: ");
    scanf("%f%f",&base,&altura);
    perimetro=2*(base+altura);
    area=base*altura;
    diagonal=sqrt(pow(base,2)+pow(altura,2));
    printf("\nO perimetro do retangulo eh %.2f a area eh %.2f e a diagonal eh %.2f",perimetro,area,diagonal);
    return 0;
}
