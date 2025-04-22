#include <stdio.h>

void converteHora(int totalsegundos, int *hora, int *min, int *seg)
{
    *hora = totalsegundos / 3600;
    *min = (totalsegundos % 3600) / 60;
    *seg = totalsegundos % 60;
}

int main()
{
    int totalsegundos;
    int hora, min, seg;
    scanf("%d", &totalsegundos);
    converteHora(totalsegundos,&hora,&min,&seg);
    printf("%d:%d:%d\n",hora,min,seg);
    return 0;
}
