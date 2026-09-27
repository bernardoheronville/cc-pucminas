import java.io.*;
import java.util.*;

public class Main {
    static int tempo = 0;
    static int cor[], TD[], TT[];
    static List<Integer> sucessores[];
    static List<String> arestasArv = new ArrayList<>();
    static List<String> arestasRet = new ArrayList<>();
    static List<String> arestasAva = new ArrayList<>();
    static List<String> arestasCru = new ArrayList<>();

    public static void dfsVisita(int u, int verticeEscolhido) {
        cor[u] = 1; 
        tempo++;
        TD[u] = tempo;
        for(int i = 0; i < sucessores[u].size(); i++) {
            int v = sucessores[u].get(i);
            if(cor[v] == 0) { 
                arestasArv.add(u + " -> " + v);
                if (u == verticeEscolhido) System.out.println("Aresta (" + u + ", " + v + "): Aresta de Árvore");
                dfsVisita(v, verticeEscolhido);
            } else if(cor[v] == 1) { 
                arestasRet.add(u + " -> " + v);
                if(u == verticeEscolhido) System.out.println("Aresta (" + u + ", " + v + "): Aresta de Retorno");
            } else if(cor[v] == 2) { 
                if(TD[u] < TD[v]) {
                    arestasAva.add(u + " -> " + v);
                    if(u == verticeEscolhido) System.out.println("Aresta (" + u + ", " + v + "): Aresta de Avanco");
                } 
                else {
                    arestasCru.add(u + " -> " + v);
                    if(u == verticeEscolhido) System.out.println("Aresta (" + u + ", " + v + "): Aresta de Cruzamento");
                }
            }
        }
        cor[u] = 2; 
        tempo++;
        TT[u] = tempo;
    }

    @SuppressWarnings("unchecked")
    public static void main(String args[]) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o nome do arquivo para a leitura");
        String nameArq = sc.nextLine();

        System.out.println("Digite o vértice a ser analisado:");
        int verticeEscolhido = sc.nextInt();
        sc.close();

        File arq = new File(nameArq);
        Scanner scfile = new Scanner(arq);

        int n = scfile.nextInt();
        int m = scfile.nextInt();

        sucessores = new ArrayList[n + 1];
        cor = new int[n + 1];
        TD = new int[n + 1];
        TT = new int[n + 1];
        
        for(int i = 0; i <= n; i++) {
            sucessores[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int origem = scfile.nextInt();
            int destino = scfile.nextInt();
            sucessores[origem].add(destino);
        }
        scfile.close();

        for(int i = 1; i <= n; i++) {
            Collections.sort(sucessores[i]);
        }

        System.out.println("\n--- CLASSIFICAÇÃO DAS ARESTAS DE SAÍDA DO VÉRTICE ESCOLHIDO " + verticeEscolhido + " ---");
    
        for (int i = 1; i <= n; i++) {
            if (cor[i] == 0) {
                dfsVisita(i, verticeEscolhido);
            }
        }

        System.out.println("\n--- ARESTAS DE ÁRVORE DA BUSCA ---");
        for (String aresta : arestasArv) {
            System.out.println(aresta);
        }
    }
}