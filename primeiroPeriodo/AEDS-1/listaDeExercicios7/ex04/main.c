#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int codigo;
    char doacao;
    char obra[20];
    char autor[20];
    char editora[20];
} Livro;

void cadastroLivros(Livro vet[TAM])
{
    for(int i=0; i<TAM; i++)
    {
        scanf("%d",vet[i].codigo);
        scanf("%c",vet[i].doacao);
        scanf("%s",vet[i].obra);
        scanf("%s",vet[i].autor);
        scanf("%s",vet[i].editora);
    }
}


int main()
{
    Livro vetor[TAM];
    cadastroLivros(vetor);
    return 0;
}
