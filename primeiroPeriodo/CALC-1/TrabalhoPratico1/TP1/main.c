#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void equacaoReta(float Ax, float Ay, float Bx, float By)
{
    float b, m;
    if (Ax == Bx)
    {
        printf("A reta eh vertical: x = %.2f\n", Ax);
    }
    else
    {
        m = (By - Ay) / (Bx - Ax);
        b = Ay - m * Ax;
        printf("Equacao da reta: y = %.2fx + %.2f\n", m, b);
    }
}

void fazendoTabela(float x0, float y0,float num1[], float num2[])
{
    float x, fx, m;

    printf("\nTabela de derivadas aproximadas (reta secante para f(x) = x^2 no ponto x = %.2f):\n", x0);
    printf("x\tf(x)\t\coef. angular\n");

    for (int i = 1; i <= 5; i++)
    {
        x = x0 + i * 0.1;
        fx = pow(x, 2);
        m = (fx - y0) / (x - x0);
        printf("%.2f\t%.2f\t%.2f\n", x, fx, m);
        num1[i-1] = x;
        num2[i-1] = fx;
    }
}

void analisarDerivada(float x0, float y0, char tipoFuncao)
{
    float x_vals[] = {x0 + 0.1, x0 + 0.2, x0 + 0.3, x0 + 0.4, x0 + 0.5};
    int num_pontos = 5;
    float fx, m, m_tangente;
    char nomeFuncao[10];

    if (tipoFuncao == '3')
    {
        strcpy(nomeFuncao, "x^3");
        m_tangente = 3.0;
    }
    else if (tipoFuncao == 's')
    {
        strcpy(nomeFuncao, "sqrt(x)");
        m_tangente = 0.5;
    }
    else
    {
        printf("Tipo de funcao desconhecido.\n");
        return;
    }

    printf("\n--- Analise da Derivada para f(x) = %s no ponto (%.f, %.f) ---\n", nomeFuncao, x0, y0);
    printf("x\t\tf(x)\t\tCoef. Angular (ms)\n");

    for (int i = 0; i < num_pontos; i++)
    {
        float x_atual = x_vals[i];


        if (tipoFuncao == '3')
        {
            fx = pow(x_atual, 3);
        }
        else
        {
            fx = sqrt(x_atual);
        }

        m = (fx - y0) / (x_atual - x0);
        printf("%.3f\t\t%.4f\t\t%.4f\n", x_atual, fx, m);
    }

    printf("\nConclusao: A medida que x se aproxima de %.f, o coeficiente angular se aproxima de %.2f.\n", x0, m_tangente);
    printf("A derivada de f(x) = %s no ponto x=%.f eh: %.2f\n", nomeFuncao, x0, m_tangente);
}

int main()
{
    float Ax, Ay, Bx, By, num1[5],num2[5];

    printf("Escreva o ponto A (x y): ");
    scanf("%f%f", &Ax, &Ay);
    printf("Escreva o ponto B (x y): ");
    scanf("%f%f", &Bx, &By);

    equacaoReta(Ax, Ay, Bx, By);

    float secanteX,secanteY;
    printf("\nDigite o ponto x e y para a tabela de reta secante de f(x) = x^2: ");
    scanf("%f%f", &secanteX, &secanteY);

    fazendoTabela(secanteX,secanteY,num1,num2);

    printf("\n--- Equacoes das retas secantes entre (%.2f, %.2f) ---\n", secanteX, secanteY);

    for(int i=0; i<5; i++)
    {
        equacaoReta(secanteX,secanteY,num1[i],num2[i]);
    }

    printf("\n--- Derivada para as funcoes x^3 e raiz de x no ponto x=1 ---\n");

    analisarDerivada(1.0, 1.0, '3');
    analisarDerivada(1.0, 1.0, 's');

    return 0;
}
