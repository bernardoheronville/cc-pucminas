#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento, nivel;
    struct No *esq, *dir;
} No;
No *criarNo(int x) {
    No *nova = (No*)malloc(sizeof(No));
    nova->elemento = x;
    nova->dir = nova->esq = NULL;
    nova->nivel = 1;
    return nova;
}

typedef struct ArvoreAVL {
    No *raiz;
} ArvoreAVL;
ArvoreAVL *criarArvore() {
    ArvoreAVL *nova = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    nova->raiz = NULL;
    return nova;
}

void inserir(int x, ArvoreAVL *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}
No *inserirAux(int x, No *i) {
    if(i == NULL) 
}

int main() {

    return 0;
}