#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int elemento;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int x) {
    No *nova = (No*)malloc(sizeof(No));
    nova->elemento = x;
    nova->dir = NULL;
    nova->esq = NULL;
    return nova;
}

typedef struct Arvore {
    No *raiz;
} Arvore;

Arvore *criarArvore() {
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}

No *inserirAux(int x, No *i) {
    if(i == NULL) i = criarNo(x);
    else if(x > i->elemento) i->dir = inserirAux(x, i->dir);
    else if(x < i->elemento) i->esq = inserirAux(x, i->esq);
    else printf("Elemento %d ja tem na arvore\n", x);
    return i;
}
void inserir(int x, Arvore *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}

No *getMaior(No *i) {
    while(i->dir != NULL) {
        i = i->dir;
    }
    return i;
}
No *removerAux(int x, No *i) {
    if(i == NULL) return NULL;
    else if(x > i->elemento) i->dir = removerAux(x, i->dir);
    else if(x < i->elemento) i->esq = removerAux(x, i->esq);
    else {
        if(i->dir == NULL) {
            No *tmp = i;
            i = i->esq;
            free(tmp);
        }
        else if(i->esq == NULL) {
            No *tmp = i;
            i = i->dir;
            free(tmp);
        }
        else {
            i->elemento = getMaior(i->esq)->elemento;
            i->esq = removerAux(i->elemento, i->esq);
        }
    }
    return i;
}
void remover(int x, Arvore *arvore) {
    arvore->raiz = removerAux(x, arvore->raiz);
}

bool pesquisarAux(int x, No *i) {
    bool resp = false;
    while(i != NULL) {
        if(x > i->elemento) i = i->dir;
        else if(x < i->elemento) i = i->esq;
        else {
            resp = true;
            i = NULL;
        }
    }
    return resp;
}
void pesquisar(int x, Arvore *arvore) {
    if(pesquisarAux(x, arvore->raiz)) {
        printf("Elemento %d encontrado\n", x);
    }
    else {
        printf("Elemento %d nao encontrado\n", x);
    }
}

void caminharCentralAux(No *i) {
    if(i != NULL) {
        caminharCentralAux(i->esq);
        printf("%d\n", i->elemento);
        caminharCentralAux(i->dir);
    }
}
void caminharCentral(Arvore *arvore) {
    caminharCentralAux(arvore->raiz);
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
    inserir(1, arvore);
    inserir(7, arvore);
    inserir(13, arvore);
    inserir(2, arvore);
    inserir(24, arvore);
    caminharCentral(arvore);
    pesquisar(1, arvore);
    remover(1, arvore);
    pesquisar(1, arvore);
    caminharCentral(arvore);
    freeArvore(arvore);
    return 0;
}