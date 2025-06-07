#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    float consumo;
    float tanque;
} Moto;

int main()
{
    Moto moto;
    srand((unsigned)time(NULL));
    int quilometros;
    quilometros = rand()%101;
    scanf("%f",&moto.consumo);
    scanf("%f",&moto.tanque);
    float distanciaTotal = moto.consumo * moto.tanque;
    if(distanciaTotal<quilometros)
    {
        int paradas= (quilometros-1)/(int)distanciaTotal;
        printf("A moto precisa parar %d vezes para abastecer\n",paradas+1);
    }
    else printf("A moto nao precisa parar para abastecer\n");
    return 0;
}
