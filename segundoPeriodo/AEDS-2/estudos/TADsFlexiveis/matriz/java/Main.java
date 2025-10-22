class Celula {
    public int elemento;
    public Celula sup, inf, prox, ant;

    public Celula() {
        this.elemento = 0;
        this.sup = null;
        this.inf = null;
        this.prox = null;
        this.ant = null;
    }
    public Celula(int x) {
        this.elemento = x;
        this.sup = null;
        this.inf = null;
        this.prox = null;
        this.ant = null;
    }
}

class Matriz {
    private Celula inicio;
    private int linha, coluna;

    public Matriz() {
        this(3, 3);
    }
    public Matriz(int l, int c) {
        this.linha = l;
        this.coluna = c;
        this.inicio = new Celula();
        Celula tmp = inicio;
        for(int i = 1; i < c; i++, tmp = tmp.prox) {
            tmp.prox = new Celula();
            tmp.prox.ant = tmp;
        }
        Celula col = inicio, linha = inicio;
        for(int i = 1; i < l; i++) {
            linha.inf = new Celula();
            linha.inf.sup = linha;
            linha = linha.inf;
            col = linha;
            for(int j = 1; j < c; j++, col = col.prox) {
                col.prox = new Celula();
                col.prox.ant = col;
                col.prox.sup = col.sup.prox;
                col.prox.sup.inf = col.prox;
            }
        }
    }
}

public class Main {
    public static void main(String args[]) {

    }
}