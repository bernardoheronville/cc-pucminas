public class Main {
    public static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void quickSort(int array[], int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[((esq + dir) / 2)];
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

    public static void main(String args[]) {
        int[] array = {3, 13, 7, 11, 5};
        int tam = array.length;
        quickSort(array, 0, tam - 1);
        for (int i = 0; i < tam; i++) {
            System.out.printf("%d ",array[i]);
        }
        System.out.printf("\n");
    }
}
