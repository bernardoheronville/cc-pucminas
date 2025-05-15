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
        char texto[100];
        while(fscanf(entrada," %[^\n]",texto) == 1)
        {
            int i=0;
            while(texto[i] != '\0')
            {
                fprintf(saida,"%c",texto[i]);
                i++;
            }
            fprintf(saida, "\n");
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
