class No {
    public int elemento;
    public No esq;
    public No dir;

    public No() {
        elemento = 0;
        esq = dir = null;
    }
    public No(int x) {
        elemento = x;
        esq = dir = null;
    }
}

class ArvoreAVL {
    public No raiz;

    public ArvoreAVL() {
        raiz = null;
    }
}

public class Main {
    public static void main(String args[]) {

    }
}