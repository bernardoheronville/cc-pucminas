#include <stdio.h>
#include <limits.h>

int main()
{
    int tam, numMax = INT_MIN, numMin = INT_MAX;
    printf("Digite o tamanho do array!\n");
    scanf("%d", &tam);
    int array[tam];
    printf("Digite os %d elementos do array: \n", tam);
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        if (array[i] > numMax)
            numMax = array[i];
        if (array[i] < numMin)
            numMin = array[i];
    }
    printf("O maior elemento do array eh %d\n", numMax);
    printf("O menor elemento do array eh %d\n", numMin);
    return 0;
}