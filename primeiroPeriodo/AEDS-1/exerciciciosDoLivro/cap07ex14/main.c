#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int mat[][3])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat[i][j] = rand()%31;
        }
    }
}

void exibeMatriz(int mat[][3])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
}

int calculaIntervalo(int mat[][3])
{
    int contador=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j] >=5 && mat[i][j] <=15)
            {
                contador++;
            }
        }
    }
    return (contador);
}

int main()
{
    int mat[2][3];
    srand((unsigned)time(NULL));
    preencheMatriz(mat);
    exibeMatriz(mat);
    printf("A quantidade de numeros no intervalo de 5 e 15 eh %d\n",calculaIntervalo(mat));
    return 0;
}
