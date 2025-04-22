#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float solucao=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
       solucao+=1.0/i;
    }
    printf("%.2f",solucao);
    return 0;
}

