#include <stdio.h>

typedef struct {
    char nome[21];
    int idade;
} Duendes;

void ordenar(Duendes duendes[] ,int n) {
    for(int i = 0; i < n; i++) {
        Duendes tmp = duendes[i];
        int j = i - 1;
        while(j >= 0 && duendes[j].idade < tmp.idade || duendes[j].idade == tmp.idade && duendes[j].nome[0] > tmp.nome[0]) {
            duendes[j + 1] = duendes[j];
            j--;
        }
        duendes[j + 1] = tmp;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    Duendes duendes[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
    ordenar(duendes, n);
    int numTimes = n/3;
    for (int i = 0; i < numTimes; i++) {
        printf("Time %d\n", i + 1);
        printf("%s %d\n", duendes[i].nome, duendes[i].idade);                      
        printf("%s %d\n", duendes[i + numTimes].nome, duendes[i + numTimes].idade); 
        printf("%s %d\n", duendes[i + 2 * numTimes].nome, duendes[i + 2 * numTimes].idade);
        printf("\n");
    }
    return 0;
}