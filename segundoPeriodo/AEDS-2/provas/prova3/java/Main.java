import java.util.Scanner;

public class Main {

    public static int hash(int alfabeto, int entrada, int pos) {
        return alfabeto + entrada + pos;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            int linhas = sc.nextInt(), soma = 0;
            for(int j = 0; j < linhas; j++) {
                String palavra = sc.next();
                for(int k = 0; k < palavra.length(); k++) {
                    soma += hash(palavra.charAt(k) - 'A', j, k);
                }
            }
            System.out.println(soma);
        }
        sc.close();
    }
}