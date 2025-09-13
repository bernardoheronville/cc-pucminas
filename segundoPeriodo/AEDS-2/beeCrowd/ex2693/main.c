#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char nome[256];
    char regiao;
    int distancia;
} Alunos;

void ordenar(Alunos aluno[], int n) {
    for(int i = 1; i < n; i++) {
        Alunos tmp = aluno[i];
        int j = i - 1;
        while(j >= 0 && aluno[j].distancia > tmp.distancia || aluno[j].distancia == tmp.distancia && aluno[j].regiao > tmp.regiao) {
            aluno[j + 1] = aluno[j];
            j--;
        }
        aluno[j + 1] = tmp;
    }
}

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        Alunos aluno[n];
        for(int i = 0 ; i < n; i++) {
            scanf("%s %c %d", aluno[i].nome, &aluno[i].regiao, &aluno[i].distancia);
        }
        ordenar(aluno, n);
        for(int i = 0 ; i < n; i++) {
            printf("%s\n", aluno[i].nome);
        }
    }
    return 0;
}