#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Hash {
    int *tabela, tamNormal, tamReserva, tamTotal, reserva;
} Hash;

Hash *criarHash(int x, int y) {
    Hash *nova = (Hash*)malloc(sizeof(Hash));
    nova->tamNormal = x;
    nova->tamReserva = y;
    nova->tamTotal = x + y;
    nova->tabela = (int*)malloc(nova->tamTotal * sizeof(int));
    for(int i = 0; i < nova->tamTotal; i++) {
        *(nova->tabela + i) = -1;
    }
    nova->reserva = 0;
    return nova;
}

int hashar(Hash *hash, int x) {
    return x % hash->tamNormal;
}

void inserir(Hash *hash, int x) {
    if(x != -1) {
        int num = hashar(hash, x);
        if(hash->tabela[num] == -1) hash->tabela[num] = x;
        else if(hash->reserva < hash->tamReserva) {
            for(int i = 0; i < hash->tamReserva; i++) {
                if(hash->tabela[hash->tamNormal + i] == -1) {
                    hash->tabela[hash->tamNormal + i] = x;
                    hash->reserva++;
                    i = hash->tamReserva;
                }
            }
        }
        else {
            printf("Hash cheio\n");
        }
    }
    else {
        printf("Nao pode inserir o -1\n");
    }
}

int remover(Hash *hash, int x) {
    int resp = -1;
    if(x != -1) {
        int num = hashar(hash, x);
        if(hash->tabela[num] == x) {
            resp = x;
            hash->tabela[num] = -1;
        }
        else {
            for(int i = 0; i < hash->tamReserva; i++) {
                if(hash->tabela[hash->tamNormal + i] == x) {
                    resp = x;
                    hash->tabela[hash->tamNormal + i] = -1;
                    hash->reserva--;
                    i = hash->tamReserva;
                }
            }
        }
    }
    return resp;
}

bool pesquisarAux(Hash *hash, int x) {
    bool resp = false;
    if(x != -1) {
        int num = hashar(hash, x);
        if(hash->tabela[num] == x) {
            resp = true;
        }
        else {
            for(int i = 0; i < hash->tamReserva; i++) {
                if(hash->tabela[hash->tamNormal + i] == x) {
                    resp = true;
                    i = hash->tamReserva;
                }
            }
        }
    }
    return resp;
}
void pesquisar(Hash *hash, int x) {
    if(pesquisarAux(hash, x)) {
        printf("Elemento %d encontrado\n", x);
    }
    else {
        printf("Elemento %d nao encontrado\n", x);
    }
}

void mostrar(Hash *hash) {
    for(int i = 0; i < hash->tamTotal; i++) {
        printf("%d ", hash->tabela[i]);
    }
    printf("\n");
}

void freeHash(Hash *hash) {
    free(hash->tabela);
    free(hash);
}

int main() {
    Hash *h = criarHash(7, 3);
    inserir(h, 5);
    inserir(h, 7);
    inserir(h, 14);
    inserir(h, 21);
    inserir(h, 19);
    mostrar(h);
    pesquisar(h, 19);
    freeHash(h);
    return 0;
} 
