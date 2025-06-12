#include <stdio.h>
#include <stdlib.h>

void preenche(int *matriz,int *mat, int N, int K, int U)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<K; j++)
        {
            scanf("%d",(matriz+i*K+j));
        }
    }
    for(int i=0; i<U; i++)
    {
        scanf("%d",(mat+i));
    }
}

void verifica(int *matriz, int *mat, int N, int K)
{
    for(int i=0; i<N; i++)
    {
        int numero = *(mat+i);
        for(int j=0; j<K; j++)
        {
            if(*(matriz+i*K+j) == numero) *(matriz+i*K+j) = -1;
        }
    }
}

void finalize(int *matriz, int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        int soma = 0;
        for (int j = 0; j < K; j++)
        {
            if (*(matriz + i * K + j) != -1)
            {
                soma += *(matriz + i * K + j);
            }
        }
        if (soma == -1*K)
        {
            printf("Cartela %d completada!\n", i + 1);
        }
    }
}


int main()
{
    int N,K,U;
    scanf("%d%d%d",&N,&K,&U);
    int *matriz = (int*)malloc(N*K*sizeof(int));
    int *mat = (int*)malloc(U*sizeof(int));
    preenche(matriz,mat,N,K,U);
    verifica(matriz,mat,N,K);
    finalize(matriz,N,K);
    free(matriz);
    free(mat);
    return 0;
}
