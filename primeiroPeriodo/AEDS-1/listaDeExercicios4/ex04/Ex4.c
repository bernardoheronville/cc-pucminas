#include <stdio.h>

int resto(int n, int d)
{
    if(n<d) return (n);
    else return (resto(n-d,d));
}

int main()
{
    int numerador,denominador;
    scanf("%d%d",&numerador,&denominador);
    printf("%d\n",resto(numerador,denominador));
    return 0;
}
