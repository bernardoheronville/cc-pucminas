#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAIPES 13

void verificarCartas(char cartas[], int sup, int contadores[4][NAIPES])
{
    int naipeConta = -1;
    char carta[3] = {cartas[sup],cartas[sup+1],'\0'};
    char naipe = cartas[sup+2];
    int valor = atoi(carta);
    switch(naipe)
    {
    case 'C':
        naipeConta = 0;
        break;
    case 'E':
        naipeConta = 1;
        break;
    case 'U':
        naipeConta = 2;
        break;
    case 'P':
        naipeConta = 3;
        break;
    }
    contadores[naipeConta][valor - 1]++;
}

void verificarNaipe(int contagem[NAIPES])
{
    int cartas_faltando = 0;
    int erro = 0;
    for (int i = 0; i < NAIPES; i++)
    {
        if (contagem[i] == 0)
        {
            cartas_faltando++;
        }
        else if (contagem[i] > 1)
        {
            erro = 1;
        }
    }
    if (erro)
    {
        printf("erro\n");
    }
    else if (cartas_faltando > 0)
    {
        printf("%d\n", cartas_faltando);
    }
    else
    {
        printf("0\n");
    }
}

int main()
{
    int contadores[4][13] = {0};
    char cartas[157];
    scanf("%s",cartas);
    int tam = strlen(cartas);
    for(int i = 0; i < tam ; i += 3)
    {
        verificarCartas(cartas,i,contadores);
    }
    for(int i=0; i < 4; i++)
    {
        verificarNaipe(contadores[i]);
    }

    return 0;
}
