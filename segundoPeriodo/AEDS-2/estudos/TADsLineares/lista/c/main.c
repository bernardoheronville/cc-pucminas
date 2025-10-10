#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int n;
    int tam;
} Lista;

void construirLista(Lista *lista, int x) {
    lista->array = (int*)malloc(x * sizeof(int));
    lista->n = 0;
    lista->tam = x;
}

int inserirInicio(Lista *lista, int x) {
    if (lista->n == lista->tam) {
        return -1; 
    }
    for (int i = lista->n; i > 0; i--) {
        lista->array[i] = lista->array[i - 1];
    }
    lista->array[0] = x;
    lista->n++;
    return 0;
}

int inserirFim(Lista *lista, int x) {
    if (lista->n == lista->tam) {
        return -1;
    }
    lista->array[lista->n++] = x;
    return 0;
}

int inserir(Lista *lista, int x, int pos) {
    if (lista->n == lista->tam || pos < 0 || pos > lista->n) {
        return -1;
    }
    for (int i = lista->n; i > pos; i--) {
        lista->array[i] = lista->array[i - 1];
    }
    lista->array[pos] = x;
    lista->n++;
    return 0;
}

int removerInicio(Lista *lista) {
    if (lista->n == 0) {
        return -1; 
    }
    int resp = lista->array[0];
    for (int i = 0; i < lista->n - 1; i++) {
        lista->array[i] = lista->array[i + 1];
    }
    lista->n--;
    return resp;
}

int removerFim(Lista *lista) {
    if (lista->n == 0) {
        return -1;
    }
    int resp = lista->array[lista->n - 1];
    lista->n--;
    return resp;
}

int remover(Lista *lista, int pos) {
    if (lista->n == 0 || pos < 0 || pos >= lista->n) {
        return -1;
    }
    int resp = lista->array[pos];
    for (int i = pos; i < lista->n - 1; i++) {
        lista->array[i] = lista->array[i + 1];
    }
    lista->n--;
    return resp;
}

void mostrar(Lista *lista) {
    for (int i = 0; i < lista->n; i++) {
        printf("%d ", lista->array[i]);
    }
    printf("\n");
}
 
void freeLista(Lista *lista) {
    free(lista->array);
}

int main() {
    Lista lista;
    construirLista(&lista, 5);

    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirInicio(&lista, 5);
    inserir(&lista, 15, 2);
    mostrar(&lista); // 5 10 15 20

    printf("Removido do início: %d\n", removerInicio(&lista));
    mostrar(&lista); // 10 15 20

    printf("Removido do fim: %d\n", removerFim(&lista));
    mostrar(&lista); // 10 15

    printf("Removido da posição 0: %d\n", remover(&lista, 0));
    mostrar(&lista); 

    freeLista(&lista);
    return 0;
}
