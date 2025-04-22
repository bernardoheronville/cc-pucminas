#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ano_nascimento, ano_atual, idade;
    char fez_aniversario;
    scanf("%d",&ano_nascimento);
    scanf("%d",&ano_atual);
    scanf(" %c",&fez_aniversario);
    idade = ano_atual - ano_nascimento;
    if(fez_aniversario == 'N' || fez_aniversario == 'n')
    {
    idade--;
    }
    printf("%d\n",idade);
    if(idade >= 18)
    {
    printf("Pode dirigir\n");
    }
    else
    {
    printf("Nao pode dirigir\n");
    }
    return 0;
}
