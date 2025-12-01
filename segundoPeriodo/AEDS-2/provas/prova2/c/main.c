#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;
    while(scanf("%d %d", &l, &c) == 2) {
        int matriz[l][c];
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < c; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < c; j++) {
                if(matriz[i][j] != 0) {
                    printf("9");
                }
                else {
                    int count = 0;
                    if(i > 0) {
                        count += matriz[i - 1][j];
                    }
                    if(j < c - 1) {
                        count += matriz[i][j + 1];
                    }
                    if(i < l - 1) {
                        count += matriz[i + 1][j];
                    }
                    if(j > 0) {
                        count += matriz[i][j - 1];
                    }
                    printf("%d", count);
                }
            }
            printf("\n");
        }
       
    }
    return 0;
}