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

int getNivel(No *no) {
    if(no == NULL) return 0;
    else return no->nivel;
}
void setNivel(No *no) {
    int maior;
    if(getNivel(no->esq) > getNivel(no->dir)) maior = getNivel(no->esq);
    else maior = getNivel(no->dir);
    no->nivel = 1 + maior;
}
int getFator(No *no) {
    return getNivel(no->dir) - getNivel(no->esq);
}

void inserir(int x, ArvoreAVL *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}
No *inserirAux(int x, No *i) {
    if(i == NULL) i = criarNo(x);
    else if(x > i->elemento) i->dir = inserirAux(x, i->dir);
    else if(x < i->elemento) i->esq = inserirAux(x, i->esq);
    else printf("Elemento %d ja tem na arvore\n", x);
    return balancear(i);
}

int main() {

    return 0;
}