#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

typedef struct Pilha {
    Celula *topo;
} Pilha;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}
Pilha *criarPilha() {
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

void inserir(Pilha *pilha, int x) {
    Celula *nova = criarCelula(x);
    nova->prox = pilha->topo;
    pilha->topo = nova;
    nova = NULL;
}

int remover(Pilha *pilha) {
    if(pilha->topo == NULL) {
        return -1;
    }
    int resp = pilha->topo->elemento;
    Celula *tmp = pilha->topo;
    pilha->topo = tmp->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

void mostrar(Pilha *pilha) {
    for(Celula *i = pilha->topo; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("\n");
}

void freePilha(Pilha *pilha) {
    Celula *i = pilha->topo; 
    while(i != NULL) {
        Celula *tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(pilha);
}

int main() {
    Pilha *pilha = criarPilha();
    inserir(pilha, 3);
    inserir(pilha, 5);
    inserir(pilha, 7);
    mostrar(pilha); // 7 5 3
    printf("Elemento %d removido\n", remover(pilha));
    mostrar(pilha); // 5 3
    freePilha(pilha);
    return 0;
}