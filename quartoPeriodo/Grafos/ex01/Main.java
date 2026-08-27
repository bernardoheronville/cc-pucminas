import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o nome do arquivo para a leitura");
        String nameArq = sc.nextLine();
        File arq = new File(nameArq);
        Scanner scfile = new Scanner(arq);
        int n = scfile.nextInt();
        int m = scfile.nextInt();
        List<Integer>[] sucessores = new ArrayList[n + 1];
        List<Integer>[] predecessores = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++) {
            sucessores[i] = new ArrayList<>();
            predecessores[i] = new ArrayList<>();
        }
        int contador = 0;
        while(contador < m) {
            int origem = scfile.nextInt();
            int destino = scfile.nextInt();
            sucessores[origem].add(destino);
            predecessores[destino].add(origem);
            contador++;
        }
        System.out.println("Digite o no que sera analisado");
        int no = sc.nextInt();
        if(no < 1 || no > n) {
            System.out.println("Digite um numero valido");
        }
        else {
            System.out.println("A quantidade de sucessores do no " + no + " eh " + sucessores[no].size());
            System.out.println("A quantidade de predecessores do no " + no + " eh " + predecessores[no].size());
            System.out.println("Os sucessores do no " + no + " eh " + sucessores[no]);
            System.out.println("Os predecessores do no " + no + " eh " + predecessores[no]);
        }
        sc.close();
        scfile.close();
    }
}