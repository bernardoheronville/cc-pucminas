#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> //Adicionado para usar o tolower

// Funcao para retornar um inteiro com o tamanho da string.
int my_strlen(char *palavra) {
    int count = 0;
    while(*(palavra + count) != '\0') {
        count++;
    }
    return count;
}

// Funcao para retorna valor true or false se as string sao iguais.
bool my_strcmp(char *palavra1, char *palavra2) {
    int tam1 = my_strlen(palavra1), tam2 = my_strlen(palavra2);
    bool resp = true;
    if(tam1 == tam2) {
        for(int i = 0; i < tam1; i++) {
            if(*(palavra1 + i) != *(palavra2 + i)) {
                resp = false;
                i = tam1;
            }
        }
    }
    else {
        resp = false;
    }
    return resp;
}

// Funcao recursiva que recebe uma string e retorna true se a mesma é composta somente por vogais.
bool isVogal(char *entrada, int i) {
    bool resp;
    char caracterAtual = tolower(*(entrada + i));
    if(i < 0) resp = true;
    else if(caracterAtual == 'a' || caracterAtual == 'e' || caracterAtual == 'i' || caracterAtual == 'o'|| caracterAtual == 'u') {
        resp = isVogal(entrada, i - 1);     
    }
    else {
        resp = false;
    }
    return resp;
}

// Funcao recursiva que recebe uma string e retorna true se a mesma é composta somente por consoantes.
bool isConsoante(char *entrada, int i) {
    bool resp;
    char caracterAtual = tolower(*(entrada + i));
    if(i < 0) resp = true;
    else if(caracterAtual >= 'a' && caracterAtual <= 'z' && caracterAtual != 'a' && caracterAtual != 'e' && caracterAtual != 'i' && caracterAtual != 'o' && caracterAtual != 'u') {
        resp = isConsoante(entrada, i - 1);       
    }
    else {
        resp = false;
    }
    return resp;
}

// Funcao recursiva que recebe uma string e retorna true se a mesma corresponde a um número inteiro.
bool isInteiro(char *entrada, int i) {
    bool resp;
    char caracterAtual = *(entrada + i);
    if (i < 0) resp = true;
    else if(caracterAtual >= '0' && caracterAtual <= '9') {
        resp = isInteiro(entrada, i - 1);
    }
    else {
        resp = false;
    }
    return resp;
}

// Funcao recursiva que recebe uma string e retorna true se a mesma corresponde a um número real.
bool isReal(char *entrada, int i, int virgulaPonto) {
    bool resp;
    char caracterAtual = *(entrada + i);
    if(i < 0) resp = true;
    else if(caracterAtual >= '0' && caracterAtual <= '9') {
        resp = isReal(entrada, i - 1, virgulaPonto);
    }
    else if((caracterAtual == ',' || caracterAtual == '.') && virgulaPonto == 0) {
        resp = isReal(entrada, i - 1, virgulaPonto + 1);
    }
    else {
        resp = false;
    }
    return resp;
}

// Procedimento que recebe uma string e chama as funcoes para retornar as respostas.
void mostrarRespostas(char *entrada) {
    int tam = my_strlen(entrada) - 1;
	if(isVogal(entrada, tam)) printf("SIM ");
	else printf("NAO ");
	if(isConsoante(entrada, tam)) printf("SIM ");
	else printf("NAO ");
	if(isInteiro(entrada, tam)) printf("SIM ");
	else printf("NAO ");
	if(isReal(entrada, tam, 0)) printf("SIM");
	else printf("NAO");
	printf("\n");
}

// Main
int main() {
    char *entrada = (char*)malloc(256*sizeof(char));
    scanf(" %[^\n]",entrada);
    while(!my_strcmp(entrada, "FIM")) {
        mostrarRespostas(entrada);
        scanf(" %[^\n]",entrada);
    }   
    free(entrada);
    return 0;
}