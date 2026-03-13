import java.util.*;

public class Main {
    public static void swap(char array[], int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void quickSort(char array[], int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[(esq + dir) / 2];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <=j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(esq < j) quickSort(array, esq, j); 
        if(i < dir) quickSort(array, i, dir);
    }

    public static char[] ex(char array[], int n, int d) {
        char nums[] = new char[d];
        for(int i = 0; i < d; i++) {
            nums[i] = array[i];
        }
        return nums;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        while(n != 0 && d != 0) {
            String entrada = sc.next();
            char array[] = new char[n];
            for(int i = 0; i < n; i++) {
                array[i] = entrada.charAt(i);
            }
            quickSort(array, 0, n - 1);   
            char nums[] = ex(array, n, d);
            boolean usadoStr[] = new boolean[n];
            boolean usadoNums[] = new boolean[d];
            for(int i = 0; i < entrada.length(); i++) {
                for(int j = 0; j < d; j++) {
                    if(nums[j] == entrada.charAt(i) && !usadoNums[j]) {
                        usadoStr[i] = true;
                        usadoNums[j] = true;
                        j = d;
                    }
                }
                if(!usadoStr[i]) System.out.print(entrada.charAt(i));
            }
            System.out.println();
            n = sc.nextInt();
            d = sc.nextInt();
        }
        sc.close();
    }
}
