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
        if ((a > b) && (a < c)) pivo = a;
        else if ((b > a) && (b < c)) pivo = b;
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

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

    }
}