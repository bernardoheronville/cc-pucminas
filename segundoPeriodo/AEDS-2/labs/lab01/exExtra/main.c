#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculaMaiuscula(char *palavra, int tam) {
	int contador = 0;
	for(int i=0;i<tam;i++) {
		if(palavra[i] >= 'A' && palavra[i] <= 'Z') {
			contador++;
		}
	}
	printf("%d\n",contador);
}

int main() {
	char palavra[100];
	while(scanf(" %[^\n]", palavra) != EOF) {
		int tam = strlen(palavra);
		calculaMaiuscula(palavra,tam);		
	}
	return 0;
}
