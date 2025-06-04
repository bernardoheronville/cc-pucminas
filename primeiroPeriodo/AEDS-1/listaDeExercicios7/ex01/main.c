#include <stdio.h>
#include <stdlib.h>

#define TAM 40

typedef struct
{
    char nome[20];
    int dia;
    int mes;
} Pessoa;

void preenche(Pessoa vet[TAM])
{
    char enter;
    for(int i=0; i<TAM; i++)
    {
        scanf("%s",vet[i].nome);
        scanf("%d",&vet[i].dia);
        scanf("%d",&vet[i].mes);
        scanf("%c",&enter);
    }
}

void exibe(Pessoa vet[TAM])
{
    for(int i=1; i<=12; i++)
    {
        printf("Aniversariantes do mes %d:\n",i);
        for(int j=0; j<TAM; j++)
        {
            if(vet[j].mes == i)
            {
                printf("Nome: %s, Dia: %d\n",vet[j].nome,vet[j].dia);
            }
        }
        printf("\n");
    }
}

int main()
{
    Pessoa vet[TAM];
    preenche(vet);
    exibe(vet);
    return 0;
}
