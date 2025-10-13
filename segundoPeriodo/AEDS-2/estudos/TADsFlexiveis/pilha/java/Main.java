class Celula {
    public int elemento;
    public Celula prox;

    public Celula() {
        this.elemento = 0;
        this.prox = null;
    }
    public Celula(int x) {
        this.elemento = x;
        this.prox = null;
    }
}

class Pilha {
    private Celula topo;

    public Pilha() {
        this.topo = null;
    }

    public void inserir(int x) {
        Celula nova = new Celula(x);
        nova.prox = topo;
        topo = nova;
        nova = null;
    }

    public int remover() {
        if(topo == null) {
             throw new IllegalArgumentException("Pilha vazia");
        }
        int resp = topo.elemento;
        Celula tmp = topo;
        topo = tmp.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }

    public void mostrar() {
        for(Celula i = topo; i != null; i = i.prox) {
            System.out.printf("%d ", i.elemento);
        }
        System.out.printf("\n");
    }
}

public class Main {
    public static void main(String args[]) {
        Pilha pilha = new Pilha();
        pilha.inserir(3);
        pilha.inserir(5);
        pilha.inserir(7);
        pilha.mostrar(); // 7 5 3
        System.out.println("Elemento " + pilha.remover() + " removido");
        pilha.mostrar(); // 5 3
    }
}