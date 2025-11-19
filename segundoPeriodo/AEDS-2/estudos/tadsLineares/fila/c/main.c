#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int primeiro;
    int ultimo;
    int tam;
} Fila;

void criarFila(Fila *fila, int x) {
    fila->array = (int*)malloc((x + 1) * sizeof(int));
    fila->primeiro = fila->ultimo = 0;
    fila->tam = x + 1;
}

int inserir(Fila *fila, int x) {
    if((fila->ultimo + 1) % fila->tam == fila->primeiro) {
        return -1;
    }
    fila->array[fila->ultimo] = x;
    fila->ultimo = (fila->ultimo + 1) % fila->tam;
    return 0;
}

int remover(Fila *fila) {
    if(fila->primeiro == fila->ultimo) {
        return -1;
    }
    int resp = fila->array[fila->primeiro];
    fila->primeiro = (fila->primeiro + 1) % fila->tam;
    return resp;
}

void mostrar(Fila *fila) {
    for(int i = fila->primeiro; i != fila->ultimo; i = (i + 1) % fila->tam) {
        printf("%d ", fila->array[i]);
    }
    printf("\n");
}

void freeFila(Fila *fila) {
    free(fila->array);
}

int main() {
    Fila fila;
    criarFila(&fila, 5);
    inserir(&fila, 5);
    inserir(&fila, 8);
    inserir(&fila, 3);
    mostrar(&fila);
    remover(&fila);
    mostrar(&fila);
    freeFila(&fila);
    return 0;
}