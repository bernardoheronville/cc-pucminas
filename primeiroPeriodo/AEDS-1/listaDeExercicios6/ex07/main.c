#include <stdio.h>
#include <stdlib.h>

int *matrizSubtrai(int matrizA[][6],int matrizB[][6])
{

    int *matrizD = (int*)malloc(4*6*sizeof(int));

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            *(matrizD+(i*6)+j) = matrizA[i][j] - matrizB[i][j];
        }
    }

    return matrizD;
}

int *matrizSoma(int matrizA[][6],int matrizB[][6])
{

    int *matrizS = (int*)malloc(4*6*sizeof(int));

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            *(matrizS+(i*6)+j) = matrizA[i][j] + matrizB[i][j];
        }
    }
    return matrizS;
}

void preencheMatriz()
{
    int matrizA[4][6],matrizB[4][6];

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%d",&matrizA[i][j]);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%d",&matrizB[i][j]);
        }
    }

    int *resultadoSoma = matrizSoma(matrizA,matrizB);
    int *resultadoSub = matrizSubtrai(matrizA,matrizB);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6;j++)
        {
            printf("%d ",*(resultadoSoma+(i*6)+j));
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6;j++)
        {
            printf("%d ",*(resultadoSub+(i*6)+j));
        }
    }
    free(resultadoSoma);
    free(resultadoSub);
}

int main()
{
    preencheMatriz();
    return 0;
}
