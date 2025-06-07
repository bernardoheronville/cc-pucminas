#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int X;
    int Y;
} Ponto;

void calculaAlinhamento(Ponto num1, Ponto num2)
{
    if(num1.X == num2.X && num1.Y == num2.Y) printf("Pontos identicos\n");
    else if (num1.X == num2.X) printf("Alinhamento vertical\n");
    else if (num1.Y == num2.Y) printf("Alinhamento horizontal\n");
    else printf("Nao ha alinhamentos\n");
}

int main()
{
    int N;
    scanf("%d",&N);
    Ponto A,B,C;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&A.X,&A.Y);
        scanf("%d%d",&B.X,&B.Y);
        scanf("%d%d",&C.X,&C.Y);
        calculaAlinhamento(A,B);
        calculaAlinhamento(A,C);
        calculaAlinhamento(B,C);
    }
    return 0;
}
