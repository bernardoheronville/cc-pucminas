#include <stdio.h>
#include <string.h>

void combinador(char *str1, char *str2, char *str3, int tam1, int tam2, int tam3) {
	for (int i = 0, j = 0, k = 0; i < tam3; i++) {
		if (j < tam1 && k < tam2) {
			if (i % 2 == 0) { 
				str3[i] = str1[j];
				j++;
			}
			else if (i % 2 != 0) {
				str3[i] = str2[k];
				k++;
			}
		}
		else if(j < tam1) {
			str3[i] = str1[j];
			j++;
		}
		else {
			str3[i] = str2[k];
			k++;
		}
	}
}

int main() {
	char str1[255], str2[255];
	while(scanf("%s %s", str1, str2) != EOF) {
		int tam1 = strlen(str1), tam2 = strlen(str2), tam3 = tam1 + tam2 + 1;
		char str3[tam3];
		combinador(str1, str2, str3, tam1, tam2, tam3);
		printf("%s\n",str3);
	}
	return 0;
}
