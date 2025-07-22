import java.util.Scanner;

public class Ex03 {
    public static void main(String[] args) {
        int numMax = Integer.MIN_VALUE, numMin = Integer.MAX_VALUE;
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o tamanho do array!");
        int tam = sc.nextInt();
        System.out.println("Digite os " + tam + " elementos: ");
        int array[] = new int[tam];
        for (int i = 0; i < tam; i++) {
            array[i] = sc.nextInt();
        }
        for (int i = 0; i < tam; i++) {
            if (array[i] > numMax)
                numMax = array[i];
            if (array[i] < numMin)
                numMin = array[i];
        }
        System.out.println("O maior elemento do array eh " + numMax);
        System.out.println("O menor elemento do array eh " + numMin);
        sc.close();
    }
}