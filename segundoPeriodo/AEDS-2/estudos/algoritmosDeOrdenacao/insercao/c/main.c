#include <stdio.h>

void Insercao(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

int main() {
    int tam = 5;
    int array[] = {3, 13, 7, 11, 5};
    Insercao(array, tam);
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
