#include <stdio.h>

int divisao(int n, int d)
{
    if(n<d) return (0);
    else return (1+divisao(n-d,d));
}

int main()
{
    int numerador,denominador;
    scanf("%d%d",&numerador,&denominador);
    printf("%d\n",divisao(numerador,denominador));
    return 0;
}
