#include <stdio.h>
#include <stdlib.h>

float calculaFatorial(int N)
{
    int fat=1;
    float S=1;
    for(int i=1; i<=N; i++)
    {
        fat*=i;
        S+=(float)1/fat;
    }
    return (S);
}
int main()
{
    int N;
    scanf("%d",&N);
    printf("%f",calculaFatorial(N));
    return 0;
}
