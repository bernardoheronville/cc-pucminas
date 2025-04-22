#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora,minuto,horariofinal;
    printf("\nEscreva o valor da hora e minuto: ");
    scanf("%d%d",&hora,&minuto);
    horariofinal=hora*60+minuto;
    printf("Se passaram %d desde o inicio do dia",horariofinal);
    return 0;
}
