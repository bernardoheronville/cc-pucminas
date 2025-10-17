class Celula {
    public int elemento;
    public Celula prox, ant;

    public Celula() {
        this.elemento = 0;
        this.prox = this.ant = null;
    }
    public Celula(int x) {
        this.elemento = x;
        this.prox = this.ant = null;
    }
}

class ListaDupla {
    private Celula primeiro, ultimo;

    public ListaDupla() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserirInicio(int x) {
        primeiro.elemento = x;
        Celula tmp = new Celula();
        tmp.prox = primeiro;
        primeiro.ant = tmp;
        primeiro = tmp;
        tmp = null;
    }
    public void inserirFim(int x) {
        Celula tmp = new Celula(x);
        ultimo.prox = tmp;
        tmp.ant = ultimo;
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
            Celula aux = primeiro.prox;
            for(int i = 1; i < pos; i++, aux = aux.prox);
            Celula tmp = new Celula(x);
            tmp.prox = aux.prox;
            tmp.prox.ant = tmp;
            aux.prox = tmp;
            tmp.ant = aux;
            tmp = aux = null;
        }
    }

    public int removerInicio() {
        if (primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        Celula tmp = primeiro.prox;
        int resp = tmp.elemento;
        primeiro.prox = tmp.prox;
        if (tmp.prox != null) {
            tmp.prox.ant = primeiro;
        } else {
            ultimo = primeiro;
        }

        return resp;
    }
    public int removerFim() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        Celula tmp = ultimo;
        ultimo = ultimo.ant;
        int resp = tmp.elemento;
        tmp.ant = ultimo.prox = null;
        tmp = null;
        return resp;
    }

    public int remover(int pos) {
        int resp;
        if(primeiro == ultimo || pos < 0 || pos >= tamanho()) {
            throw new IllegalArgumentException("Lista vazia ou posicao invalida");
        }
        else if(pos == 0) {
            resp = removerInicio();
        }
        else if(pos == tamanho() - 1) {
            resp = removerFim();
        }
        else {
            Celula tmp = primeiro.prox;
            for(int i = 0; i < pos; i++, tmp = tmp.prox);
            resp = tmp.elemento;
            tmp.ant.prox = tmp.prox;
            tmp.prox.ant = tmp.ant;
            tmp.prox = tmp.ant = null;
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
        ListaDupla lista = new ListaDupla();
        lista.inserirInicio(3);
        lista.inserirInicio(5);
        lista.inserirInicio(7);
        lista.mostrar(); // 7 5 3
        lista.inserirFim(13);
        lista.mostrar(); // 7 5 3 13
        lista.inserir(20, 2);
        lista.mostrar(); // 7 5 20 3 13
        System.out.println("Elemento " + lista.removerInicio() + " removido");
        lista.mostrar(); // 5 20 3 13
        System.out.println("Elemento " + lista.removerFim() + " removido");
        lista.mostrar(); // 5 20 3
        System.out.println("Elemento " + lista.remover(1) + " removido");
        lista.mostrar(); // 5 3
    }
}