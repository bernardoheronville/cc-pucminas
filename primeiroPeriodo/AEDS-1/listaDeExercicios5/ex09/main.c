#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    scanf("%d",&opcao);
    getchar();
    if(opcao==1)
    {
        FILE *saida=fopen("saida.txt","w");
        int matricula,telefone;
        char parar='s';
        while(parar!='n')
        {
            scanf("%d%d",&matricula,&telefone);
            fprintf(saida,"%d %d\n",matricula,telefone);
            printf("Deseja continuar? (s ou n): ");
            scanf(" %c",&parar);
        }
        fclose(saida);
    }
    else if(opcao==2)
    {
        FILE *entrada=fopen("entrada.txt","r");
        FILE *saida=fopen("saida.txt","w");
        char texto;
        while((texto=fgetc(entrada)) != EOF)
        {
            fprintf(saida,"%c",texto);
        }
        fclose(entrada);
        fclose(saida);
    }
    else
    {
        printf("Opcao invalida digite 1 ou 2\n");
    }
    return 0;
}
