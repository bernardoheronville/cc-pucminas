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

class Lista {
    private Celula primeiro, ultimo;

    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserirInicio(int x) {
        primeiro.elemento = x;
        Celula tmp = new Celula();
        tmp.prox = primeiro;
        primeiro = tmp;
        tmp = null;
    }
    public void inserirFim(int x) {
        Celula tmp = new Celula(x);
        ultimo.prox = tmp;
        ultimo = tmp;
        tmp = null;
    }
    public void inserir(int x, int pos) {
        if(pos < 0 || pos > tamanho()) {
            throw new IllegalArgumentException("Posicao invalida");
        }
        else if(pos == 0) {
            inserirInicio(x);
        }
        else if(pos == tamanho()) {
            inserirFim(x);
        }
        else {
            Celula tmp = primeiro;
            for(int i = 0; i < pos; tmp = tmp.prox, i++);
            Celula nova = new Celula(x);
            nova.prox = tmp.prox;
            tmp.prox = nova;
            tmp = nova = null;
        }
    }
    
    public int removerInicio() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        Celula tmp = primeiro.prox;
        int resp = tmp.elemento;
        primeiro.prox = tmp.prox;
        return resp;
    }

    public int removerFim() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        int resp = ultimo.elemento;
        Celula i;
        for(i = primeiro; i.prox != ultimo; i = i.prox);
        ultimo = i;
        ultimo.prox = i = null;
        return resp;
    }

    public int remover(int pos) {
        int resp;
        if(primeiro == ultimo || pos < 0 || pos > tamanho()) {
            throw new IllegalArgumentException("ERRO");
        }
        else if(pos == 0) {
            resp = removerInicio();
        }
        else if(pos == tamanho()) {
            resp = removerFim();
        }
        else {
            Celula tmp = primeiro;
            for(int i = 0; i < pos; i++, tmp = tmp.prox);
            resp = tmp.prox.elemento;
            tmp.prox = tmp.prox.prox;
            tmp = null;
        }   
        return resp;
    }

    public int tamanho() {
        int count = 0;
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            count++;
        }
        return count;
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
        Lista lista = new Lista();
        lista.inserirInicio(3);
        lista.inserirInicio(5);
        lista.inserirInicio(7);
        lista.mostrar(); // 7 5 3
        lista.inserirFim(2);
        lista.inserirFim(12);
        lista.mostrar(); // 7 5 3 2 12
        lista.inserir(13, 2);
        lista.mostrar(); // 7 5 13 3 2 12
        System.out.println("Elemento " + lista.removerInicio() + " removido.");
        lista.mostrar(); // 5 13 3 2 12
        System.out.println("Elemento " + lista.removerFim() + " removido.");
        lista.mostrar(); // 5 13 3 2
        System.out.println("Elemento " + lista.remover(1) + " removido.");
        lista.mostrar(); // 5 3 2
    }
}