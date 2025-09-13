import java.util.Scanner;

class Palavra {
    private String nome;
    private int preco;

    Palavra() {
        this.nome = "nenhum";
        this.preco = 0;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setPreco(int preco) {
        this.preco = preco;
    }
    public String getNome() {
        return nome;
    }
    public int getPreco() {
        return preco;
    }

    public void mostrar() {
        System.out.println(nome + " " + preco);
    }
}

public class Main {
    public static boolean my_strcmp(String palavra1, String palavra2) {
        boolean resp = true;
        if(palavra1.length() == palavra2.length()) {
            for(int i = 0; i < palavra1.length(); i++) {
                if(palavra1.charAt(i) != palavra2.charAt(i)) {
                    resp = false;
                    i = palavra1.length();
                }
            }
        }
        else {
            resp = false;
        }
        return resp;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        Palavra palavra[] = new Palavra[m];
        for(int i = 0; i < m; i++) {
            palavra[i] = new Palavra();
            String nome = sc.next();
            palavra[i].setNome(nome);
            int preco = sc.nextInt();
            palavra[i].setPreco(preco);
        }
        for(int i = 0; i < n; i++) {
            int soma = 0;
            String word = sc.next();
            while(!my_strcmp(word, ".")) {
                for(int j = 0; j < m; j++) {
                    if(my_strcmp(word, palavra[j].getNome())) {
                        soma += palavra[j].getPreco();
                    }
                }
                word = sc.next();
            }
            System.out.println(soma);
        }
    }
}