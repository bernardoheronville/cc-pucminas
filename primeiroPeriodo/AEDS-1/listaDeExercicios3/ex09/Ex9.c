#include <stdio.h>
#include <stdlib.h>

float calculaMedia(int alunos)
{
    int q1=0;
    float media,nota,notatotal=0;
    for(int i=1; i<=alunos; i++)
    {
        scanf("%f",&nota);
        if(nota>=6)
        {
            notatotal+=nota;
            q1++;
        }
    }
    media = (float)notatotal/q1;
    return (media);
}

int main()
{
    int alunos;
    scanf("%d",&alunos);
    printf("%.1f",calculaMedia(alunos));
    return 0;
}
