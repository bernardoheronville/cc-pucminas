#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *entrada = (char*)malloc(256*sizeof(char));
    scanf("%s", entrada);
    bool resp = true;
    if(strlen(entrada) == 8) {
        for(int i = 0; i < 3; i++) {
            if(!(*(entrada + i) >= 'A' && *(entrada + i) <= 'Z')) { // Vendo se os primeiros 3 caracteres sao letras maisculas.
                resp = false;
            }
        }
        if(*(entrada + 3) != '-') resp = false; // Vendo se o 4 caracter é um hifen.
        for(int i = 4; i < 8; i++) {
            if(!(*(entrada + i) >= '0' && *(entrada + i) <= '9')) { // Vendo se os 4 ultimos caracteres sao digitos.
                resp = false;
            }
        }
        if(resp) {
            printf("1\n");
        }
        else {
            printf("0\n");
        } 
    }
    else if(strlen(entrada) == 7) {
        for(int i = 0; i < 3; i++) {
            if(!(*(entrada + i) >= 'A' && *(entrada + i) <= 'Z')) { // Vendo se os primeiros 3 caracteres sao letras maisculas.
                resp = false;
            }
        }
        if(!(*(entrada + 3) >= '0' && *(entrada + 3) <= '9')) resp = false; // Vendo se o 4 caracter é um digito.
        if(!(*(entrada + 4) >= 'A' && *(entrada + 4) <= 'Z')) resp = false; // Vendo se o 5 caracter é um letra maiscula.
        for(int i = 5; i < 7; i++) {
            if(!(*(entrada + i) >= '0' && *(entrada + i) <= '9')) { // Vendo se os 2 ultimos caracteres sao digitos.
                resp = false;
            }
        }
        if(resp) {
            printf("2\n");
        }
        else {
            printf("0\n");
        } 
    }
    else {
        printf("0\n");
    }
    return 0;
}