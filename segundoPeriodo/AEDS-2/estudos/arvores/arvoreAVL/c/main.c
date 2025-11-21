#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

No *rotacionarDir(No *no) {
    No *noEsq = no->esq;
    No *noEsqDir = noEsq->dir;
    noEsq->dir = no;
    no->esq = noEsqDir;
    setNivel(no);
    setNivel(noEsq);
    return noEsq;
}
No *rotacionarEsq(No *no) {
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;
    noDir->esq = no;
    no->dir = noDirEsq;
    setNivel(no);
    setNivel(noDir);
    return noDir;
}
No *balancear(No *no) {
    if(no != NULL) {
        setNivel(no);
        int fator = getFator(no);
        if(fator == 2) {
            int fatorDir = getFator(no->dir);
            if(fatorDir == -1) no->dir = rotacionarDir(no->dir);
            return rotacionarEsq(no);
        }
        else if(fator == -2) {
            int fatorEsq = getFator(no->esq);
            if(fatorEsq == 1) no->esq = rotacionarEsq(no->esq);
            return rotacionarDir(no);
        }
    }
    return no;
}

No *inserirAux(int x, No *i) {
    if(i == NULL) i = criarNo(x);
    else if(x > i->elemento) i->dir = inserirAux(x, i->dir);
    else if(x < i->elemento) i->esq = inserirAux(x, i->esq);
    else printf("Elemento %d ja tem na arvore\n", x);
    return balancear(i);
}
void inserir(int x, ArvoreAVL *arvore) {
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
    return balancear(i);
}
void remover(int x, ArvoreAVL *arvore) {
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
void pesquisar(int x, ArvoreAVL *arvore) {
    if(pesquisarAux(x, arvore->raiz)) {
        printf("Elemento %d encontrado!\n", x);
    }
    else {
        printf("Elemento %d nao encontrado!\n", x);
    }
}

void caminharCentralAux(No *i) {
    if(i != NULL) {
        caminharCentralAux(i->esq);
        printf("%d ", i->elemento);
        caminharCentralAux(i->dir);
    }
}
void caminharCentral(ArvoreAVL *arvore) {
    caminharCentralAux(arvore->raiz);
    printf("\n");
}

void freeArvoreAux(No *i) {
    if(i != NULL) {
        freeArvoreAux(i->esq);
        freeArvoreAux(i->dir);
        free(i);
    }
}
void freeArvore(ArvoreAVL *arvore) {
    freeArvoreAux(arvore->raiz);
    free(arvore);
}

int main() {
    ArvoreAVL *arvore = criarArvore();
    inserir(3, arvore);
    inserir(7, arvore);
    inserir(5, arvore);
    caminharCentral(arvore);
    remover(3, arvore);
    caminharCentral(arvore);
    pesquisar(1, arvore);
    freeArvore(arvore);
    return 0;
}