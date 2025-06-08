#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,soma=0,contador=0;
    scanf("%d",&N);
    int numeros[N];
    for(int i=0; i<N; i++)
    {
        int num;
        scanf("%d",&num);
        if(num == 0)
        {
            if(contador > 0)
            {
                contador--;
                soma -= numeros[contador];
            }

        }
        else
        {
            numeros[contador] = num;
            soma += num;
            contador++;
        }
    }
    printf("%d\n",soma);
    return 0;
}
