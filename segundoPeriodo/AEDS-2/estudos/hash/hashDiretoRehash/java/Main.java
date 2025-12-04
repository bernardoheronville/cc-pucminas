class Hash {
    private int tabela[];
    private int tam;

    public Hash(int x) {
        tabela = new int[x];
        tam = x;
        for(int i = 0; i < tam; i++) {
            tabela[i] = -1;
        }
    }

    private int h(int x) {
        return x % tam;
    }
    private int reh(int x) {
        return ++x % tam;
    }

    public void inserir(int x) {
        if(x != -1) {
            int hash = h(x);
            if(tabela[hash] == -1) tabela[hash] = x;
            else {
                int rehash = reh(x);
                if(tabela[rehash] == -1) tabela[rehash] = x;
                else {
                    System.out.println("Nao eh possivel inserir o numero " + x);
                }
            }
        }
    }

    public int remover(int x) {
        int resp = -1;
        if(x != -1) {
            int hash = h(x);
            if(tabela[hash] == x) {
                tabela[hash] = -1;
                resp = x;
            }
        }
        else {
            int rehash = reh(x);
            if(tabela[rehash] == x) {
                tabela[rehash] = -1;
                resp = x;
            }
        }
        return resp;
    }

    public void pesquisar(int x) {
        if(pesquisarAux(x)) {
            System.out.println("Elemento " + x + " encontrado!");
        }
        else {
            System.out.println("Elemento " + x + " nao encontrado!");
        }
    }
    private boolean pesquisarAux(int x) {
        boolean resp = false;
        int hash = h(x);
        if(tabela[hash] == x) resp = true;
        else {
            int rehash = reh(x);
            if(tabela[rehash] == x) resp = true;
        }
        return resp;
    }

    public void mostrar() {
        for(int i = 0; i < tam; i++) {
            System.out.print(tabela[i] + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String args[]) {
        Hash h = new Hash(7);
        h.inserir(5);
        h.inserir(7);
        h.inserir(14);
        h.inserir(21);
        h.inserir(19);
        h.inserir(1);
        h.mostrar();
        h.pesquisar(13);
    }
}