public class Main {
    public static void insercao(int array[], int n) {
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

    public static void main(String args[]) {
        int[] array = {3, 13, 7, 11, 5};
        int tam = array.length;
        insercao(array, tam);
        for (int i = 0; i < tam; i++) {
            System.out.printf("%d ",array[i]);
        }
        System.out.printf("\n");
    }
}
