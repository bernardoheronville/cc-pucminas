#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str) {
    int count = 0;
    while(*(str + count) != '\0') {
        count++;
    }
    return count;
}

int main() {
    char letras[100], frase[100];
    int count = 0;
    while(scanf("%s", letras) != EOF) {
        scanf(" %[^\n]", frase);
        count = 0;
        for(int i = 0; i < my_strlen(frase); i++) {
            for(int j = 0; j < my_strlen(letras); j++) {
                if(frase[i] == letras[j]) {
                    count++;
                    j = my_strlen(letras);
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}