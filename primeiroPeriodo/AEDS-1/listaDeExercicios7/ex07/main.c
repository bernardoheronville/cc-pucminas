#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   float largura;
   float altura;
   float area;
} Retangulo;

void preenche(Retangulo *vet, int tam)
{
    for(int i=0;i<tam;i++)
    {
        scanf("%f",&((vet+i)->largura));
        scanf("%f",&((vet+i)->altura));
    }
}

void calculaArea(Retangulo *vet, int tam)
{
    for(int i=0;i<tam;i++)
    {
        float area;
        area = ((vet+i)->largura) * ((vet+i)->altura);
        printf("A area do retangulo %d eh %.2f\n",i+1,area);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    Retangulo *vetor = (Retangulo*)malloc(N*sizeof(Retangulo));
    preenche(vetor,N);
    calculaArea(vetor,N);
    free(vetor);
    return 0;
}
