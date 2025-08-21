#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

bool palindromo(wchar_t palavra[], int inicio, int fim) {
	if(inicio >= fim) return true;
	else if(palavra[inicio] != palavra[fim]) return false;
	else return palindromo(palavra, inicio + 1, fim - 1);
}

int my_strlen(wchar_t palavra[]) {
	int contador = 0;
	while(palavra[contador] != L'\0') {
		contador++;
	}
	return contador;
}

int main() {
	setlocale(LC_ALL, ""); //habilita UTF-8 no sistema
	wchar_t palavra[255];
	wscanf(L"%ls", palavra);
	while(wcscmp(palavra, L"FIM")) {
		if(palindromo(palavra, 0, my_strlen(palavra) - 1)) {
			printf("SIM\n");
		}
		else {
			printf("NAO\n");
		}
		swscanf(L"%ls", palavra);
	}
	return 0;
}
