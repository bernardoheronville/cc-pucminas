#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,qmenor=0,qzero=0,qmaior=0;
    long long int num;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&num);
        if(num>0)
        {
            qmaior++;
        }
        else if(num<0)
        {
            qmenor++;
        }
        else
        {
            qzero++;
        }
    }
    printf("%d POSITIVOS\n",qmaior);
    printf("%d NEGATIVOS\n",qmenor);
    printf("%d ZEROS\n",qzero);
    return 0;
}
