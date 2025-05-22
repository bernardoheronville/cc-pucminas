#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(int matriz[5][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("%d\n",letraA(matriz));
    printf("%d\n",letraB(matriz));
    printf("%d\n",letraC(matriz));
    printf("%d\n",letraD(matriz));
    printf("%d\n",letraE(matriz));
}

int letraA(int matriz[5][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0;j<5;j++)
        {
           if(i==3) soma += matriz[i][j];
        }
    }
    return (soma);
}

int letraB(int matriz[5][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j==1) soma += matriz[i][j];
        }
    }
    return (soma);
}

int letraC(int matriz[5][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(i == j) soma += matriz[i][j];
        }
    }
    return (soma);
}

int letraD(int matriz[5][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        soma += matriz[i][4-i];
    }
    return (soma);
}

int letraE(int matriz[][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            soma += matriz[i][j];
        }
    }
    return(soma);
}

int main()
{
    int M[5][5];
    preencherMatriz(M);
    return 0;
}
