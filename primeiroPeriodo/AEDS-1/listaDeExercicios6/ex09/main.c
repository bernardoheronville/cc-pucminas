#include <stdio.h>
#include <stdlib.h>

void ordenar(int *vetor, int tam)
{
    int temp;
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (*(vetor + i) > *(vetor + j))
            {
                temp = *(vetor + i);
                *(vetor + i) = *(vetor + j);
                *(vetor + j) = temp;
            }
        }
    }
}


void exibe(int *vetor, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ",*(vetor+i));
    }
}

int main()
{
    int *vetor,N;
    scanf("%d",&N);
    vetor = (int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++)
    {
        scanf("%d",(vetor+i));
    }
    ordenar(vetor,N);
    exibe(vetor,N);
    free(vetor);
    return 0;
}
