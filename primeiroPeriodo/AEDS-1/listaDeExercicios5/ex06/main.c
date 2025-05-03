#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *saida=fopen("saida.txt","w");
    int N,soma=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        if(N%i==0)
        {
           printf("%d\n",i);
           soma+=i;
        }
    }
    fprintf(saida,"%d\n",soma);
    fclose(saida);
    return 0;
}
