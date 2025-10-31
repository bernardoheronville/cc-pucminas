#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Celula {
    char *nome;
    struct Celula *prox;
} Celula;

Celula *criarCelula(char *x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->nome = strdup(x);
    nova->prox = NULL;
    return nova;
}

typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo; 
} Lista;

Lista *criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    nova->primeiro = criarCelula("");
    nova->ultimo = nova->primeiro;
    return nova;
}

void inserir(Lista *lista, char *x) {
    lista->ultimo->prox = criarCelula(x);
    lista->ultimo = lista->ultimo->prox;
}

char *remover(Lista *lista) {
    if(lista->primeiro == lista->ultimo) {
        return strdup("");
    }
    Celula *tmp = lista->primeiro->prox;
    char *resp = strdup(tmp->nome); 
    lista->primeiro->prox = tmp->prox;
    if (tmp == lista->ultimo) lista->ultimo = lista->primeiro;
    free(tmp->nome);
    free(tmp);
    return resp;
}

void freeLista(Lista *lista) {
    Celula *i = lista->primeiro;
    while(i != NULL) {
        Celula *tmp = i->prox;
        free(i->nome);
        free(i);
        i = tmp;
    }
    free(lista);
}

void mostrar(Lista *lista) {
    char *resp = remover(lista);
    if(strcmp(resp, "") != 0) {
        printf("%s ", resp);
    }  
    free(resp);
}

int main() {
    Lista *lista1 = criarLista();
    Lista *lista2 = criarLista();
    Lista *lista3 = criarLista();
    Lista *lista4 = criarLista();
    char entrada[10], ponto[10] = "";
    scanf("%s", entrada);
    while(strcmp(entrada, "0") != 0) {
        if(strcmp(entrada, "-1") == 0 || strcmp(entrada, "-2") == 0 || strcmp(entrada, "-3") == 0 || strcmp(entrada, "-4") == 0) {
            strcpy(ponto, entrada);
        }
        else {
            if(strcmp(ponto, "-1") == 0) {
                inserir(lista1, entrada);
            }
            else if(strcmp(ponto, "-2") == 0) {
                inserir(lista2, entrada);
            }
            else if(strcmp(ponto, "-3") == 0) {
                inserir(lista3, entrada);
            }
            else if(strcmp(ponto, "-4") == 0) {
                inserir(lista4, entrada);
            }
        }
        scanf("%s", entrada);
    }

    while(lista1->primeiro != lista1->ultimo || lista2->primeiro != lista2->ultimo || lista3->primeiro != lista3->ultimo || lista4->primeiro != lista4->ultimo) {
        if(lista1->primeiro != lista1->ultimo) mostrar(lista1);
        if(lista3->primeiro != lista3->ultimo) mostrar(lista3);        
        if(lista2->primeiro != lista2->ultimo) mostrar(lista2);
        if(lista4->primeiro != lista4->ultimo) mostrar(lista4);
    }

    freeLista(lista1);
    freeLista(lista2);
    freeLista(lista3);
    freeLista(lista4);
    return 0;
}
