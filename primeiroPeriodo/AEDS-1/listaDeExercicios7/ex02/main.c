#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    char *nome;
    char *telefone;
    float preco;
}Loja;

void cadastro(Loja *vet)
{
    for(int i=0;i<TAM;i++)
    {
        (vet+i)->nome=(char*)malloc(20*sizeof(char));
        (vet+i)->telefone=(char*)malloc(20*sizeof(char));
        scanf("%s",(vet+i)->nome);
        scanf("%s",(vet+i)->telefone);
        scanf("%f",&(vet+i)->preco);
    }
}

void calculoMedia(Loja *vet)
{
    float soma=0;
    for(int i=0;i<TAM;i++)
    {
        soma += (vet+i)->preco;
    }
    float media = soma/TAM;
    printf("A media dos precos cadastrados eh: %.2f\n",media);
    printf("Lojas com precos abaixo da media:\n");
    for(int i=0;i<TAM;i++)
    {
        if((vet+i)->preco < media)
        {
            printf("Nome: %s\n",(vet+i)->nome);
            printf("Telefone: %s\n",(vet+i)->telefone);
        }
    }
}

int main()
{
    Loja *vet = (Loja*)malloc(TAM*sizeof(Loja));
    cadastro(vet);
    calculoMedia(vet);
    free(vet);
    return 0;
}
