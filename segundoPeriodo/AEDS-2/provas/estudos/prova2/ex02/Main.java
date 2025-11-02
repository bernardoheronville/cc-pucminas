import java.util.Scanner;

class Atleta {
    public String nome;
    public int peso;

    public Atleta(String nome, int peso) {
        this.nome = nome;
        this.peso = peso;
    }
    public Atleta() {
        nome = "";
        peso = 0;
    }
}

public class Main {
    public static void swap(Atleta array[], int i, int j) {
        Atleta temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void quickSort(Atleta array[], int esq, int dir) {
        int i = esq, j = dir;
        int pivoPeso = array[(esq + dir) / 2].peso;
        String pivoNome = array[(esq + dir) / 2].nome;
        while(i <= j) {
            while((array[i].peso > pivoPeso) || (array[i].peso == pivoPeso && pivoNome.compareTo(array[i].nome) > 0)) i++;
            while((array[j].peso < pivoPeso) || (array[j].peso == pivoPeso && pivoNome.compareTo(array[j].nome) < 0)) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(esq < j) quickSort(array, esq, j);
        if(i < dir) quickSort(array, i, dir);
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String nome;
        int n = sc.nextInt(), peso;
        Atleta atletas[] = new Atleta[n];
        for(int i = 0; i < n; i++) {
            nome = sc.next();
            peso = sc.nextInt();
            atletas[i] = new Atleta(nome, peso);
        }
        quickSort(atletas, 0, n - 1);
        for(int i = 0; i < n; i++) {
            System.out.println(atletas[i].nome + " " + atletas[i].peso);
        }
    }
}