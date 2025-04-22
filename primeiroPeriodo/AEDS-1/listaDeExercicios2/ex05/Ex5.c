#include <stdio.h>
#include <stdlib.h>

int main()
{
    int filhos,totalPessoas=0;
    float salario,mediaFilhos=0,mediaSalario=0,maiorSalario=0,salarioBaixo=0;

    scanf("%f%d", &salario, &filhos);

     while(salario>=0){

        mediaFilhos+=filhos;
        mediaSalario+=salario;
        totalPessoas++;

        if(salario>maiorSalario){
            maiorSalario = salario;
        }

        if(salario<=100){
            salarioBaixo++;
        }


        scanf("%f%d",&salario,&filhos);
    }

    printf("%0.2f\n",mediaSalario/totalPessoas);
    printf("%.0f\n",mediaFilhos/(float)totalPessoas);
    printf("%0.2f\n",maiorSalario);
    printf("%0.2f",salarioBaixo/totalPessoas*100);

    return 0;
}
