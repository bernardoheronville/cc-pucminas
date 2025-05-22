#include <stdio.h>
#include <stdlib.h>

void preencherNotas()
{
    float notas[10];
    for(int i = 0; i < 10; i++)
    {
        scanf("%f",&notas[i]);
    }
    calculaMedia(notas,10);
}

void calculaMedia(float notas[], int tamanho)
{
    int acima=0;
    float media,total = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(notas[i] >= 6) acima++;
        total += notas[i];
    }
    media = (float)total / tamanho;
    printf("Media: %.2f\n", media);
    printf("Alunos acima da media: %d\n",acima);
}

int main()
{
    preencherNotas();
    return 0;
}
