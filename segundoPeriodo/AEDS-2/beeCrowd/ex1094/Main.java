import java.util.Scanner;

class Animais {
    public int quantidade;
    public char tipo;

    Animais(int quantidade, char tipo) {
        this.quantidade = quantidade;
        this.tipo = tipo;
    }
    public void mostrar() {
        System.out.println(quantidade + " " + tipo);
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Animais animais[] = new Animais[n];
        for(int i = 0 ; i < n; i++) {
            int quantidade = sc.nextInt();
            char tipo = sc.next().charAt(0);
            animais[i] = new Animais(quantidade, tipo);
        }
        int total = 0, totalCoelho = 0, totalRatos = 0, totalSapos = 0;
        for(int i = 0 ; i < n; i++) {
            switch(animais[i].tipo) {
                case 'C':
                    total += animais[i].quantidade;
                    totalCoelho += animais[i].quantidade;
                    break;
                case 'R':
                    total += animais[i].quantidade;
                    totalRatos += animais[i].quantidade;
                    break;
                case 'S':
                    total += animais[i].quantidade;
                    totalSapos += animais[i].quantidade;
                    break;
                default:
                    System.out.println("ERRO");
            }
        }
        System.out.println("Total: " + total + " cobaias");
        System.out.println("Total de coelhos: " + totalCoelho);
        System.out.println("Total de ratos: " + totalRatos);
        System.out.println("Total de sapos: " + totalSapos);
        System.out.printf("Percentual de coelhos: %.2f %%\n", ((float) totalCoelho / total) * 100);
        System.out.printf("Percentual de ratos: %.2f %%\n", ((float) totalRatos / total) * 100);
        System.out.printf("Percentual de sapos: %.2f %%\n", ((float) totalSapos / total) * 100);
        sc.close();
    }
}