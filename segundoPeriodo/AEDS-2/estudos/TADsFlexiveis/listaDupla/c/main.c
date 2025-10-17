#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento;
    struct Celula *prox;
    struct Celula *ant;
} Celula;
typedef struct ListaDupla {
    Celula *primeiro;
    Celula *ultimo;
} ListaDupla;

Celula *criarCelula(int x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = nova->ant = NULL;
    return nova;
}
ListaDupla *criarLista() {
    ListaDupla *nova = (ListaDupla*)malloc(sizeof(ListaDupla));
    nova->primeiro = criarCelula(0);
    nova->ultimo = nova->primeiro;
    return nova;
}

int tamanho(ListaDupla *lista);

void inserirInicio(ListaDupla *lista, int x) {
    lista->primeiro->elemento = x;
    Celula *tmp = criarCelula(0);
    tmp->prox = lista->primeiro;
    lista->primeiro->ant = tmp;
    lista->primeiro = tmp;
    tmp = NULL;
}
void inserirFim(ListaDupla *lista, int x) {
    lista->ultimo->prox = criarCelula(x);
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
}
void inserir(ListaDupla *lista, int x, int pos) {
    if(pos < 0 || pos > tamanho(lista)) {
        printf("Posicao invalida\n");
    }
    else if(pos == 0) {
        inserirInicio(lista, x);
    }
    else if(pos == tamanho(lista)) {
        inserirFim(lista, x);
    }
    else {
        Celula *i = lista->primeiro;
        for(int j = 0; j < pos; j++, i = i->prox);
        Celula *tmp = criarCelula(x);
        tmp->prox = i->prox;
        tmp->prox->ant = tmp;
        i->prox = tmp;
        tmp->ant = i;
        tmp = i = NULL;
    }
}

int removerInicio(ListaDupla *lista) {
    if (lista->primeiro == lista->ultimo) {
        return -1;
    }
    Celula *tmp = lista->primeiro->prox;
    int resp = tmp->elemento;
    lista->primeiro->prox = tmp->prox;
    if (tmp->prox != NULL) {
        tmp->prox->ant = lista->primeiro;
    } else {
        lista->ultimo = lista->primeiro;
    }
    free(tmp);
    return resp;
}

int removerFim(ListaDupla *lista) {
    if(lista->primeiro == lista->ultimo) {
        return -1;
    }
    int resp = lista->ultimo->elemento;
    Celula *tmp = lista->ultimo;
    lista->ultimo = tmp->ant;
    lista->ultimo->prox = NULL;
    tmp->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}
int remover(ListaDupla *lista, int pos) {
    int resp;
    if(lista->primeiro == lista->ultimo || pos < 0 || pos >= tamanho(lista)) {
        return -1;
    }
    else if(pos == 0) {
        resp = removerInicio(lista);
    }
    else if(pos == tamanho(lista) - 1) {
        resp = removerFim(lista);
    }
    else {
        Celula *tmp = lista->primeiro->prox;
        for(int i = 0; i < pos; i++, tmp = tmp->prox);
        resp = tmp->elemento;
        tmp->ant->prox = tmp->prox;
        tmp->prox->ant = tmp->ant;
        tmp->prox = tmp->ant = NULL;
        free(tmp);
        tmp = NULL;
    }
    return resp;
}

int tamanho(ListaDupla *lista) {
    int count = 0;
    for(Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        count++;
    }
    return count;
}

void mostrar(ListaDupla *lista) {
    for(Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("\n");
}

void freeLista(ListaDupla *lista) {
    Celula *i = lista->primeiro;
    while(i != NULL) {
        Celula *tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(lista);
}

int main() {
    ListaDupla *lista = criarLista();
    inserirInicio(lista, 3);
    inserirInicio(lista, 5);
    inserirInicio(lista, 7);
    mostrar(lista); // 7 5 3
    inserirFim(lista, 10);
    mostrar(lista); // 7 5 3 10
    inserir(lista, 13, 2);
    mostrar(lista); // 7 5 13 3 10
    printf("Elemento %d removido\n", removerInicio(lista));
    mostrar(lista); // 5 13 3 10
    printf("Elemento %d removido\n", removerFim(lista));
    mostrar(lista); // 5 13 3
    printf("Elemento %d removido\n", remover(lista, 1));
    mostrar(lista); // 5 3
    freeLista(lista);
    return 0;
}