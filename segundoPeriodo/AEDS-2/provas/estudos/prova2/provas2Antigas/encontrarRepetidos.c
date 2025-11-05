#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula {
    int numero;
    struct Celula *prox;
} Celula;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->numero = x;
    nova->prox = NULL;
    return nova;
}

typedef struct CelulaMatriz {
    int numero;
    struct CelulaMatriz *prox, *ant, *sup, *inf;
} CelulaMatriz;

typedef struct No {
    int numero;
    struct No *esq, *dir;
} No;

Celula *encontrarRepetidos(No *raiz, CelulaMatriz *inicio) {
    Celula *nova = criarCelula(0); 
    for(CelulaMatriz *l = inicio; l != NULL; l = l->inf) { 
        for(CelulaMatriz *c = l; c != NULL; c = c->prox) {
            if(pesquisar(raiz, c->numero)) {
                int valor = c->numero;
                Celula *ant = nova;
                Celula *atual = nova->prox; 
                while (atual != NULL && atual->numero > valor) {
                    ant = atual;
                    atual = atual->prox;
                }
                Celula *novaCelula = criarCelula(valor);
                novaCelula->prox = atual;
                ant->prox = novaCelula;
            }
        }
    }
    return nova; 
}

bool pesquisar(No *i, int x) {
    bool resp = false;
    while(i != NULL) {
        if(x > i->numero) i = i->dir;
        else if(x < i->numero) i = i->esq;
        else {
            resp = true;
            i = NULL;
        }
    }
    return resp;
}