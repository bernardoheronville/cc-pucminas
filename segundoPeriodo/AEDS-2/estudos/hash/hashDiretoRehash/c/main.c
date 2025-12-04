#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Hash {
    int *tabela, tam;
} Hash;

Hash *criarHash(int x) {
    Hash *nova = (Hash*)malloc(sizeof(Hash));
    nova->tabela = (int*)malloc(x * sizeof(int));
    nova->tam = x;
    for(int i = 0; i < nova->tam; i++) {
        nova->tabela[i] = -1;
    }
    return nova;
}

int h(Hash *hash, int x) {
    return x % hash->tam;
}
int res(Hash *hash, int x) {
    return ++x % hash->tam;
}

void inserir(Hash *hash, int x) {
    if(x != -1) {
        int num = h(hash, x);
        if(hash->tabela[num] == -1) hash->tabela[num] = x;
        else {
            int rehash = res(hash, x);
            if(hash->tabela[rehash] == -1) hash->tabela[rehash] = x;
            else printf("Nao eh possivel inserir o numero %d\n", x);
        }
    }
}

int remover(Hash *hash, int x) {
    int resp = -1;
    if(x != -1) {
        int num = h(hash, x);
        if(hash->tabela[num] == x) {
            hash->tabela[num] = -1;
            resp = x;
        }
        else {
            int rehash = res(hash, x);
            if(hash->tabela[rehash] == x) {
                hash->tabela[rehash] = -1;
                resp = x;
            }
        }
    }
    return resp;
}

bool pesquisarAux(Hash *hash, int x) {
    bool resp = false;
    if(x != -1) {
        int num = h(hash, x);
        if(hash->tabela[num] == x) {
            resp = true;
        }
        else {
            int rehash = res(hash, x);
            if(hash->tabela[rehash] == x) {
                resp = true;
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

int mostrar(Hash *hash) {
    for(int i = 0; i < hash->tam; i++) {
        printf("%d ", hash->tabela[i]);
    }
    printf("\n");
}

void freeHash(Hash *hash) {
    free(hash->tabela);
    free(hash);
}

int main() {
    Hash *h = criarHash(7);
    inserir(h, 5);
    inserir(h, 7);
    inserir(h, 14);
    inserir(h, 21);
    inserir(h, 19);
    inserir(h, 1);
    mostrar(h);
    pesquisar(h, 19);
    remover(h, 19);
    mostrar(h);
    pesquisar(h, 19);
    freeHash(h);
    return 0;
}