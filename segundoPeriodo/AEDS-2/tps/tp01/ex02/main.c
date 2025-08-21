#include <stdio.h>
#include <stdbool.h>

bool palindromo(char palavra[], int inicio, int fim) {
	if(inicio >= fim) return true;
	else if(palavra[inicio] != palavra[fim]) return false;
	else return palindromo(palavra, inicio + 1, fim - 1);
}

int my_strlen(char palavra[]) {
	int contador = 0;
	while(palavra[contador] != '\0') {
		contador++;
	}
	return contador;
}

bool my_strcmp(char palavra[]) {
	if(palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M' && palavra[3] == '\0') return false;
	else return true;
}

int main() {
	char palavra[255];
	scanf("%s",palavra);
	while(my_strcmp(palavra)) {
		if(palindromo(palavra, 0, my_strlen(palavra) - 1)) {
			printf("SIM\n");
		}
		else {
			printf("NAO\n");
		}
		scanf("%s",palavra);
	}
	return 0;
}
