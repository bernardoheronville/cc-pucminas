#include <stdio.h>

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(esq + dir) / 2];
    while(i <= j) {
        while(array[i] < pivo) i++;
        while(array[j] > pivo) j--;
        if(i <= j) {
            swap(array, i, j);
            i++;
            j--;
        }
    }
    if(esq < j) quickSort(array, esq, j);
    if(i < dir) quickSort(array, i, dir);
}

int main() {
    int tam = 5;
    int array[] = {3, 13, 7, 11, 5};
    quickSort(array, 0, tam - 1);
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

