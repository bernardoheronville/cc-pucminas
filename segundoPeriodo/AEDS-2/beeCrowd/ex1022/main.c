#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b)
{
    a = abs(a);
    b = abs(b);

    int resto;
    while (b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

void simplificar(int *num, int *den)
{
    if (*den == 0)
    {
        return;
    }

    int divisorComum = mdc(*num, *den);

    *num = *num / divisorComum;
    *den = *den / divisorComum;

    if (*den < 0)
    {
        *den = -(*den);
        *num = -(*num);
    }
}

void resolve(int n1, int d1, int n2, int d2, char op)
{
    int num, den;
    switch (op)
    {
    case '+':
        num = n1 * d2 + n2 * d1;
        den = d1 * d2;
        break;
    case '-':
        num = n1 * d2 - n2 * d1;
        den = d1 * d2;
        break;
    case '*':
        num = n1 * n2;
        den = d1 * d2;
        break;
    case '/':
        if (n2 == 0)
        {
            printf("ERRO (divisao por zero)\n");
            return;
        }
        num = n1 * d2;
        den = n2 * d1;
        break;
    default:
        printf("Operador invalido\n");
        return;
    }

    printf("%d/%d = ", num, den);

    simplificar(&num, &den);

    printf("%d/%d\n", num, den);
}

int main()
{
    system("cls");
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int n1, d1, n2, d2;
        char op, espaco;
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        resolve(n1, d1, n2, d2, op);
    }
    return 0;
}
