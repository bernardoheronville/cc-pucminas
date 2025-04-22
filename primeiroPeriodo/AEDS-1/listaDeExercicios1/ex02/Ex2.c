#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3,n4,media;
    scanf("%f%f%f%f",&n1,&n2,&n3,&n4);
    media = (n1+n2+n3+n4)/4;
    if(media>=7)
    {
    printf("%.2f\nAprovado",media);
    }
    else
    {
    printf("%.2f\nReprovado",media);
    }
    return 0;
}
