#include <stdio.h>
#include <stdlib.h>

#define TAM 15

typedef struct
{
    char nome[20];
    char telefone[20];
    float preco;
}Loja;

void cadastro(Loja vet[TAM])
{
    for(int i=0;i<TAM;i++)
    {
        scanf("%s",vet[i].nome);
        scanf("%s",vet[i].telefone);
        scanf("%f",&vet[i].preco);
    }
}

void calculoMedia(Loja vet[TAM])
{
    float soma=0;
    for(int i=0;i<TAM;i++)
    {
        soma += vet[i].preco;
    }
    float media = soma/TAM;
    printf("A media dos precos cadastrados eh: %.2f\n",media);
    printf("Lojas com precos abaixo da media:\n");
    for(int i=0;i<TAM;i++)
    {
        if((vet+i)->preco < media)
        {
            printf("Nome: %s\n",vet[i].nome);
            printf("Telefone: %s\n",vet[i].telefone);
        }
    }
}

int main()
{
    Loja vet[TAM];
    cadastro(vet);
    calculoMedia(vet);
    return 0;
}
