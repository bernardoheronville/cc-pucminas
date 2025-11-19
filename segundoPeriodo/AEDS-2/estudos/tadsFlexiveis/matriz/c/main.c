#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *inf, *sup, *esq, *dir;
} Celula;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->inf = nova->sup = nova->esq = nova->dir = NULL;
    return nova;
}

typedef struct Matriz {
    int linhas, colunas;
    Celula *inicio;
} Matriz;

Matriz *criarMatriz(int l, int c) {
    Matriz *nova = (Matriz*)malloc(sizeof(Matriz));
    nova->linhas = l;
    nova->colunas = c;
    nova->inicio = criarCelula(0);
    Celula *tmp = nova->inicio;
    for(int i = 1; i < c; i++, tmp = tmp->dir) {
        tmp->dir = criarCelula(0);
        tmp->dir->esq = tmp;
    }
    Celula *lin = nova->inicio, *col = nova->inicio;
    for(int i = 1; i < l; i++) {
        lin->inf = criarCelula(0);
        lin->inf->sup = lin;
        lin = lin->inf;
        col = lin;
        for(int j = 1; j < c; j++) {
            col->dir = criarCelula(0);
            col->dir->esq = col;
            col = col->dir;
            col->sup = col->esq->sup->dir;
            col->sup->inf = col;
        }
    }
    return nova;
}

void inserir(Matriz *matriz) {
    Celula *l = matriz->inicio, *c = matriz->inicio;
    for(int i = 0; i < matriz->linhas; i++) {
        for(int j = 0; j < matriz->colunas; j++, c = c->dir) {
            scanf("%d", &c->elemento);
        }
        l = l->inf;
        c = l;
    }
}

void mostrar(Matriz *matriz) {
    Celula *l = matriz->inicio, *c;
    for(int i = 0; i < matriz->linhas; i++) {
        c = l;
        for(int j = 0; j < matriz->colunas; j++, c = c->dir) {
            printf("%d ", c->elemento);
        }
        printf("\n");
        l = l->inf;
    }
    c = l = NULL;
}

void removerUltimaColuna(Matriz *matriz) {
    Celula *l = matriz->inicio, *c;
    if(matriz->colunas == 1) {
        while(l != NULL) {
            c = l;
            l = l->inf;
            free(c);
        }
    }
    else {
        while(l != NULL) {
            for(c = l; c->dir != NULL; c = c->dir);
            c->esq->dir = NULL;
            c->esq = NULL;
            free(c);
            l = l->inf; 
        }
    }
    matriz->colunas--;
}

void freeMatriz(Matriz *matriz) {
    Celula *l = matriz->inicio, *c;
    while(l != NULL) {
        c = l;
        l = l->inf;
        while(c != NULL) {
            Celula *tmp = c->dir;
            free(c);
            c = tmp;
        }
    }
    free(matriz);
}

int main() {
    Matriz *matriz = criarMatriz(3, 3);
    inserir(matriz);
    mostrar(matriz);
    removerUltimaColuna(matriz);
    mostrar(matriz);
    freeMatriz(matriz);
    return 0;
}