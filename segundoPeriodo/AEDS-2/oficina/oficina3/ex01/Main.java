import java.util.Scanner;

class Jogador {
    private String nome;
    private int gol;
    private int soma;
    private int partidas;

    float calculaMedia() {
        return soma / (partidas/2) ;
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Jogador jogador[] = new Jogador();
        for(int i = 0; i < N; i++) {
            jogador[i].nome = sc.next();
            int count = 0;
            while(sc.hasNextInt()) {
                int gol = sc.nextInt();
                jogador[i].gol += gol;
                int assist = sc.nextInt();
                int aux =  gol + assist;
                jogador[i].soma = aux;
                count++;
            }
            jogador[i].partidas = count;
        }
    }   
}