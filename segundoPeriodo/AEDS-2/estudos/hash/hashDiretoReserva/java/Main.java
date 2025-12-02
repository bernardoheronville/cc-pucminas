class Hash {
    public int tabela[];
    int tamNormal, tamReserva, tamTotal, reserva;
    
    public Hash(int x, int y) {
        this.tamNormal = x;
        this.tamReserva = y;
        this.tamTotal = x + y;
        tabela = new int[this.tamTotal];
        for(int i = 0; i < tamTotal; i++) {
            tabela[i] = -1;
        }
        reserva = 0;
    }
 
    private int hash(int x) {
        return x % tamNormal;
    }

    public void inserir(int x) {
        if(x != 1) {
            int num = hash(x);
            if(tabela[num] == -1) tabela[num] = x;
            else if(reserva < tamReserva) {
                for(int i = 0; i < tamReserva; i++) {
                    if(tabela[tamNormal + i] == -1) {
                        tabela[tamNormal + i] = x;
                        reserva++;
                        i = tamReserva;
                    }      
                }
            }
            else {
                throw new IllegalArgumentException("Hash cheio");
            }
        }
        else {
            throw new IllegalArgumentException("Nao pode inserir o -1");
        }
    }

    public int remover(int x) {
        int resp = -1;
        if(x != 1) {
            int num = hash(x);
            if(tabela[num] == x) {
                tabela[num] = -1;
                resp = x;
            }
            else {
                for(int i = 0; i < tamReserva; i++) {
                    if(tabela[tamNormal + i] == x) {
                        resp = x;
                        tabela[tamNormal + i] = -1;
                        reserva--;
                        i = tamReserva;
                    }
                }
            }
        }
        return resp;
    }

    public void pesquisar(int x) {
        if(pesquisarAux(x)) {
            System.out.println("Elemento " + x + " encontrado");
        }
        else {
            System.out.println("Elemento " + x + " nao encontrado");
        }
    }
    private boolean pesquisarAux(int x) {
        boolean resp = false;
        if(x != 1) {
            int num = hash(x);
            if(tabela[num] == x) {
                resp = true;
            }
            else {
                for(int i = 0; i < tamReserva; i++) {
                    if(tabela[tamNormal + i] == x) {
                        resp = true;
                        i = tamReserva;
                    }
                }
            }
        }
        return resp;
    }

    public void mostrar() {
        for(int i = 0; i < tamTotal; i++) {
            System.out.print(tabela[i] + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Hash h = new Hash(7, 3);
        h.inserir(5);
        h.inserir(7);
        h.inserir(14);
        h.inserir(21);
        h.inserir(19);
        h.mostrar();
        h.pesquisar(13);
    }
}