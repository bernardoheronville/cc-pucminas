#include <stdio.h>
#include <stdbool.h>

void preencherArray(int tam, int array[])
{
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &array[i]);
    }
}

void organizaArray(int tam, int array[]) {
        int aux;
        for (int i = 0; i < tam; i++) {
            for (int j = i + 1; j < tam; j++) {
                if (array[i] > array[j]) {
                    aux = array[i];
                    array[i] = array[j];
                    array[j] = aux;
                }
            }
        }
    }

bool verificaArray(int num, int tam, int array[])
{
    bool existe = false;
    if (num > array[tam / 2])
    {
        for (int i = array[tam / 2] + 1; i < tam; i++)
        {
            if (array[i] == num)
            {
                existe = true;
                return existe;
            }
        }
    }
    else if (num < array[tam / 2])
    {
        for (int i = array[tam / 2] + 1; i > 0; i--)
        {
            if (array[i] == num)
            {
                existe = true;
                return existe;
            }
        }
    }
    else
    {
        existe = true;
        return existe;
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
    organizaArray(tam, array);
    if (verificaArray(num, tam, array))
        printf("O numero %d existe no array!\n", num);
    else
        printf("O numero %d nao existe no array!\n", num);
    return 0;
}