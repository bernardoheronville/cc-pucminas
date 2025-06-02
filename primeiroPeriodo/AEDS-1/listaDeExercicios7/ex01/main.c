#include <stdio.h>
#include <stdlib.h>

#define TAM 40

typedef struct
{
    char *nome;
    int dia;
    int mes;
} Pessoa;

void preenche(Pessoa *vet)
{
    for(int i=0; i<TAM; i++)
    {
        (vet+i)->nome=(char*)malloc(20*sizeof(char));
        scanf("%s",(vet+i)->nome);
        scanf("%d",&(vet+i)->dia);
        scanf("%d",&(vet+i)->mes);
    }
}

void exibe(Pessoa *vet)
{
    for(int i=1; i<=12; i++)
    {
        printf("Aniversariantes do mes %d:\n",i);
        for(int j=0; j<TAM; j++)
        {
            if((vet+j)->mes == i)
            {
                printf("Nome: %s, Dia: %d\n",(vet+j)->nome,(vet+j)->dia);
            }
        }
        printf("\n");
    }
}

int main()
{
    Pessoa *vet = (Pessoa*)malloc(TAM*sizeof(Pessoa));
    preenche(vet);
    exibe(vet);
    free(vet);
    return 0;
}
