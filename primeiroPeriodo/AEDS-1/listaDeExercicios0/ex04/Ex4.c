#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float raio,perimetro,area;
    printf("\nDigite o raio de um circulo: ");
    scanf("%f",&raio);
    perimetro=2*M_PI*raio;
    area=M_PI*(raio*raio);
    printf("O perimetro do circulo eh %.2f e a area eh %.2f ",perimetro,area);
    return 0;
}
