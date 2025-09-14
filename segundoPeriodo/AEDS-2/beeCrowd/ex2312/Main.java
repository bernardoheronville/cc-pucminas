import java.util.Scanner;

class Paises {
    public String nome;
    public int ouro;
    public int prata;
    public int bronze;

    Paises(String nome, int ouro, int prata, int bronze) {
        this.nome = nome;
        this.ouro = ouro;
        this.prata = prata;
        this.bronze = bronze;
    }

    public void mostrar() {
        System.out.println(nome + " " + ouro + " " + prata + " " + bronze);
    }
}

public class Main {

    public static void ordenar(Paises paises[], int n) {
        for(int i = 1; i < n; i++) {
            Paises tmp = paises[i];
            int j = i - 1;
            while(j >= 0 && (
            (paises[j].ouro < tmp.ouro) || 
            (paises[j].ouro == tmp.ouro && paises[j].prata < tmp.prata) || 
            (paises[j].ouro == tmp.ouro && paises[j].prata == tmp.prata && paises[j].bronze < tmp.bronze) || 
            (paises[j].ouro == tmp.ouro && paises[j].prata == tmp.prata && paises[j].bronze == tmp.bronze && paises[j].nome.compareTo(tmp.nome) > 0)
            )) {
                paises[j + 1] = paises[j];
                j--;
            }
            paises[j + 1] = tmp;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Paises paises[] = new Paises[n];
        for(int i = 0; i < n; i++) {
            String nome = sc.next();
            int ouro = sc.nextInt();
            int prata = sc.nextInt();
            int bronze = sc.nextInt();
            paises[i] = new Paises(nome, ouro, prata, bronze);
        }
        ordenar(paises, n);
        for(int i = 0; i < n; i++) {
            paises[i].mostrar();
        }
        sc.close();
    }
}