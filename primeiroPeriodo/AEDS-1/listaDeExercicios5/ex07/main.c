#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *saida=fopen("saida.txt","w");
    int N,soma=0;
    char letra,contador[100];
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
    {
        scanf(" %c",&letra);
        fprintf(saida,"%c\n",letra);
    }
    fclose(saida);
    saida=fopen("saida.txt","r");
    while(fscanf(saida," %[^\n]",contador) == 1)
    {
        int i=0;
        while(contador[i] != '\0')
        {
            char teste = tolower(contador[i]);
            if(teste=='a' || teste=='e' || teste=='i' || teste=='o' || teste=='u')
            {
                soma++;
            }
            i++;
        }

    }
    printf("%d",soma);
    fclose(saida);
    return 0;
}
