#include <stdio.h>
#include <stdlib.h>

void calculaConceito(int nota)
{
    if(nota<=39)
        {
            printf("F\n");
        }
        else if(nota>=40 && nota<=59)
        {
            printf("E\n");
        }
        else if(nota>=60 && nota<=69)
        {
            printf("D\n");
        }
        else if(nota>=70 && nota<=79)
        {
            printf("C\n");
        }
        else if(nota>=80 && nota<=89)
        {
            printf("B\n");
        }
        else
        {
            printf("A\n");
        }
}
int main()
{
    int nota,N;
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&nota);
        calculaConceito(nota);
    }
    return 0;
}
