import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        while(n != 0 && d != 0) {
            String entrada = sc.next();
            char array[] = new char[n];
            for(int i = 0; i < n; i++) {
                array[i] = entrada.charAt(i);
                System.out.print(array[i]);
            }
            System.out.println();
            d = sc.nextInt();
            n = sc.nextInt();
        }
    }
}
