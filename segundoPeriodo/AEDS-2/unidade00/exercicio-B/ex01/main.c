#include <stdio.h>
#include <stdbool.h>

void preencherArray(int tam, int array[])
{
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &array[i]);
    }
}

bool verificaArray(int num, int tam, int array[])
{
    bool existe = false;
    for (int i = 0; i < tam; i++)
    {
        if (array[i] == num)
        {
            existe = true;
            return existe;
        }
    }
    return existe;
}

int main()
{
    int tam, num;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);
    int array[tam];
    preencherArray(tam, array);
    printf("Digite o numero que voce quer verificar se esta no array: ");
    scanf("%d", &num);
    if (verificaArray(num, tam, array))
        printf("O numero %d existe no array!\n", num);
    else
        printf("O numero %d nao existe no array!\n", num);
    return 0;
}