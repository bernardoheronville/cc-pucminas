class Fila {
    private int array[];
    private int primeiro;
    private int ultimo;

    public Fila(int x) {
        this.array = new int[x + 1];
        this.primeiro = this.ultimo = 0;
    }

    public void inserir(int x) {
        if((ultimo + 1) % array.length == primeiro) {
            throw new IllegalArgumentException("Fila cheia");
        }
        array[ultimo] = x;
        ultimo = (ultimo + 1) % array.length;   
    }

    public int remover() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Fila vazia");
        }
        int resp = array[primeiro];
        primeiro = (primeiro + 1) % array.length;
        return resp;
    }

    public void mostrar() {
        for(int i = primeiro; i != ultimo; i = (i + 1) % array.length) {
            System.out.printf("%d ", array[i]);
        }
        System.out.printf("\n");
    }
}

public class Main {
    public static void main(String args[]) {
        Fila fila = new Fila(5);
        fila.inserir(5);
        fila.inserir(2);
        fila.inserir(7);
        System.out.println("Numero: "+ fila.remover() + " removido");
        fila.mostrar();
        fila.inserir(13);
        fila.inserir(8);
        System.out.println("Numero: "+ fila.remover() + " removido");
        fila.mostrar();
    }
}