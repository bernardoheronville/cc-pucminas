#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *str) {
    int count = 0;
    while(*(str + count) != '\0') {
        count++;
    }
    return count;
}

int main() {
    char *entrada = (char*)malloc(256 * sizeof(char));
    while(scanf(" %[^\n]", entrada) != EOF) {
        for(int i = 0; i < my_strlen(entrada); i++) {
            char c = *(entrada + i);
            if(c == '@') {
                *(entrada + i) = 'a';
            }
            else if(c == '&') {
                *(entrada + i) = 'e';
            }
            else if(c == '!') {
                *(entrada + i) = 'i';
            }
            else if(c == '*') {
                *(entrada + i) = 'o';
            }
            else if(c == '#') {
                *(entrada + i) = 'u';
            }
        }
        printf("%s\n", entrada);
    }
    free(entrada);
    return 0;
}