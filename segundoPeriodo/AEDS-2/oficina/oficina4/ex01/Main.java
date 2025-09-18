import java.util.Scanner;

public class Main {

    public static void quickSort(int array[], int esq, int dir) {
        int i = esq, j = dir, meio = array[(esq + dir) / 2];
        while(i <= j) {
            while(array[i] < meio) i++;
            while(array[j] > meio) j--;
            if(i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if(esq < j) quickSort(array, esq , j);
        if(i < dir) quickSort(array, i, dir); 
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int array[] = new int[n];
        for(int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        quickSort(array, 0, n - 1);
        for(int i = 0; i < n; i++) {
            System.out.printf("%d ", array[i]);
        }
        System.out.printf("\n");
        sc.close();
    }
}