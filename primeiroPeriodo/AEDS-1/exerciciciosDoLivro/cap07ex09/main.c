#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int mat[][3],int limite)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat[i][j] = rand()%limite+1;
        }
    }
}

void multiplicaMatriz(int mat[][3],int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat[i][j] *= num;
        }
    }
}

void exibeMatriz(int mat[][3])
{
    printf("Matriz resultante: \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][3],num,limite,linhas,colunas;
    srand((unsigned)time(NULL));
    printf("Digite o limite dos numeros sorteados: ");
    scanf("%d",&limite);
    preencheMatriz(mat,limite);
    printf("Digite o valor que vc quer multiplicar: ");
    scanf("%d",&num);
    multiplicaMatriz(mat,num);
    exibeMatriz(mat);
    return 0;
}
