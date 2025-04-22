#include <stdio.h>
#include <stdlib.h>

void calculaMedia()
{
    int N;
    float nota1,nota2,nota3,mediafinal;
    char opcao;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%f%f%f %c",&nota1,&nota2,&nota3,&opcao);
        if(opcao=='A' || opcao=='a')
        {
            mediafinal = (float)(nota1+nota2+nota3)/3;
            printf("%.2f\n",mediafinal);
        }
        else if(opcao=='P' || opcao=='p')
        {
            mediafinal = (float)((nota1*5)+(nota2*3)+(nota3*2))/10;
            printf("%.2f\n",mediafinal);
        }
        else
        {
            printf("Digite uma opcao valida\n");
        }
    }
}
int main()
{
    calculaMedia();
    return 0;
}
