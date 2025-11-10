class No {
    public int elemento;
    public No esq;
    public No dir;

    public No(int x) {
        elemento = x;
        esq = dir = null;
    }
}

class Arvore {
    public No raiz;

    public Arvore() {
        raiz = null;
    }

    public void inserir(int x) {
        raiz = inserir(x, raiz);
    }
    private No inserir(int x, No i) {
        if(i == null) i = new No(x);
        else if(x > i.elemento) i.dir = inserir(x, i.dir);
        else if(x < i.elemento) i.esq = inserir(x, i.esq);
        else throw new IllegalArgumentException("ERRO");
        return i;
    }

    public void pesquisar(int x) {
        if(pesquisar(x, raiz)) {
            System.out.println("Numero " + x + " encontrado!");
        }
        else {
            System.out.println("Numero " + x + " nao encontrado!");
        }
    }
    private boolean pesquisar(int x, No i) {
        boolean resp = false;
        while(i != null) {
            if(x > i.elemento) i = i.dir;
            else if(x < i.elemento) i = i.esq;
            else {
                resp = true;
                i = null;
            }
        }
        return resp;
    }

    public void remover(int x) {
        raiz = remover(x, raiz);
    }
    private No remover(int x, No i) {
        if(i == null) throw new IllegalArgumentException("Elemento nao encontrado");
        else if(x > i.elemento) i.dir = remover(x, i.dir);
        else if(x < i.elemento) i.esq = remover(x, i.esq);
        else {
            // elemento foi encontrado.
            if(i.dir == null) i = i.esq; // tem apenas o filho da esquerda.
            else if(i.esq == null) i = i.dir; // tem apenas o filho da direita.
            else { // tem dois filhos
                i.elemento = getMaior(i.esq).elemento;
                i.esq = remover(i.elemento, i.esq);
            }
        }
        return i;
    }
    private No getMaior(No i) {
        while(i.dir != null) {
            i = i.dir;
        }
        return i;
    }

    public void caminharCentral() {
        caminharCentral(raiz);
    }
    private void caminharCentral(No i) {
        if(i != null) {
            caminharCentral(i.esq);
            System.out.println(i.elemento);
            caminharCentral(i.dir);
        }
    }
    public void caminharPre() {
        caminharPre(raiz);
    }
    private void caminharPre(No i) {
        if(i != null) {
            System.out.println(i.elemento);
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }
    public void caminharPos() {
        caminharPos(raiz);
    }
    private void caminharPos(No i) {
        if(i != null) {
            caminharPos(i.esq);
            caminharPos(i.dir);
            System.out.println(i.elemento);
        }
    }
}

public class Main {
    public static void main(String args[]) {
        Arvore arvore = new Arvore();
        arvore.inserir(3);
        arvore.inserir(1);
        arvore.inserir(9);
        arvore.inserir(2);
        arvore.inserir(7);
        arvore.inserir(21);
        arvore.inserir(17);
        arvore.caminharCentral();
        arvore.pesquisar(3);
        arvore.remover(3);
        arvore.caminharCentral();
    }
}