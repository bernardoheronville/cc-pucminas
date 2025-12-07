class Hash {
    public Lista tabela[];
    public int tam;

    public Hash(int x) {
        tam = x;
        tabela = new Lista[tam];
        for(int i = 0; i < tam; i++) {
            tabela[i] = new Lista();
        }
    }

    public int h(int x) {
        return x % tam;
    }

    public void inserir(int x) {
        int pos = h(x);
        tabela[pos].inserir(x);
    }

    public int remover(int x) {
        int pos = h(x);
        int resp = tabela[pos].remover(x);
        return resp;
    }

    public void pesquisar(int x) {
        int pos = h(x);
        if(tabela[pos].pesquisar(x)) {
            System.out.println("Elemento " + x + " encontrado");
        }
        else {
            System.out.println("Elemento " + x + " nao encontrado");
        }
    }

    public void mostrar() {
        for(int i = 0; i < tam; i++) {
            tabela[i].mostrar();
        }
    }
}

class Lista {
    Celula primeiro;
    Celula ultimo;

    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserir(int x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public int remover(int x) {
        int resp = -1;
        if(primeiro == ultimo) return resp;
        else {
            for(Celula i = primeiro; i.prox != null; i = i.prox) {
                if(i.prox.elemento == x) {
                    Celula tmp = i.prox;
                    resp = tmp.elemento;
                    if(tmp == ultimo) {
                        ultimo = i;
                    }
                    i.prox = tmp.prox;
                    tmp.prox = null;
                    tmp = null;
                    return resp;
                }
            }
        }
        return resp; 
    }

    public boolean pesquisar(int x) {
        boolean resp = false;
        if(primeiro == ultimo) resp = false;
        else {
            for(Celula i = primeiro.prox; i != null; i = i.prox) {
                if(i.elemento == x) {
                    resp = true;
                    i = ultimo;
                }
            }
        }
        return resp; 
    }

    public void mostrar() {
        System.out.print("[ ");
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.printf("%d ", i.elemento);
        }
        System.out.println("]");
    }
}

class Celula {
    public int elemento;
    public Celula prox;

    public Celula() {
        elemento = 0;
        prox = null;
    }
    public Celula(int x) {
        elemento = x;
        prox = null;
    }
}

public class Main {
    public static void main(String args[]) {
        Hash h = new Hash(7);
        h.inserir(5);
        h.inserir(7);
        h.inserir(14);
        h.inserir(21);
        h.inserir(19);
        h.inserir(3);
        h.mostrar();
        System.out.println("Elemento " + h.remover(5) + " removido");
        h.pesquisar(1);
        h.mostrar();
    }
}