#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
    int codigo;
    char email[30];
    int horas;
    char pagina;
    float quanzas;
} Cliente;

void cadastroCliente(Cliente vet[TAM])
{
    for(int i=0; i<TAM; i++)
    {
        scanf("%d",&vet[i].codigo);
        scanf("%s",vet[i].email);
        scanf("%d",&vet[i].horas);
        scanf(" %c",&vet[i].pagina);
    }
}

void exibe(Cliente vet[TAM])
{
    for(int i=0;i<TAM;i++)
    {
        printf("Cliente %d:\n",i+1);
        printf("Codigo: %d\n",vet[i].codigo);
        printf("E-mail: %s\n",vet[i].email);
        printf("Horas de acesso: %d\n",vet[i].horas);
        printf("Possui Pagina: %c\n",vet[i].pagina);
        printf("Valor a Pagar: %.2f Quanzas\n",vet[i].quanzas);
    }
}

void calculaValor(Cliente vet[TAM])
{
    int pagina=40,base=35;
    for(int i=0; i<TAM; i++)
    {
        if(vet[i].horas <= 20)
        {
            if(vet[i].pagina == 'S') vet[i].quanzas = base + pagina;
            else vet[i].quanzas = base;
        }
        else
        {
            int horasExtras = vet[i].horas - 20;
            if(vet[i].pagina == 'S') vet[i].quanzas = base + horasExtras*2.50 + pagina;
            else vet[i].quanzas = base + horasExtras*2.50;
        }
    }
}

int main()
{
    Cliente vetor[TAM];
    cadastroCliente(vetor);
    calculaValor(vetor);
    exibe(vetor);
    return 0;
}
