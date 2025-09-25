import java.util.*;

public class Main {

    public static void QuickSortFirstPivot(int array[], int left, int right) {
        int i = left, j = right;
        int pivo = array[left];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if(left < j) QuickSortFirstPivot(array, left, j);
        if(i < right) QuickSortFirstPivot(array, i, right);
    }

    public static void QuickSortLastPivot(int array[], int left, int right) {
        int i = left, j = right;
        int pivo = array[right];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if(left < j) QuickSortLastPivot(array, left, j);
        if(i < right) QuickSortLastPivot(array, i, right);
    }

    public static void QuickSortRandomPivot(int array[], int left, int right) {
        int i = left, j = right;
        Random gerador = new Random();
        int pivoIndex = left + gerador.nextInt(right - left + 1);
        int pivo = array[pivoIndex];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if(left < j) QuickSortRandomPivot(array, left, j);
        if(i < right) QuickSortRandomPivot(array, i, right);
    }

    public static void QuickSortMedianOfThree(int array[], int left, int right) {
        int i = left, j = right;
        int a = array[left], b = array[(left + right) / 2], c = array[right];
        int pivo;
        if (a > b && a < c) pivo = a;
        else if (b > a && b < c) pivo = b;
        else pivo = c;
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if(left < j) QuickSortMedianOfThree(array, left, j);
        if(i < right) QuickSortMedianOfThree(array, i, right);
    }

    public static long now() {
        return System.nanoTime();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = 100;
        //int array[] = new int[100];
        //int array[] = new int[1000];
        int array[] = new int[10000];
        for(int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        long inicio = now();
        //System.out.println("inicio " + inicio);
        QuickSortFirstPivot(array, 0, n - 1);
        //QuickSortLastPivot(array, 0, n - 1);
        //QuickSortRandomPivot(array, 0, n - 1);
        //QuickSortMedianOfThree(array, 0, n - 1);
        long fim = now();
        System.out.println("Numeros ordenados: ");

        for(int i = 0; i < n; i++) {
            System.out.printf("%d ",array[i]);
        }

        System.out.println("Tempo para ordenar: " + (fim-inicio) + " ns.");

        System.out.printf("\n");
    }
}