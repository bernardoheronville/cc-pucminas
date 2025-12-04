import java.util.Scanner;

class Paises {
    public String nome;
    public int ouro;
    public int prata;
    public int bronze;

    public Paises(String nome) {
        this.nome = nome;
        this.ouro = 0;
        this.prata = 0;
        this.bronze = 0;
    }
}

public class Main {
    public static int compare(Paises a, Paises b) {
        if (a.ouro != b.ouro) return b.ouro - a.ouro;
        if (a.prata != b.prata) return b.prata - a.prata;
        if (a.bronze != b.bronze) return b.bronze - a.bronze;
        return a.nome.compareTo(b.nome);
    }

    public static void swap(Paises array[], int i, int j) {
        Paises temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void quickSort(Paises array[], int esq, int dir) {
        int i = esq, j = dir;
        Paises pivo = array[(esq + dir) / 2];
        while(i <= j) {
            while(compare(array[i], pivo) < 0) i++; 
            while(compare(array[j], pivo) > 0) j--;  
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(esq < j) quickSort(array, esq, j);      
        if(i < dir) quickSort(array, i, dir);    
    }

    public static int obterPais(Paises paises[], String nome) {
        for (int i = 0; i < paises.length; i++) {
            if (paises[i] != null && paises[i].nome.equals(nome)) {
                return i;
            }
        }
        for (int i = 0; i < paises.length; i++) {
            if (paises[i] == null) {
                paises[i] = new Paises(nome);
                return i;
            }
        }
        return -1; 
    }

    public static void adicionarMedalha(Paises paises[], String nome, int tipo) {
        int i = obterPais(paises, nome);
        switch (tipo) {
            case 2: 
                paises[i].ouro++; 
                break;
            case 1: 
                paises[i].prata++; 
                break;
            case 0: 
                paises[i].bronze++; 
                break;
            default:
                break;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Paises paises[] = new Paises[300];
        while(sc.hasNextLine()) {
            String lixo = sc.nextLine();
            String gold = sc.nextLine().trim();
            adicionarMedalha(paises, gold, 2);
            String silver = sc.nextLine().trim();
            adicionarMedalha(paises, silver, 1);
            String bronze = sc.nextLine().trim();
            adicionarMedalha(paises, bronze, 0);
        }
        int n = 0;
        for (int i = 0; i < paises.length; i++) {
            if (paises[i] != null) n++;
         }
        quickSort(paises, 0, n - 1);
        System.out.println("Quadro de Medalhas");
        for(int i = 0; i < n; i++) {
            System.out.println(paises[i].nome + " " + paises[i].ouro + " " + paises[i].prata + " " + paises[i].bronze);
        }
        sc.close();
    }
}
