#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *saida=fopen("resultado.txt","w");
    int QuantidadeV;
    float aluguel,faturamento,multa,conserto;
    scanf("%d%f",&QuantidadeV,&aluguel);
    faturamento =(QuantidadeV/3.0)*aluguel*12.0;
    printf("%.2f\n",faturamento);
    fprintf(saida,"%.2f\n",faturamento);
    multa =(QuantidadeV/3.0/10)*(aluguel*0.20);
    printf("%.2f\n",multa);
    fprintf(saida,"%.2f\n",multa);
    conserto = (float) (QuantidadeV*0.02)*600;
    printf("%.2f\n",conserto);
    fprintf(saida,"%.2f\n",conserto);
    fclose(saida);
    return 0;
}
