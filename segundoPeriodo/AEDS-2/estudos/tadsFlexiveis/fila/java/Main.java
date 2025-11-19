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

class Fila {
    private Celula primeiro;
    private Celula ultimo;
    
    public Fila() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserir(int x) {
        Celula nova = new Celula(x);
        ultimo.prox = nova;
        ultimo = nova;
        nova = null;
    }

    public int remover() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Fila vazia");
        }
        Celula tmp = primeiro.prox;
        int resp = tmp.elemento;
        primeiro.prox = tmp.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }

    public void mostrar() {
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.printf("%d ", i.elemento);
        }
        System.out.printf("\n");
    }
}

public class Main {
    public static void main(String args[]) {
        Fila fila = new Fila();
        fila.inserir(3);
        fila.inserir(5);
        fila.inserir(7);
        fila.mostrar(); // 3 5 7
        System.out.println("Elemento " + fila.remover() + " removido");
        fila.mostrar(); // 5 7
    }
}