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

}


int main()
{
    Livro vetor[TAM];
    cadastroLivros(vetor);
    return 0;
}
