#include <stdio.h>
#include <stdlib.h>

void calculaCrescente(int a,int b,int c)
{
    int menor,meio,maior;
    if(a<=b&&a<=c)
    {
        menor=a;
        if(b<=c)
        {
            meio=b;
            maior=c;
        }
        else
        {
            meio=c;
            maior=b;
        }
    }
    if(b<=a&&b<=c)
    {
        menor=b;
        if(a<=c)
        {
            meio=a;
            maior=c;
        }
        else
        {
            meio=c;
            maior=a;
        }
    }
    if(c<=a&&c<=b)
    {
        menor=c;
        if(a<=b)
        {
            meio=a;
            maior=b;
        }
        else
        {
            meio=b;
            maior=a;
        }
    }
    printf("%d %d %d\n",menor,meio,maior);
}
int main()
{
    int N,num1,num2,num3;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d%d",&num1,&num2,&num3);
        calculaCrescente(num1,num2,num3);
    }
    return 0;
}
