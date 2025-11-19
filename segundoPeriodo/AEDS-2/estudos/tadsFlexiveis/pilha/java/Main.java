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

    public int soma() {
        int count = 0;
        for(Celula i = topo; i != null; i = i.prox) {
            count += i.elemento;
        }
        return count;
    }

    public int somaRec() {
        return somaRec(topo);
    }
    private int somaRec(Celula i) {
        if (i == null) return 0;
        return i.elemento + somaRec(i.prox);
    }

    public int maiorElemento() {
        int maior = Integer.MIN_VALUE;
        for(Celula i = topo; i != null; i = i.prox) {
            if(i.elemento > maior) {
                maior = i.elemento;
            }
        }
        return maior;
    }

    public int maiorElementoRec() {
        return maiorElementoRec(topo, Integer.MIN_VALUE);
    }
    private int maiorElementoRec(Celula i, int maior) {
        if (i == null) {
            return maior;
        }     
        else {
            if (i.elemento > maior) {
                maior = i.elemento;
            }
            return maiorElementoRec(i.prox, maior);
        }
    }

    public void mostrarRec() {
        mostrarRec(topo);
        System.out.printf("\n");
    }
    private void mostrarRec(Celula i) {
        if(i != null) {
            System.out.printf("%d ", i.elemento);
            mostrarRec(i.prox);
        } 
    }

    public void mostrarRecInvertido() {
        mostrarRecInvertido(topo);
        System.out.printf("\n");
    }
    private void mostrarRecInvertido(Celula i) {
        if(i != null) {
            mostrarRecInvertido(i.prox);
            System.out.printf("%d ", i.elemento);
        } 
    }

    public int tamanho() {
        int count = 0;
        for(Celula i = topo; i != null; i = i.prox) {
            count++;
        }
        return count;
    }

    public void mostrarInvertido() {
        for(int i = tamanho() - 1; i >= 0; i--) {
            Celula tmp = topo;
            for(int j = 0; j < i; j++, tmp = tmp.prox);
            System.out.printf("%d ", tmp.elemento);
        }
        System.out.printf("\n");
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
        pilha.inserir(3);
        pilha.inserir(5);
        pilha.inserir(7);
        System.out.println("A soma dos elementos da pilha eh " + pilha.soma()); // 23
        System.out.println("A soma dos elementos da pilha eh " + pilha.somaRec()); // 23
        System.out.println("O maior elemento da pilha eh " + pilha.maiorElemento()); // 7
        System.out.println("O maior elemento da pilha eh " + pilha.maiorElementoRec()); // 7
        pilha.mostrarRec(); // 7 5 3 5 3
        pilha.mostrarRecInvertido(); // 3 5 3 5 7
        pilha.mostrarInvertido(); // 3 5 3 5 7
    }
}