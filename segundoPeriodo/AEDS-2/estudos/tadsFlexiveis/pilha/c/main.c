#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int soma(Pilha *pilha) {
    int soma = 0;
    for(Celula *i = pilha->topo; i != NULL; i = i->prox) {
        soma += i->elemento;
    }
    return soma;
}

int somaRecAux(Celula *i) {
    if(i == NULL) return 0;
    else return i->elemento + somaRecAux(i->prox);
}
int somaRec(Pilha *pilha) {
    return somaRecAux(pilha->topo);
}

int maior(Pilha *pilha) {
    int maior = INT_MIN;
    for(Celula *i = pilha->topo; i != NULL; i = i->prox) {
        if(i->elemento > maior) {
            maior = i->elemento;
        }
    }
    return maior;
}

int maiorRecAux(Celula *i, int maior) {
    if(i == NULL) return maior;
    else if(i->elemento > maior) return maiorRecAux(i->prox, i->elemento);
    else return maiorRecAux(i->prox, maior);
}
int maiorRec(Pilha *pilha) {
    return maiorRecAux(pilha->topo, INT_MIN);
}

void mostrarInvertidoRecAux(Celula *i) {
    if(i != NULL) {
        mostrarInvertidoRecAux(i->prox);
        printf("%d ", i->elemento);
    }
}
void mostrarInvertidoRec(Pilha *pilha) {
    mostrarInvertidoRecAux(pilha->topo);
    printf("\n");
}

void mostrarRecAux(Celula *i) {
    if(i != NULL) {
        printf("%d ", i->elemento);
        mostrarRecAux(i->prox);
    }
}
void mostrarRec(Pilha *pilha) {
    mostrarRecAux(pilha->topo);
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
    inserir(pilha, 3);
    inserir(pilha, 5);
    inserir(pilha, 7);
    printf("A soma dos elementos da pilha eh %d\n", soma(pilha)); // 23
    printf("A soma dos elementos da pilha eh %d\n", somaRec(pilha)); // 23
    printf("O maior elemento da pilha eh %d\n", maior(pilha)); // 7
    printf("O maior elemento da pilha eh %d\n", maiorRec(pilha)); // 7
    mostrarRec(pilha);
    mostrarInvertidoRec(pilha); // 3 5 3 5 7
    freePilha(pilha);
    return 0;
}