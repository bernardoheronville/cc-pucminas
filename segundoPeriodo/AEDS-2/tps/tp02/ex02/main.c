#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> // Adicionando biblioteca para usar o toupper

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

// Funcao que recebe uma string e retorna true se a mesma é composta somente por vogais.
bool isVogal(char *palavra) {
	bool resp = true;
	int tam = my_strlen(palavra);
	for(int i = 0; i < tam; i++) {
		char letra = toupper(*(palavra + i));
		if(!(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')) {
			resp = false;
			i = tam;
		}
	}
	return resp;
}

// Funcao que recebe uma string e retorna true se a mesma é composta somente por consoantes.
bool isConsoante(char *palavra) {
	bool resp = true;
	int tam = my_strlen(palavra);
	for(int i = 0; i < tam; i++) {
		char letra = toupper(*(palavra + i));
		if((letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')) {
				resp = false;
				i = tam;
		}
		if(!(letra >= 'A' && letra <= 'Z')) {
			resp = false;
			i = tam;
		}
	}
	return resp;
}

// Funcao que recebe uma string e retorna true se a mesma corresponde a um número inteiro.
bool isInteiro(char *palavra) {
	bool resp = true;
	int tam = my_strlen(palavra);
	for(int i = 0; i < tam; i++) {
		char letra = *(palavra + i);
		if(letra < '0' || letra > '9') {
			resp = false;
			i = tam;
		}
	}
	return resp;
}

// Funcao que recebe uma string e retorna true se a mesma corresponde a um número real.
bool isReal(char *palavra) {
	bool resp = true;
	int tam = my_strlen(palavra), virgulaPonto = 0;
	for(int i = 0; i < tam; i++) {
		char letra = *(palavra + i);
		if(letra == ',' || letra == '.') {
			virgulaPonto++;
		}
		else if(letra < '0' || letra > '9') {
			resp = false;
			i = tam;
		}
	}
	if(virgulaPonto != 0 && virgulaPonto != 1) resp = false;
	return resp;
}

// Procedimento que recebe uma string e chama as funcoes para retornar as respostas.
void mostrarRespostas(char *palavra) {
	if(isVogal(palavra)) printf("SIM ");
	else printf("NAO ");
	if(isConsoante(palavra)) printf("SIM ");
	else printf("NAO ");
	if(isInteiro(palavra)) printf("SIM ");
	else printf("NAO ");
	if(isReal(palavra)) printf("SIM");
	else printf("NAO");
	printf("\n");
}

// Main
int main() {
	char *palavra = (char*)malloc(256*sizeof(char));
	scanf(" %[^\n]",palavra);
	while(!my_strcmp(palavra, "FIM")) {
		mostrarRespostas(palavra);
		scanf(" %[^\n]",palavra);
	}
	free(palavra);
	return 0;
}
