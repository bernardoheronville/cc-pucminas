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
        this(0);
    }
    public Matriz(int l, int c) {
        this.linha = l;
        this.coluna = c;
        Celula nova = new Celula();
        this.inicio = nova;
        for(int i = 0; i < l; i++) { 
            for(int j = 0; j < c; j++) {
                Celula nova = new Celula();
                Celula tmp = inicio;
                int linha = 0, coluna = 0;
                if(i != 0 && j != 0) {
                    while(coluna != j) {
                        tmp = tmp.prox;
                        coluna++;
                    }
                    while(linha < i - 1) {
                        tmp = tmp.inf;
                        linha++;
                    }
                    tmp.inf = nova;
                    nova.sup = tmp;
                    tmp = inicio;
                    while(linha != i) {
                        tmp = tmp.inf;
                        linha++;
                    }
                    while(coluna < j - 1) {
                        tmp = tmp.prox;
                        coluna++;
                    }
                    tmp.prox = nova;
                    nova.ant = tmp;
                }
                else if(i == 0) {
                    while(tmp.prox != null) tmp = tmp.prox;
                    tmp.prox = nova;
                    nova.ant = tmp;
                }
                else {
                    while(tmp.inf != null) tmp = tmp.inf;
                    tmp.inf = nova;
                    nova.sup = tmp;                   
                }
            }
        }
    }
}

public class Main {
    public static void main(String args[]) {

    }
}