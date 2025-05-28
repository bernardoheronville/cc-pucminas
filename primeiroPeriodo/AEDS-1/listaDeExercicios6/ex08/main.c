#include <stdio.h>

void preencheMatriz(int matriz[10][10], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("%d ",matriz[i][j]);
        }
    }
}

void letraA(int matriz[10][10], int tam)
{
    int aux[10];
    for (int j = 0; j < tam; j++)
    {
        aux[j] = matriz[1][j];
        matriz[1][j] = matriz[7][j];
        matriz[7][j] = aux[j];
    }
}

void letraB(int matriz[10][10], int tam)
{
    int aux[10];
    for (int i = 0; i < tam; i++)
    {
        aux[i] = matriz[i][3];
        matriz[i][3] = matriz[i][9];
        matriz[i][9] = aux[i];
    }
}

void letraC(int matriz[10][10], int tam)
{
    int aux[10];
    for (int i = 0; i < tam; i++)
    {
        aux[i] = matriz[i][i];
    }

    for (int i = 0; i < tam; i++)
    {
        matriz[i][i] = matriz[i][tam - 1 - i];
        matriz[i][tam - 1 - i] = aux[i];
    }
}

void letraD(int matriz[10][10], int tam)
{
    int aux[10], contador = 0;

    for(int i = 0; i < tam;i++)
    {
        for(int j = 0; j < tam;j++)
        {
            if(i==4)
            {
                aux[contador] = matriz[i][j];
                contador++;
            }
        }
    }

    for(int i = 0; i < tam;i++)
    {
        matriz[4][i] = matriz[i][9];
    }
    for(int i = 0; i<tam;i++)
    {
        matriz[i][9] = aux[i];
    }
}

void exibeMatriz(int matriz[10][10], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
}

int main()
{
    int M[10][10];
    preencheMatriz(M,10);
    letraA(M, 10);
    letraB(M, 10);
    letraC(M, 10);
    letraD(M, 10);
    exibeMatriz(M, 10);
    return 0;
}


