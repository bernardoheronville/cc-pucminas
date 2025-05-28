#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int *mat)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            *(mat+i*4+j) = rand()%31;
        }
    }
}

void exibeMatriz(int *mat)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%4d",*(mat+i+4+j));
        }
        printf("\n");
    }
}

void calculaPares(int *mat)
{
    int qPares=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(*(mat+i+4+j) % 2 == 0) qPares++;
        }
    }
    printf("A quantidade de numeros pares eh %d\n",qPares);
}

void somaImpares(int *mat)
{
    int somaImpares=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(*(mat+i+4+j) % 2 != 0) somaImpares += *(mat+i+4+j);
        }
    }
    printf("A soma dos impares eh %d\n",somaImpares);
}

void media(int *mat)
{
    int soma=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            soma += *(mat+i+4+j);
        }
    }
    printf("A media de todos elementos eh %.2f\n",soma/12.0);
}

int main()
{
    int *mat;
    mat = (int*)malloc(3*4*sizeof(int));
    srand((unsigned)time(NULL));
    preencheMatriz(mat);
    exibeMatriz(mat);
    calculaPares(mat);
    somaImpares(mat);
    media(mat);
    free(mat);
    return 0;
}
