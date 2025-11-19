import java.util.Scanner;

class Lista {
    private int[] array;
    private int n;

    public Lista(int x) {
        this.array = new int[x];
        this.n = 0;
    }

    public void inserirInicio(int x) {
        if (n >= array.length) {
            throw new IllegalArgumentException("Lista cheia");
        }
        for (int i = n; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = x;
        n++;
    }

    public void inserirFim(int x) {
        if (n >= array.length) {
            throw new IllegalArgumentException("Lista cheia");
        }
        array[n++] = x;
    }

    public void inserir(int x, int pos) {
        if (n >= array.length) {
            throw new IllegalArgumentException("Lista cheia");
        }
        if (pos < 0 || pos > n) {
            throw new IllegalArgumentException("Posição inválida");
        }
        for (int i = n; i > pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos] = x;
        n++;
    }

    public int removerInicio() {
        if (n == 0) {
            throw new IllegalArgumentException("Lista vazia");
        }
        int resp = array[0];
        for (int i = 0; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
        n--;
        return resp;
    }

    public int removerFim() {
        if (n == 0) {
            throw new IllegalArgumentException("Lista vazia");
        }
        int resp = array[--n]; 
        return resp;
    }

    public int remover(int pos) {
        if (n == 0) {
            throw new IllegalArgumentException("Lista vazia");
        }
        if (pos < 0 || pos >= n) {
            throw new IllegalArgumentException("Posição inválida");
        }
        int resp = array[pos];
        for (int i = pos; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
        n--;
        return resp;
    }

    public void mostrar() {
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", array[i]);
        }
        System.out.println("\n");
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Lista lista = new Lista(10);

        System.out.println("=== Testando Inserções ===");

        // Inserir no fim
        lista.inserirFim(10);
        lista.inserirFim(20);
        lista.inserirFim(30);
        System.out.print("Após inserirFim(10, 20, 30): ");
        lista.mostrar(); // 10 20 30

        // Inserir no início
        lista.inserirInicio(5);
        System.out.print("Após inserirInicio(5): ");
        lista.mostrar(); // 5 10 20 30

        // Inserir em posição específica
        lista.inserir(15, 2);
        System.out.print("Após inserir(15, 2): ");
        lista.mostrar(); // 5 10 15 20 30


        System.out.println("\n=== Testando Remoções ===");

        // Remover do início
        int removidoInicio = lista.removerInicio();
        System.out.println("Removido do início: " + removidoInicio);
        lista.mostrar(); // 10 15 20 30

        // Remover do fim
        int removidoFim = lista.removerFim();
        System.out.println("Removido do fim: " + removidoFim);
        lista.mostrar(); // 10 15 20

        // Remover de uma posição específica
        int removidoPos = lista.remover(1);
        System.out.println("Removido da posição 1: " + removidoPos);
        lista.mostrar(); // 10 20


        System.out.println("\n=== Teste com Entrada do Usuário ===");

        System.out.print("Digite um valor para inserir no início: ");
        int valorInicio = sc.nextInt();
        lista.inserirInicio(valorInicio);
        lista.mostrar();

        System.out.print("Digite um valor para inserir no fim: ");
        int valorFim = sc.nextInt();
        lista.inserirFim(valorFim);
        lista.mostrar();

        System.out.print("Digite um valor e uma posição para inserir (valor pos): ");
        int valor = sc.nextInt();
        int pos = sc.nextInt();
        lista.inserir(valor, pos);
        lista.mostrar();

        System.out.println("\nRemovendo início, fim e posição 1...");
        lista.removerInicio();
        lista.removerFim();
        lista.remover(1);
        lista.mostrar();
    }
}