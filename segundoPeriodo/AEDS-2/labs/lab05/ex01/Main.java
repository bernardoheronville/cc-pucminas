import java.util.*;

public class Main {

    public static void QuickSortFirstPivot(int array[], int left, int right) {
        int i = left, j = right;
        int pivo = array[left];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                swap(array, i, j);
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
                swap(array, i, j);
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
                swap(array, i, j);
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
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(left < j) QuickSortMedianOfThree(array, left, j);
        if(i < right) QuickSortMedianOfThree(array, i, right);
    }

    public static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void ordenado(int array[], int n) {
		for (int i = 0; i < n; i++) {
			array[i] = i;
		}
	}

    public static void random(int array[], int n) {
		Random rand = new Random();
		ordenado(array, n);	
		for (int i = 0; i < n; i++) {
			swap(array, i, Math.abs(rand.nextInt()) % n);
		}
	}

    public static void meioOrdenado(int array[], int n) {
		Random rand = new Random();
		ordenado(array, n);	
		for (int i = 0; i < n / 2; i++) {
			swap(array, i, Math.abs(rand.nextInt()) % n);
		}
	}

    public static long now() {
        return System.nanoTime();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = 100;
        int array[] = new int[n];

        //ordenado(array, n);
        meioOrdenado(array, n);
        //random(array, n);
        
        long inicio = now();
        //QuickSortFirstPivot(array, 0, n - 1);
        //QuickSortLastPivot(array, 0, n - 1);
        //QuickSortRandomPivot(array, 0, n - 1);
        QuickSortMedianOfThree(array, 0, n - 1);
        long fim = now();

        System.out.println("Tempo para ordenar: " + (fim - inicio) / 1_000_000.0 + " ms.");
    }
}