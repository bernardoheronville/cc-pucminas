import java.util.Scanner;

class Pokemon {
    private String nomes[];
    private int n;

    Pokemon(int tam) {
        this.nomes = new String[tam];
        this.n = 0;
    }
    public void inserir(String nome) {
        boolean inserir = true;
        for(int i = 0; i < n; i++) {
            if(nome.equals(nomes[i])) {
                inserir = false;
            }
        }
        if(inserir) {
            this.nomes[n] = nome;
            n++;
        }
    }
    public int result() {
        return 151 - n;
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), total = 151;
        Pokemon pokemon = new Pokemon(n);
        for(int i = 0; i < n; i++) {
            String nome = sc.next();
            pokemon.inserir(nome);
        }
        System.out.println("Falta(m) " + pokemon.result() + " pomekon(s).");
        sc.close();
    }
}