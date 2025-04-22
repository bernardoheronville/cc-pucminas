#include <stdio.h>

int main()
{
    int l,num1=1,num2=1,temp;
    scanf("%d",&l);

    if (l >= 1)
    {
        printf("1 ");
    }
    if (l >= 2)
    {
        printf("1 ");
    }
    temp=num1+num2;
    while(temp < l)
    {
        printf("%d ", temp);
        num1=num2;
        num2=temp;
        temp=num1+num2;
    }
    printf("\n");
    return 0;
}
