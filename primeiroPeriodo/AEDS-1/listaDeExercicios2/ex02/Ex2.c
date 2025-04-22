#include <stdio.h>

int main()
{
    int n,qmenor=0,qzero=0,qmaior=0,percentualmaior=0,percentualmenor=0,percentualzero=0;
    long int num;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
    scanf("%ld",&num);
    if(num>0) qmaior++;
    if(num<0) qmenor++;
    if(num==0) qzero++;
    }
    percentualmaior= qmaior*100/n;
    percentualmenor= qmenor*100/n;
    percentualzero= qzero*100/n;
    printf("%d%% POSITIVOS\n",percentualmaior);
    printf("%d%% NEGATIVOS\n",percentualmenor);
    printf("%d%% ZEROS\n",percentualzero);
    return 0;
}
