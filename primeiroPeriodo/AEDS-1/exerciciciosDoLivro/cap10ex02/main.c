#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float salario;
    int idade;
    int filhos;
}habitante;

int main()
{
    habitante habitantes[5];
    for(int i=0;i<5;i++)
    {
        printf("Digite o salario do habitante %d: ",i+1);
        scanf("%f",&habitantes[i].salario);
        printf("Digite a idade do habitante %d: ",i+1);
        scanf("%d",&habitantes[i].idade);
        printf("Digite a quantidade de filhos do habitante %d: ",i+1);
        scanf("%d",&habitantes[i].filhos);
    }
    for(int i=0;i<5;i++)
    {
        printf("O habitante %d tem o salario de %.2f a idade de %d e %d filhos\n",i+1,habitantes[i].salario,habitantes[i].idade,habitantes[i].filhos);
    }
    return 0;
}
