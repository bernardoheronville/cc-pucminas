#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *saida=fopen("saida.txt","w");
    int N,soma=0;
    char letra,contador;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf(" %c",&letra);
        fprintf(saida,"%c\n",letra);
    }
    fclose(saida);
    saida=fopen("saida.txt","r");
    while((contador=fgetc(saida)) != EOF)
    {
        if(contador=='A' || contador=='a' || contador=='E' || contador=='e' || contador=='I' || contador=='i' || contador=='O' || contador=='o' || contador=='U' || contador=='u')
        {
            soma++;
        }
    }
    printf("%d",soma);
    fclose(saida);
    return 0;
}
