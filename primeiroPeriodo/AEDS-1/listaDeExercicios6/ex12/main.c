#include <stdio.h>
#include <string.h>

void troca(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutacoes(char *vetor, int inicio, int fim) {
    if (inicio == fim) {
        printf("%s ", vetor);
    } else {
        for (int i = inicio; i <= fim; i++) {
            troca((vetor + inicio), (vetor + i));
            permutacoes(vetor, inicio + 1, fim);
            troca((vetor + inicio), (vetor + i));
        }
    }
}

int main() {
    char *vetor;
    vetor = (char*)malloc(100*sizeof(char));
    scanf("%s", vetor);
    int tamanho = strlen(vetor);
    printf("As permutacoes da string sao:\n", vetor);
    permutacoes(vetor, 0, tamanho - 1);
    free(vetor);
    return 0;
}

