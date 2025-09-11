#include <stdio.h>

typedef struct {
    char nome[21];
    int idade;
} Duendes;

void ordenar(Duendes duendes[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        int idadeMaior = duendes[i].idade, aux = i;
        for(int j = i + 1; j < n; j++) {
            if(idadeMaior > duendes[j].idade) {
                idadeMaior = duendes[j].idade;
                aux = j;
            }
        }
        printf("%d\n",duendes[aux].idade);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    Duendes duendes[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
    ordenar(duendes, n);
    return 0;
}