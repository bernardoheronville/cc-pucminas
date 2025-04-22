#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float cateto1,cateto2,hipotenusa;
    printf("\nDigite os catetos de um triangulo: ");
    scanf("%f%f",&cateto1,&cateto2);
    hipotenusa=sqrt(pow(cateto1,2)+pow(cateto2,2));
    printf("A hipotenusa do trianngulo eh %.2f",hipotenusa);
    return 0;
}
