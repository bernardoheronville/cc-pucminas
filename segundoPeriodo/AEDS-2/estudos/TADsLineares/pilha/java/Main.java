import java.util.Scanner;

class Pilha {
    private int array[];
    private int topo;
    
    public Pilha(int tamanho) {
        this.topo = -1;
        this.array = new int[tamanho];
    }
    
    public void inserir(int x) {
        if(topo == array.length - 1) {
            throw new IllegalArgumentException("Pilha cheia");
        }
        array[++topo] = x;
    }

    public int remover() {
        if(topo == -1) {
            throw new IllegalArgumentException("Pilha vazia");
        }
        int resp = array[topo--];
        return resp; 
    }

    public void mostrar() {
        if(topo == -1) {
            throw new IllegalArgumentException("Pilha vazia");
        }
        for(int i = topo; i >= 0; i--) {
            System.out.printf("%d ", array[i]);
        }
        System.out.printf("\n");
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Pilha pilha = new Pilha(5);
        pilha.inserir(7);
        pilha.inserir(3);
        pilha.inserir(9);
        pilha.mostrar();
        pilha.remover();
        pilha.mostrar();
        pilha.inserir(10);
        pilha.mostrar();
    }
}