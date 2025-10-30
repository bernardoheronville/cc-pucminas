#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Item {
    int id;
    struct Item *prox;
} Item;

typedef struct Pessoa {
    char *nome;
    struct Pessoa *prox;
    Item *pedidos;
} Pessoa;

typedef struct No {
    int num;
    struct No *esq;
    struct No *dir;
    Lista *pessoas;
} No;

typedef struct Arvore {
    No *raiz;
} Arvore;

typedef struct Lista {
    Pessoa *primeiro;
    Pessoa *ultimo;
} Lista;

Arvore *criarArvore() {
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}

Item *criarItem(int x) {
    Item *nova = (Item*)malloc(sizeof(Item));
    nova->id = x;
    nova->prox = NULL;
    return nova;
}

Pessoa *criarPessoa(char *nome) {
    Pessoa *nova = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(nome, nova->nome);
    nova->prox = NULL;
    nova->pedidos = criarItem(-1);
    return nova;
}

Lista *criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    nova->primeiro = criarPessoa("");
    nova->ultimo = nova->primeiro;
    return nova;
}

No *criarNo(int x) {
    No *nova = (No*)malloc(sizeof(No));
    nova->num = x;
    nova->dir = NULL;
    nova->esq = NULL;
    nova->pessoas = criarLista();
    return nova;
}

No *inserirAux(int x, No *i) {
    if(i == NULL) i = criarNo(x);
    else if(x > i->num) i->dir = inserirAux(x, i->dir);
    else if(x < i->num) i->esq = inserirAux(x, i->esq);
    else ;
    return i;
}
void inserir(int x, Arvore *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}

No *pesquisarAux(int x, No *i) {
    No *achar;
    while(i != NULL) {
        if(x > i->num) i = i->dir;
        else if(x < i->num) i = i->dir;
        else if(x == i->num) achar = i;
    }
    return achar;
}
No *pesquisar(int x, Arvore *arvore) {
    return pesquisarAux(x, arvore->raiz);
}

void inserirLista(int x, char *nome, Arvore *arvore) {
    No *mesa = pesquisar(x, arvore);
    mesa->pessoas->ultimo->prox = criarPessoa(nome);
    mesa->pessoas->ultimo = mesa->pessoas->ultimo->prox;
}

void inserirItem(int x, char *nome, int id, Arvore *arvore) {
    No *mesa = pesquisar(x, arvore);
    Pessoa *i;
    for(i = mesa->pessoas->primeiro->prox; !strcmp(i->nome, nome); i = i->prox);
    
}

void mostrarAux(No *i) {
    if(i != NULL) {
        mostrarAux(i->esq);
        printf("%d\n", i->num);
        mostrarAux(i->dir);
    }
}
void mostrar(Arvore *arvore) {
    mostrarAux(arvore->raiz);
}

void freeArvoreAux(No *i) {
    if(i != NULL) {
        freeArvoreAux(i->esq);
        freeArvoreAux(i->dir);
        free(i);
    }

}
void freeArvore(Arvore *arvore) {
    freeArvoreAux(arvore->raiz);
    free(arvore);
}

int main() {
    Arvore *arvore = criarArvore();
    inserir(3, arvore);
    inserir(5, arvore);
    inserir(7, arvore);
    mostrar(arvore);
    pesquisar(3, arvore);
    freeArvore(arvore);
    return 0;
}