import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String entrada;
        for(int i = 0; i < n; i++) {
            entrada = sc.nextLine();
            int count = 0, aberto = 0;
            for(int j = 0; j < entrada.length(); j++) {
                char c = entrada.charAt(j);
                if(c == '<') aberto++;
                else if(c == '>' && aberto > 0) {
                    count++;
                    aberto--;
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}