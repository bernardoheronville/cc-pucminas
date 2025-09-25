import java.util.Scanner;

public class Teste {

    public static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void construir(int array[], int num, int n) {
        array[n] = num; 
        int i = n;
        while (i > 0 && array[i] < array[(i - 1) / 2]) { 
            swap(array, i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int array[] = new int[n];
        for(int i = 0; i < n; i++) {
            int num = sc.nextInt();
            construir(array, num, i);
        }

        System.out.println("Heap construído:");
        for(int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
