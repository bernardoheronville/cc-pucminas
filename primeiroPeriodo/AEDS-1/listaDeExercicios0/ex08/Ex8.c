#include <stdio.h>
#include <stdlib.h>

int main()
{
    float A,B,temp;
    printf("\nDigite dois numeros reais: ");
    scanf("%f%f",&A,&B);
    temp=A;
    A=B;
    B=temp;
    printf("\n%.2f %.2f",A,B);
    return 0;
}
