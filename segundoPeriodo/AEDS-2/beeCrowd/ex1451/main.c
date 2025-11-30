#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct String {
    char str[100005];
} String;

typedef struct Celula {
    String frase;
    struct Celula *prox;
} Celula;

Celula *criarCelula(String x) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    strcpy(nova->frase.str, x.str);
    nova->prox = NULL;
    return nova;
}

typedef struct Fila {
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Fila *criarFila() {
    Fila *nova = (Fila*)malloc(sizeof(Fila));
    nova->primeiro = (Celula*)malloc(sizeof(Celula));
    nova->primeiro->prox = NULL;
    nova->ultimo = nova->primeiro;
    return nova;
}

void inserirInicio(Fila *fila, String x) {
    if (strlen(x.str) == 0) return; 
    Celula *nova = criarCelula(x);
    nova->prox = fila->primeiro->prox;
    fila->primeiro->prox = nova;
    if (fila->ultimo == fila->primeiro) {
        fila->ultimo = nova;
    }
}

void inserirFim(Fila *fila, String x) {
    if (strlen(x.str) == 0) return; 
    Celula *nova = criarCelula(x);
    fila->ultimo->prox = nova;
    fila->ultimo = nova;
}

void limparFila(Fila *fila) {
    Celula *p = fila->primeiro->prox;
    while(p != NULL) {
        Celula *tmp = p;
        p = p->prox;
        free(tmp);
    }
    fila->primeiro->prox = NULL;
    fila->ultimo = fila->primeiro;
}

int main() {
    String entrada;
    String buffer; 
    Fila *fila = criarFila();
    while(scanf("%s", entrada.str) != EOF) {
        limparFila(fila);
        buffer.str[0] = '\0'; 
        int bufPos = 0;
        int estado = 1; 
        for(int i = 0; i < strlen(entrada.str); i++) {
            char c = entrada.str[i];
            if(c == '[' || c == ']') {
                buffer.str[bufPos] = '\0';
                if(estado == 0) inserirInicio(fila, buffer);
                else inserirFim(fila, buffer);
                bufPos = 0;
                buffer.str[0] = '\0';
                if (c == '[') estado = 0; 
                else estado = 1;          
            } 
            else {
                buffer.str[bufPos++] = c;
            }
        }
        buffer.str[bufPos] = '\0';
        if(estado == 0) inserirInicio(fila, buffer);
        else inserirFim(fila, buffer);
        for(Celula *i = fila->primeiro->prox; i != NULL; i = i->prox) {
            printf("%s", i->frase.str);
        }
        printf("\n");
    }
    return 0;
}