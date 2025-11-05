#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

Celula *inicio;
Celula *fim;

void Meiose() {
    if (inicio != NULL) { 
        for(Celula *i = inicio; i != NULL; i = i->prox->prox) {
            i->elemento = i->elemento / 2;
            Celula *tmp = criarCelula(i->elemento);
            tmp->prox = i->prox;
            i->prox = tmp;
            tmp = NULL;
        }
        fim = fim->prox; 
    }
}