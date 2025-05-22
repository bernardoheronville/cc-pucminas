#include <stdio.h>
#include <stdlib.h>

void OrganizaVetor(int vet1[],int vet2[],int tam)
{
    int organiza[20];

    for (int i = 0; i < tam; i++)
    {
        organiza[2 * i] = vet1[i];
        organiza[2 * i + 1] = vet2[i];
    }
    ExibeMatriz(organiza);
}

void ExibeMatriz(int vetor3[])
{

    for(int i=0;i<20;i++)
    {
        printf("%d ",vetor3[i]);
    }
}

void PreencherVetor(int vetor1[], int vetor2[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        scanf("%d",&vetor1[i]);
    }
    for(int i=0;i<tam;i++)
    {
        scanf("%d",&vetor2[i]);
    }
    OrganizaVetor(vetor1,vetor2,tam);
}

int main()
{
    int X[10],Y[10],tam=10;
    PreencherVetor(X,Y,tam);
    return 0;
}


