#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//funcao para retorna true or false se a string eh um palindromo

bool palindromo(char *palavra, int inicio, int fim) {
	if(inicio >= fim) return true;
	else if(*(palavra + inicio) != *(palavra + fim)) return false;
	else return palindromo(palavra, inicio + 1, fim - 1);
}

//funcao para retornar um inteiro com o tamanho da string

int my_strlen(char *palavra) {
	int contador = 0;
	while(*(palavra + contador) != '\0') {
		contador++;
	}
	return contador;
}

//funcao para retorna valor true or false se as string sao iguais

bool my_strcmp(char *palavra1, char *palavra2) {
	int i = 0;
	while(*(palavra1 + i) != '\0' && *(palavra2 + i) != '\0') {
		if(*(palavra1 + i) != *(palavra2 + i)) return false; 
		i++;
	}
	return (*(palavra1 + i) == *(palavra2 + i));
}

// main

int main() {
	char *palavra = (char*)malloc(256*sizeof(char));
	scanf(" %[^\n]", palavra);
	while(!my_strcmp(palavra, "FIM")) {
		if(palindromo(palavra, 0, my_strlen(palavra) - 1)) {
			printf("SIM\n");
		}
		else {
			printf("NAO\n");
		}
		scanf(" %[^\n]", palavra);
	}
	free(palavra);
	return 0;
}
