#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Importando biblioteca bool

// Funcao para retornar um inteiro com o tamanho da string

int my_strlen(char *palavra) {
	int contador = 0;
	while(*(palavra + contador) != '\0') {
		contador++;
	}
	return contador;
}

// Funcao para retorna valor true or false se as string sao iguais

bool my_strcmp(char *palavra1, char *palavra2) {
	int i = 0;
	while(*(palavra1 + i) != '\0' && *(palavra2 + i) != '\0') {
		if(*(palavra1 + i) != *(palavra2 + i)) return false; 
		i++;
	}
	return (*(palavra1 + i) == *(palavra2 + i));
}

// Funcao para retorna true or false se a string eh um palindromo

bool palindromo(char *palavra, int inicio, int fim) {
	bool resp;
	if(inicio >= fim) resp = true;
	else if(*(palavra + inicio) != *(palavra + fim)) resp = false;
	else resp = palindromo(palavra, inicio + 1, fim - 1);
	return resp;
}

// Funcao auxiliar do palindromo

bool palindromoAux(char *palavra) {
	return palindromo(palavra, 0, my_strlen(palavra) - 1);
}

// Main

int main() {
	char *palavra = (char*)malloc(256*sizeof(char));
	scanf(" %[^\n]", palavra);
	while(!my_strcmp(palavra, "FIM")) {
		if(palindromoAux(palavra)) {
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
