#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

typedef struct Pilha {
    Celula *topo;
} Pilha;

Pilha *criarPilha() {
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

void push(Pilha *pilha, int x) {
    Celula *nova = criarCelula(x);
    nova->prox = pilha->topo;
    pilha->topo = nova;
    nova = NULL;
}

int pop(Pilha *pilha) {
    if(pilha->topo == NULL) {
        printf("EMPTY\n");
        return -1;
    }
    else {
        int resp = pilha->topo->elemento;
        Celula *tmp = pilha->topo;
        pilha->topo = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        tmp = NULL;
        return resp;
    }
}

void min(Pilha *pilha) {
    if(pilha->topo == NULL) {
        printf("EMPTY\n");
    }
    else {
        int min = INT_MAX;
        for(Celula *i = pilha->topo; i != NULL; i = i->prox) {
            if(i->elemento < min) min = i->elemento;
        }
        printf("%d\n", min);
    }
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
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char acao[10];
        scanf("%s", acao);
        if(strcmp(acao, "PUSH") == 0) {
            int num;
            scanf("%d", &num);
            push(pilha, num);
        }
        else if(strcmp(acao, "POP") == 0) {
            pop(pilha);
        }
        else if(strcmp(acao, "MIN") == 0) {
            min(pilha);
        }
        else ;
    }
    freePilha(pilha);
}