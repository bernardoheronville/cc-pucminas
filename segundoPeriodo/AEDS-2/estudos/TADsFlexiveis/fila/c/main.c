#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

typedef struct Fila {
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

Fila *criarFila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->primeiro = criarCelula(0);
    fila->ultimo = fila->primeiro;
    return fila;
}

void inserir(Fila *fila, int x) {
    Celula *nova = criarCelula(x);
    fila->ultimo->prox = nova;
    fila->ultimo = nova;
    nova = NULL;
}

int remover(Fila *fila) {
    if(fila->primeiro == fila->ultimo) {
        return -1;
    }
    Celula *tmp = fila->primeiro->prox;
    int resp = tmp->elemento;
    fila->primeiro->prox = tmp->prox;
    free(tmp);
    tmp = NULL;
    return resp;
}

void mostrar(Fila *fila) {
    for(Celula *i = fila->primeiro->prox; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("\n");
}

void freeFila(Fila *fila) {
    Celula *i = fila->primeiro;
    while(i != NULL) {
        Celula *tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(fila);
}

int main() {
    Fila *fila = criarFila();
    inserir(fila, 3);
    inserir(fila, 5);
    inserir(fila, 7);
    mostrar(fila); // 3 5 7
    printf("Elemento %d removido\n", remover(fila));
    mostrar(fila); // 5 7
    freeFila(fila);
    return 0;
}