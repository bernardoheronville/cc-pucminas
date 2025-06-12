#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int distancia = (N-3)%8;
    switch(distancia)
    {
    case 3:
        printf("1\n");
        break;
    case 4:
        printf("2\n");
        break;
    case 5:
        printf("3\n");
        break;
    default:
        printf("ERRO\n");
        break;
    }

    return 0;
}
