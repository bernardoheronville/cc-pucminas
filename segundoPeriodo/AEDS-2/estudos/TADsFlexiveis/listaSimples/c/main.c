#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

int tamanho(Lista *lista);

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

Lista *criarLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = criarCelula(0);
    lista->ultimo = lista->primeiro;
    return lista;
}

void inserirInicio(Lista *lista, int x) {
    lista->primeiro->elemento = x;
    Celula *tmp = criarCelula(0);
    tmp->prox = lista->primeiro;
    lista->primeiro = tmp;
    tmp = NULL;
}
void inserirFim(Lista *lista, int x) {
    lista->ultimo->prox = criarCelula(x);
    lista->ultimo = lista->ultimo->prox;
}
void inserir(Lista *lista, int x, int pos) {
    if(pos < 0 || pos > tamanho(lista)) {
        printf("Posicoes invalidas\n");
    }
    else if(pos == 0) {
        inserirInicio(lista, x);
    }
    else if(pos == tamanho(lista)) {
        inserirFim(lista, x);
    }
    else {
        Celula *tmp = lista->primeiro;
        for(int i = 0; i < pos; i++, tmp = tmp->prox);
        Celula *nova = criarCelula(x);
        nova->prox = tmp->prox;
        tmp->prox = nova;
        tmp = nova = NULL;
    }
}

int removerInicio(Lista *lista) {
    if(lista->primeiro == lista->ultimo) {
        return -1;
    }
    Celula *tmp = lista->primeiro->prox;
    int resp = tmp->elemento;
    lista->primeiro->prox = tmp->prox;
    free(tmp);
    tmp = NULL;
    return resp;
}

int removerFim(Lista *lista) {
    if(lista->primeiro == lista->ultimo) {
        return -1;
    }
    int resp = lista->ultimo->elemento;
    Celula *i;
    for(i = lista->primeiro; i->prox != lista->ultimo; i = i->prox);
    free(lista->ultimo);
    lista->ultimo = i;
    i = lista->ultimo->prox = NULL;
    return resp;
}

int remover(Lista *lista, int pos) {
    int resp;
    if(lista->primeiro == lista->ultimo || pos < 0 || pos > tamanho(lista)) {
        return -1;
    }
    else if(pos == 0) {
        resp = removerInicio(lista);
    }
    else if(pos == tamanho(lista) - 1) {
        resp = removerFim(lista);
    }
    else {
        Celula *tmp = lista->primeiro;
        for(int i = 0;i < pos; i++, tmp = tmp->prox);
        Celula *remover = tmp->prox;
        resp = remover->elemento;
        tmp->prox = remover->prox;
        free(remover);
        tmp = remover = NULL;
    }
    return resp;
}

int tamanho(Lista *lista) {
    int count = 0;
    for (Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        count++;
    }    
    return count;
}

void mostrar(Lista *lista) {
    for(Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("\n");
}


void freeLista(Lista *lista) {
    Celula *i = lista->primeiro;
    while (i != NULL) {
        Celula *tmp = i;
        i = i->prox;
        free(tmp);
    }
    free(lista);
}

int main() {
    Lista *lista = criarLista();
    inserirInicio(lista, 3);
    inserirInicio(lista, 5);
    inserirInicio(lista, 7);
    mostrar(lista); // 7 5 3
    inserirFim(lista, 13);
    inserirFim(lista, 20);
    mostrar(lista); // 7 5 3 13 20
    inserir(lista, 8,2);
    mostrar(lista); // 7 5 8 3 13 20
    printf("Elemento %d removido\n", removerInicio(lista));
    mostrar(lista); // 5 8 3 13 20
    printf("Elemento %d removido\n", removerFim(lista));
    mostrar(lista); // 5 8 3 13
    printf("Elemento %d removido\n", remover(lista, 1));
    mostrar(lista); // 5 3 13
    freeLista(lista);
    return 0;
}