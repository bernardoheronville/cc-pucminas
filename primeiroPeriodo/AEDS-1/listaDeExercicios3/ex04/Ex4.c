#include <stdio.h>
#include <stdlib.h>

void calculaTriangulo(float a,float b,float c)
{
    if(a<b+c && b<a+c && c<a+b)
    {
        if(a==b && a==c)
        {
            printf("TRIANGULO EQUILATERO\n");
        }
        else if(a==b || a==c || b==c)
        {
            printf("TRIANGULO ISOSCELES\n");
        }
        else
        {
            printf("TRIANGULO ESCALENO\n");
        }
    }
    else
    {
        printf("NAO TRIANGULO\n");
    }
}
int main()
{
    float lado1,lado2,lado3;
    scanf("%f%f%f",&lado1,&lado2,&lado3);
    while(lado1>=0)
    {
        calculaTriangulo(lado1,lado2,lado3);
        scanf("%f%f%f",&lado1,&lado2,&lado3);
    }
    return 0;
}
