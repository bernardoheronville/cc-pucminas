#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
    char nome[20];
    char endereco[20];
    char telefone[20];
} Cliente;

void preencheClientes(Cliente vet[TAM])
{
    for(int i=0; i<TAM; i++)
    {
        scanf("%s",vet[i].nome);
        scanf("%s",vet[i].endereco);
        scanf("%s",vet[i].telefone);
    }
}

void exibeClientes(Cliente vet[TAM])
{
    for(int i=0; i<TAM; i++)
    {
        printf("%s %s %s\n",vet[i].nome,vet[i].endereco,vet[i].telefone);
    }
}

int main()
{
    Cliente vetor[TAM];
    preencheClientes(vetor);
    exibeClientes(vetor);
    return 0;
}
