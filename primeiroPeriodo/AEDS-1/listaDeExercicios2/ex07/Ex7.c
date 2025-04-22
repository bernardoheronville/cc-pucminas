#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,num1=1,num2=1,temp;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        printf("%d ",num1);
        temp=num1+num2;
        num1=num2;
        num2=temp;
    }
    printf("\n");
    return 0;
}


