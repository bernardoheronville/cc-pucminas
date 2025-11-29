import java.util.Scanner;

class Carro {
    public String placa, modelo, tipo, chassi;
 
    public void ler(String linha) {
        String[] partes = linha.split(",");
        placa = partes[0]; modelo = partes[1]; tipo = partes[2]; chassi = partes[3];
    }
    void imprimir() {
        System.out.println(placa + " " + modelo + " " + tipo + " " + chassi);
    }
}

class No {
    public Carro carro;
    public No esq, dir;

    public No(Carro x) {
        carro = x;
        esq = dir = null;
    }
}

class Arvore {
    public No raiz;

    public Arvore() {
        raiz = null;
    }

    public void inserir(Carro x) {
        raiz = inserir(x, raiz);
    }
    private No inserir(Carro x, No i) {
        if(i == null) i = new No(x);
        else if(x.placa.compareTo(i.carro.placa) > 0) i.dir = inserir(x, i.dir);
        else if(x.placa.compareTo(i.carro.placa) < 0) i.esq = inserir(x, i.esq);
        else ;
        return i;
    }

    public void caminharCentral() {
        caminharCentral(raiz);
    }
    private void caminharCentral(No i) {
        if(i != null) {
            caminharCentral(i.esq);
            i.carro.imprimir();
            caminharCentral(i.dir);
        } 
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Arvore arvore = new Arvore();
        String entrada = sc.nextLine();
        while(!entrada.equals("FIM")) {
            Carro carro = new Carro();
            carro.ler(entrada);
            arvore.inserir(carro);
            entrada = sc.nextLine();
        }
        arvore.caminharCentral();
    }
}
