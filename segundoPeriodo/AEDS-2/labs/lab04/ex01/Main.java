import java.util.Scanner;

class Bubble {

    private int array[];
    private int n;

    public Bubble(int array[], int n) {
        this.array = array;
        this.n = n;
    }

    public void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public int sort() {
        int count = 0;
        for (int i = (n - 1); i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (array[j] > array[j + 1]) {
                    swap(j, j+1);
                    count++;
                }
            }
        }
        return count;
    }

    public void mostrar() {
        System.out.println(sort());
    }
}
 
public class Main {
    public static void preencherArrays(int array1[], int array2[], int array3[], int n, Scanner sc) {
        for(int i = 0; i < n; i++) {
            array1[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++) {
            array2[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(array1[i] == array2[j]) {
                    array3[j] = i;
                    j = n;
                }
            }
        }    
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            int n = sc.nextInt();
            int array1[] = new int[n];
            int array2[] = new int[n];
            int array3[] = new int[n];
            preencherArrays(array1, array2, array3, n, sc);
            Bubble bubble = new Bubble(array3, n);
            bubble.mostrar();
        }
        sc.close();
    }
}