#include <stdio.h>
#include <stdlib.h>

int numPares(int num) {
    int resp = 0;
    while(num != 0) {
        int resto = num % 10;
        if(resto % 2 == 0) resp++;
        num /= 10;
    }
    return resp;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int sacas[n], resp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &sacas[i]);
    }
    for(int i = 0; i < k; i++) {
        int maior = -1, posicao;
        for(int j = 0; j < n; j++) {
            if(sacas[j] > maior) {
                maior = sacas[j];
                posicao = j;
            }
        }
        resp = numPares(maior);
        sacas[posicao] -= resp;  
    }
    printf("%d", resp);
    return 0;
}