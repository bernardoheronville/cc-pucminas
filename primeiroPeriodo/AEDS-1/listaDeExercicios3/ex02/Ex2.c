#include <stdio.h>
#include <stdlib.h>

void calculaMedia()
{
    int filhos,pessoas=0;
    float salario,salariototal=0,media;
    scanf("%f%d",&salario,&filhos);
    while(salario>=0)
    {
        pessoas++;
        salariototal+=salario;
        scanf("%f%d",&salario,&filhos);
    }
    media=(float)salariototal/pessoas;
    printf("%.2f\n",media);
}
int main()
{
    calculaMedia();
    return 0;
}
