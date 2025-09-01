#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Funcao recursiva que recebe um número inteiro como parâmetro e retorna a soma de seus dígitos.
int soma(char *entrada, int i) {
    int resp = 0, digito = *(entrada + i) - 48;
    if (*(entrada + i) == '\0') resp = 0;
    else resp = digito + soma(entrada, i + 1); 
    return resp;
}

// Funcao auxiliar para a soma.
int somaAux(char *entrada) {
    return soma(entrada,0);
}

// Main
int main () {
    char *entrada = (char*)malloc(256*sizeof(char));
    scanf(" %[^\n]",entrada);
    while(!my_strcmp(entrada, "FIM")) {
        printf("%d\n",somaAux(entrada));
        scanf(" %[^\n]",entrada);
    }
    free(entrada);
    return 0;
}