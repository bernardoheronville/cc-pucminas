#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int N,*num,maiorNum=INT_MIN;
    scanf("%d",&N);
    num = (int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
    {
        scanf("%d",(num+i));
        if(*(num+i) > maiorNum) maiorNum = *(num+i);
    }
    printf("%d\n",maiorNum);
    free(num);
    return 0;
}
