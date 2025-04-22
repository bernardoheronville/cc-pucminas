#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hx,hf,h;
    scanf("%d",&hx);
    scanf("%d",&hf);
    h=(hx*60)-(2.0/3.0*(hf*60));
    if(h<600)
    {
    printf("100.00\n");
    }
    else if(h>=600&&h<1200)
    {
    printf("200.00\n");
    }
    else if(h>=1200&&h<1800)
    {
    printf("300.00\n");
    }
    else if(h>=1800&&h<2400)
    {
    printf("400.00\n");
    }
    else
    {
    printf("500.00\n");
    }
    return 0;
}
