#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int topo;
    int tam;
} Pilha;

void criarPilha(Pilha *p, int x) {
    p->array = (int*)malloc(x * sizeof(int));
    p->topo = -1;
    p->tam = x;
}

void inserir(Pilha *p, int x) {
    if(p->tam - 1 == p->topo) {
        printf("Pilha cheia\n");
    }
    p->array[++p->topo] = x;
}

int remover(Pilha *p) {
    if(p->topo == -1) {
        printf("Pilha vazia\n");
    }
    int resp = p->array[p->topo--];
    return resp;
}

void mostrar(Pilha *p) {
    if(p->topo == -1) {
        printf("Pilha vazia\n");
    }
    for(int i = p->topo; i >= 0; i--) {
        printf("%d ", p->array[i]);
    }
    printf("\n");
}
void freePilha(Pilha *p) {
    free(p->array);
}

int main() {
    Pilha pilha;
    criarPilha(&pilha, 5);
    inserir(&pilha, 7);
    inserir(&pilha, 3);
    inserir(&pilha, 9);
    mostrar(&pilha);
    remover(&pilha);
    mostrar(&pilha);
    inserir(&pilha, 10);
    mostrar(&pilha);
    freePilha(&pilha);
    return 0;
}