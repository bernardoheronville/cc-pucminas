class No {
    char elemento;
    int tam = 255;
    No prox[];
    boolean folha;

    public No(char x) {
        elemento = x;
        prox = new No[tam];
        for(int i = 0; i < tam; i++) prox[i] = null;
        folha = false;
    }
}

class Arvore {
    No raiz;

    public Arvore() {
        raiz = new No(' ');
    }

    public void inserir(String s) {
        inserir(s, raiz, 0);
    }
    private void inserir(String s, No no, int i) {
        char c = s.charAt(i);
        int index = (int)c; 
        if(no.prox[index] == null) no.prox[index] = new No(c);
        if(i == s.length() - 1) no.prox[index].folha = true;
        else inserir(s, no.prox[index], i + 1);
    }

    public boolean pesquisar(String s) {
        return pesquisar(s, raiz, 0);
    }
    private boolean pesquisar(String s, No no, int i) {
        char c = s.charAt(i);
        int index = (int)c;
        if(no.prox[index] == null) return false; 
        if(i == s.length() - 1) return no.prox[index].folha; 
        return pesquisar(s, no.prox[index], i + 1);
    }

    public void mostrar() {
        mostrar("", raiz);
    }
    private void mostrar(String s, No no) {
        if (no.folha == true) {
            System.out.println("Palavra: " + s);
        }
        for (int i = 0; i < no.prox.length; i++) {
            if (no.prox[i] != null) {
                mostrar(s + no.prox[i].elemento, no.prox[i]);
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Arvore t = new Arvore();
        System.out.println("--- Inserindo ---");
        t.inserir("CASA");
        t.inserir("CASAS"); 
        System.out.println("\n--- Mostrando ---");
        t.mostrar();
    }
}