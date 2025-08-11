#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculaMaiuscula(char *palavra, int i) {
	if(palavra[i] == '\0') return 0;
	else if(palavra[i] >= 'A' && palavra[i] <= 'Z') return (1+calculaMaiuscula(palavra,i+1));
	else return (calculaMaiuscula(palavra,i+1));
}

int main() {
	char palavra[100];
	scanf(" %[^\n]",palavra);
	while(strcmp(palavra, "FIM") != 0) {
		printf("%d\n",calculaMaiuscula(palavra,0));		
		scanf(" %[^\n]",palavra);
	}
	return 0;
}
