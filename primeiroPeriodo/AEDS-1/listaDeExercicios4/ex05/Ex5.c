#include <stdio.h>

int fatorial(int num)
{
    if(num<0) return 0;
    else if(num==0 || num==1) return 1;
    else return (num*fatorial(num-1));
}

int main()
{
    int N;
    float expressao;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        expressao += 1.0/fatorial(i);
    }
    printf("%.2f\n",expressao);
    return 0;
}
