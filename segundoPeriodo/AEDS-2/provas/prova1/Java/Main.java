import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        char resultado;
        int total = 0;
        for(int i = 0; i < 6; i++) {
            resultado = sc.next().charAt(0);
            if(resultado == 'V') { // Vendo a quantidade de vitorias
                total++;
            }
        }
        if(total == 5 || total == 6) System.out.println("1"); // Usando esse if para ver em qual grupo ficar dependendo da quantidade de vitorias
        else if(total == 3 || total == 4) System.out.println("2");
        else if(total == 1 || total == 2) System.out.println("3");
        else System.out.println("-1");
    } 
}