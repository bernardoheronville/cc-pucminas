#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quicksort(int array[], int esq, int dir) {
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
    if(esq < j) quicksort(array, esq, j);
    if(i < dir) quicksort(array, i, dir);
}

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        quicksort(array, 0, n - 1);
        int soma = 0;
        for(int j = n - 1, a = 0; a != k; j--, a++) {
            soma += array[j];
        }
        printf("%d\n", soma);
    }
    return 0;
}