#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    scanf("%d",&idade);
    if(idade<5)
    {
    printf("Sem categoria");
    }
    else if(idade>=5&&idade<=7)
    {
    printf("Infantil");
    }
    else if(idade>=8&&idade<=10)
    {
    printf("Juvenil");
    }
    else if(idade>=11&&idade<=15)
    {
    printf("Adolescente");
    }
    else if(idade>=16&&idade<=30)
    {
    printf("Adulto");
    }
    else
    {
     printf("Senior");
    }
    return 0;
}
