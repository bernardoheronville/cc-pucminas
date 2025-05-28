#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int mat[][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            mat[i][j] = rand()%31;
        }
    }
}

void exibeMatriz(int mat[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
}

void somaLinha(int mat[][5])
{
    int soma=0,linha;
    printf("Digite a linha que vc quer somar: ");
    scanf("%d",&linha);
    for(int j=0;j<5;j++)
    {
        soma += mat[linha][j];
    }
    printf("A soma da linha %d eh %d\n",linha,soma);
}

void somaColuna(int mat[][5])
{
    int soma=0,coluna;
    printf("Digite a coluna que vc quer somar: ");
    scanf("%d",&coluna);
    for(int i=0;i<5;i++)
    {
        soma += mat[i][coluna];
    }
    printf("A soma da coluna %d eh %d\n",coluna,soma);
}

void somaDiagonalPrincipal(int mat[][5])
{
    int soma=0;
    for(int i=0;i<5;i++)
    {
        soma += mat[i][i];
    }
    printf("A soma da diagonal principal eh %d\n",soma);
}

void somaDiagonalSecundaria(int mat[][5])
{
    int soma=0;
    for(int i=0;i<5;i++)
    {
        soma += mat[i][5-1-i];
    }
    printf("A soma da diagonal secundaria eh %d\n",soma);
}

void total(int mat[][5])
{
    int soma=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            soma += mat[i][j];
        }

    }
    printf("A soma de todos os elementos eh %d\n",soma);
}

int main()
{
    int mat[5][5];

    srand((unsigned)time(NULL));

    preencheMatriz(mat);
    exibeMatriz(mat);
    somaLinha(mat);
    somaColuna(mat);
    somaDiagonalPrincipal(mat);
    somaDiagonalSecundaria(mat);
    total(mat);

    return 0;
}
