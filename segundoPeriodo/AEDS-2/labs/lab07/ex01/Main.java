class No {
    public int elemento;
    public No esq;
    public No dir;

    public No() {
        elemento = 0;
        esq = null;
        dir = null;
    }
    public No(int x) {
        elemento = x;
        esq = null;
        dir = null;
    }
}

class Arvore {
    public No raiz;

    public Arvore() {
        raiz = null;
    }

    public No inserir(int x, No i) {
        if(i == null) i = new No(x);
        else if(x > i.elemento) i.dir = inserir(x, i.dir);
        else if(x < i.elemento) i.esq = inserir(x, i.esq);
    }
    public void inserir(int x) {
        inserir(x, raiz);
    }

    public void mostrar() {
        
    }
}

class Main {
    public static void main(String args[]) {
        Arvore arvore = new Arvore();

    }
}