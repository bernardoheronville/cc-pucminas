class Celula {
    private int elemento;
    private Celula sup, inf, prox, ant;

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
        
    }
}

public class Main {
    public static void main(String args[]) {

    }
}