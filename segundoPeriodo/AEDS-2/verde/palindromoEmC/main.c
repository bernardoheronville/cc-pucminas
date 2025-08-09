#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char *palavra)
{
	int inicio = 0;
	int final = strlen(palavra) - 1;
	while (inicio < final)
	{
		if (palavra[inicio] != palavra[final])
		{
			return false;
		}
		inicio++;
		final--;
	}
	return true;
}

int main()
{
	char palavra[100];
	scanf("%s", palavra);
	while (strcmp(palavra, "FIM") != 0)
	{
		if (palindromo(palavra))
			printf("SIM\n");
		else
			printf("NAO\n");
		scanf("%s", palavra);
	}
	return 0;
}