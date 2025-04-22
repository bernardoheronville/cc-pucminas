#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura;
    char sexo;
    scanf("%f",&altura);
    scanf(" %c",&sexo);
    if(sexo=='H'||sexo=='h')
    {
    printf("%.2f\n",(72.7*altura)-58);
    }
    else if(sexo=='M'||sexo=='m')
    {
    printf("%.2f\n",(62.1*altura)-44.7);
    }
    else
    {
    printf("\nColoque um sexo valido");
    }
    return 0;
}
