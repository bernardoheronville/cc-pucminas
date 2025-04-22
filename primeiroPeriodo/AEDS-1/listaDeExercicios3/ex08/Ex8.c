#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculaFormula(int N)
{
    float S=0;
    for(int i=1; i<=N; i++)
    {
        S+=(float)(pow(i,2)+1)/(i+3);
    }
    return (S);
}
int main()
{
    int N;
    scanf("%d",&N);
    printf("%f",calculaFormula(N));
    return 0;
}
