#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char doacao;
    char obra[20];
    char autor[20];
    char editora[20];
    int area;
} Livro;

int main()
{
    Livro exatas[500], humanas[500], biologicas[500];
    int codiguin, i = 0;

    while (1)
    {
        scanf("%d", &codiguin);
        if (codiguin == -1) break;

        Livro *livro;
        if (codiguin == 1)
        {
            livro = &exatas[i];
        }
        else if (codiguin == 2)
        {
            livro = &humanas[i];
        }
        else
        {
            livro = &biologicas[i];
        }

        livro->area = codiguin;
        scanf("%d", &livro->codigo);
        scanf(" %c", &livro->doacao);
        scanf("%s", livro->obra);
        scanf("%s", livro->autor);
        scanf("%s", livro->editora);

        i++;
    }

    while (1)
    {
        scanf("%d", &codiguin);
        if (codiguin == -1) break;

        Livro *livro;
        if (codiguin == 1)
        {
            livro = &exatas[i];
        }
        else if (codiguin == 2)
        {
            livro = &humanas[i];
        }
        else
        {
            livro = &biologicas[i];
        }
    }

    return 0;
}
