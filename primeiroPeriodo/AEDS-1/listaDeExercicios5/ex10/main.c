#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    float num,numMin=FLT_MAX,numMax= -FLT_MAX,total=0,q=0;
    FILE *entrada=fopen("entrada.txt","r");
    while((fscanf(entrada,"%f",&num)) == 1)
    {
       if(num>numMax)
       {
           numMax=num;
       }
       if(num<numMin)
       {
           numMin=num;
       }
       q++;
       total+=num;
    }
    printf("%.2f\n",numMax);
    printf("%.2f\n",numMin);
    printf("%.2f\n",total/q);
    fclose(entrada);
    return 0;
}
