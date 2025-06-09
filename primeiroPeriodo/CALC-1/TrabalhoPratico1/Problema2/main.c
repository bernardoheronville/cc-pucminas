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

    printf("\n--- Equacoes das retas secantes entre (%.2f, %.2f)---\n", secanteX, secanteY);

    for(int i=0;i<5;i++)
    {
        equacaoReta(secanteX,secanteY,num1[i],num2[i]);
    }

    return 0;
}
