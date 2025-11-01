import java.util.Scanner;

class Intervalo{
    public int inicio;
    public int fim;
    public Intervalo(int a, int b) {
        inicio = a;
        fim = b;
    }
}

public class Main {
    public static void swap(Intervalo array[], int i, int j) {
        Intervalo temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void quickSort(Intervalo array[], int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[(esq + dir) / 2].inicio;
        while(i <= j) {
            while(array[i].inicio < pivo) i++;
            while(array[j].inicio > pivo) j--;
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
        int p = sc.nextInt();
        int s = sc.nextInt();
        int teste = 1;
        while(p != 0 || s != 0) {
            Intervalo intervalo[] = new Intervalo[s];
            for(int i = 0; i < s; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                intervalo[i] = new Intervalo(u, v);
            }
            quickSort(intervalo, 0, s - 1);
            System.out.println("Teste " + teste++);
            if(s > 0) {
                int inicioAtual = intervalo[0].inicio;
                int fimAtual = intervalo[0].fim;
                for(int i = 1; i < s; i++) {
                    int inicioProx = intervalo[i].inicio;
                    int fimProx = intervalo[i].fim;
                    if(inicioProx <= fimAtual) {
                        if(fimProx > fimAtual) {
                            fimAtual = fimProx;
                        }
                    }
                    else {
                        System.out.println(inicioAtual + " " + fimAtual);
                        inicioAtual = inicioProx;
                        fimAtual = fimProx;
                    }
                }
                System.out.println(inicioAtual + " " + fimAtual);
            }
            System.out.println();
            p = sc.nextInt();
            s = sc.nextInt();
        }
        sc.close();
    }
}
