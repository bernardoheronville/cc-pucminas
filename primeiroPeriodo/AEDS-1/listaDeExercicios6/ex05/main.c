#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(int matriz[][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
}

int letraA(int matriz[][5])
{
    int soma=0;
    for(int j=0; j<5; j++)
    {
        soma += matriz[4][j];
    }
    return (soma);
}

int letraB(int matriz[][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        soma += matriz[i][2];
    }
    return (soma);
}

int letraC(int matriz[][5])
{
    int soma=0;
    for(int i=0; i<5; i++)
    {
        soma += matriz[i][i];
    }
    return (soma);
}

int letraD(int matriz[][5])
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

    printf("%d\n",letraA(M));
    printf("%d\n",letraB(M));
    printf("%d\n",letraC(M));
    printf("%d\n",letraD(M));
    printf("%d\n",letraE(M));
    return 0;
}
