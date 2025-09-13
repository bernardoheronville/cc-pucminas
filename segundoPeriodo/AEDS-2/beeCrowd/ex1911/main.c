#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char nome[21];
    char assinatura[21];
} AlunosV;

typedef struct {
    char nome[21];
    char assinatura[21];
} AlunosT;

int my_strlen(char *palavra) {
    int count = 0;
    while(*(palavra + count) != '\0') {
        count++;
    }
    return count;
}

bool my_strcmp(char *palavra1, char *palavra2) {
    bool resp = true;
    if(my_strlen(palavra1) == my_strlen(palavra2)) {
        for(int i = 0; i < my_strlen(palavra1); i++) {
            if(*(palavra1 + i) != *(palavra2 + i)) {
                resp = false;
                i = my_strlen(palavra1);
            }
        }
    }
    else {
        resp = false;
    }
    return resp;
}

int contarDiferencas(char *palavra1, char *palavra2) {
    int dif = 0, i = 0;
    while(palavra1[i] != '\0') {
        if(palavra1[i] != palavra2[i]) {
            dif++;
        }
        i++;
    }
    return dif;
}

int main() {
    int n;
    scanf("%d",&n);
    while(n != 0) {
        AlunosV alunosV[n];
        for(int i = 0; i < n; i++) {
            scanf("%s %s", alunosV[i].nome, alunosV[i].assinatura);
        }
        int m;
        scanf("%d",&m);
        AlunosT alunosT[m];
        for(int i = 0; i < m; i++) {
            scanf("%s %s", alunosT[i].nome, alunosT[i].assinatura);
        }
        int count = 0;
        for(int i = 0; i < m; i++) {    
            for(int j = 0; j < n; j++) {
                if(my_strcmp(alunosT[i].nome, alunosV[j].nome)) {
                    if(contarDiferencas(alunosT[i].assinatura, alunosV[j].assinatura) > 1) {
                        count++;
                    }
                    j = n;
                }
            }
        }
        printf("%d\n", count);
        scanf("%d",&n);
    }
    return 0;
}