#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float solucao=1,fat=1;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
       fat*=i;
       solucao+=1.0/fat;
    }
    printf("%.2f",solucao);
    return 0;
}

