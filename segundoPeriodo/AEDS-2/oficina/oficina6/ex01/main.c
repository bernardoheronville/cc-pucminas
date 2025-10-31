#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Item Item;
typedef struct Pilha Pilha;
typedef struct Pessoa Pessoa;
typedef struct Lista Lista;
typedef struct No No;
typedef struct Arvore Arvore;

struct Item {
    int id;
    Item *prox;
};

struct Pilha {
    Item *topo;
};

struct Pessoa {
    char *nome;
    Pessoa *prox;
    Pilha *pedidos;
};

struct Lista {
    Pessoa *primeiro;
    Pessoa *ultimo;
    Pilha *inf;
};

struct No {
    int num;
    No *esq;
    No *dir;
    Lista *pessoas;
};

struct Arvore {
    No *raiz;
};

Item *criarItem(int x) {
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->id = x;
    novo->prox = NULL;
    return novo;
}

Pilha *criarPilha() {
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

Pessoa *criarPessoa(char *nome) {
    Pessoa *nova = (Pessoa*)malloc(sizeof(Pessoa));
    nova->nome = strdup(nome);
    nova->prox = NULL;
    nova->pedidos = criarPilha();
    return nova;
}

Lista *criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    nova->primeiro = (Pessoa*)malloc(sizeof(Pessoa));
    nova->primeiro->nome = NULL;
    nova->primeiro->prox = NULL;
    nova->primeiro->pedidos = NULL;
    nova->ultimo = nova->primeiro;
    nova->inf = criarPilha();
    return nova;
}

No *criarNo(int x) {
    No *novo = (No*)malloc(sizeof(No));
    novo->num = x;
    novo->esq = novo->dir = NULL;
    novo->pessoas = criarLista();
    return novo;
}

Arvore *criarArvore() {
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}


No *inserirAux(int x, No *i) {
    if (i == NULL) i = criarNo(x);
    else if (x > i->num) i->dir = inserirAux(x, i->dir);
    else if (x < i->num) i->esq = inserirAux(x, i->esq);
    return i;
}

void inserir(int x, Arvore *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}

No *pesquisarAux(int x, No *i) {
    while (i != NULL) {
        if (x > i->num) i = i->dir;
        else if (x < i->num) i = i->esq;
        else return i;
    }
    return NULL;
}

No *pesquisar(int x, Arvore *arvore) {
    return pesquisarAux(x, arvore->raiz);
}

void inserirLista(int x, char *nome, Arvore *arvore) {
    No *mesa = pesquisar(x, arvore);
    if (mesa == NULL) return;
    mesa->pessoas->ultimo->prox = criarPessoa(nome);
    mesa->pessoas->ultimo = mesa->pessoas->ultimo->prox;
}

void inserirItem(int x, char *nome, int id, Arvore *arvore) {
    No *mesa = pesquisar(x, arvore);
    if (mesa == NULL) return;
    for (Pessoa *p = mesa->pessoas->primeiro->prox; p != NULL; p = p->prox) {
        if (strcmp(p->nome, nome) == 0) {
            Item *novo = criarItem(id);
            novo->prox = p->pedidos->topo;   
            p->pedidos->topo = novo;
            break;
        }
    }
}

void mostrarAux(No *i) {
    if (i != NULL) {
        mostrarAux(i->esq);
        printf("Mesa %d\n", i->num);
        for (Pessoa *p = i->pessoas->primeiro->prox; p != NULL; p = p->prox) {
            printf("  Pessoa: %s\n", p->nome);
            for (Item *item = p->pedidos->topo; item != NULL; item = item->prox)  
                    printf("    Pedido: %d\n", item->id);
        }
        mostrarAux(i->dir);
    }
}

void mostrar(Arvore *arvore) {
    mostrarAux(arvore->raiz);
}

void freePilha(Pilha *p) {
    Item *atual = p->topo;
    while (atual != NULL) {
        Item *tmp = atual;
        atual = atual->prox;
        free(tmp);
    }
    free(p);
}

void freeLista(Lista *l) {
    Pessoa *atual = l->primeiro;
    while (atual != NULL) {
        Pessoa *tmp = atual;
        atual = atual->prox;
        if (tmp->pedidos) freePilha(tmp->pedidos);
        free(tmp->nome);
        free(tmp);
    }
    free(l);
}

void freeArvoreAux(No *i) {
    if (i != NULL) {
        freeArvoreAux(i->esq);
        freeArvoreAux(i->dir);
        freeLista(i->pessoas);
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

    inserirLista(3, "Joao", arvore);
    inserirLista(5, "Maria", arvore);
    inserirItem(3, "Joao", 10, arvore);
    inserirItem(5, "Maria", 20, arvore);

    mostrar(arvore);
    freeArvore(arvore);
    return 0;
}
