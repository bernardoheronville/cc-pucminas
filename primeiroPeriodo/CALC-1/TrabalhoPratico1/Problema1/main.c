#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float Ax,Ay,Bx,By,b,m;
    printf("Escreva o ponto A: ");
    scanf("%f%f",&Ax,&Ay);
    printf("Escreva o ponto B: ");
    scanf("%f%f",&Bx,&By);
    if(Bx==By)
    {
        printf("A reta eh vertical: x = %.2f\n", Ax);
    }
    else
    {
        m = (By-Ay)/(Bx-Ax);
        b = Ay-m*Ax;
        printf("y = %.2fx + %.2f\n",m,b);
    }
    return 0;
}
