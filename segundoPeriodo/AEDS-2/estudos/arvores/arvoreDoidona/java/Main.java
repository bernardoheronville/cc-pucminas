class T1 {
    public int tabela[];
    T2 t2;
    public int tam;

    public T1() {
        tam = 5;
        tabela = new int[tam];
        for(int i = 0; i < tam; i++) tabela[i] = -1;
        t2 = new T2();
    }

    public int h1(int x) {
        return x % tam;
    }

    public void inserir(int x) {
        int pos = h1(x);
        if(tabela[pos] == -1) tabela[pos] = x;
        else t2.inserir(x);
    }

    public boolean pesquisar(int x) {
        int pos = h1(x);
        if(tabela[pos] == -1) return false;
        else if(tabela[pos] == x) return true;
        else return t2.pesquisar(x);
    }

    public void mostrar() {
        System.out.println("Elementos de T1");
        for(int i = 0; i < tam; i++) {
            System.out.print(tabela[i] + " ");
        }
        System.out.println();
        t2.mostrar();
    }
}
class T2 {
    T3 t3;
    Lista lista;
    Arvore arvore;

    public T2() {
        t3 = new T3();
        lista = new Lista();
        arvore = new Arvore();
    }

    public int h2(int x) {
        return x % 3;
    }

    public void inserir(int x) {
        int pos = h2(x);
        if(pos == 0) t3.inserir(x);
        else if(pos == 1) lista.inserir(x);
        else arvore.inserir(x);
    }

    public boolean pesquisar(int x) {
        int pos = h2(x);
        if(pos == 0) return t3.pesquisar(x);
        else if(pos == 1) return lista.pesquisar(x);
        else return arvore.pesquisar(x);
    }

    public void mostrar() {
        t3.mostrar();
        lista.mostrar();
        System.out.println("Elementos da arvore da T1");
        arvore.mostrar();
    }
}
class T3 {
    int tabela[];
    Arvore arvore3;
    int tam;

    public T3() {
        tam = 5;
        tabela = new int[tam];
        for(int i = 0; i < tam; i++) tabela[i] = -1;
        arvore3 = new Arvore();
    }

    public int h3(int x) {
        return x % tam;
    }
    public int res3(int x) {
        return ++x % tam;
    }

    public void inserir(int x) {
        int pos = h3(x);
        if(tabela[pos] == -1) tabela[pos] = x;
        else {
            int res = res3(x);
            if(tabela[res] == -1) tabela[res] = x;
            else arvore3.inserir(x);
        }
    }

    public boolean pesquisar(int x) {
        int pos = h3(x);
        if(tabela[pos] == -1) return false;
        else if(tabela[pos] == x) return true;
        else {
            int res = res3(x);
            if(tabela[res] == x) return true;
            else return arvore3.pesquisar(x);
        }
    }

    public void mostrar() {
        System.out.println("Elementos de T3");
        for(int i = 0; i < tam; i++) {
            System.out.print(tabela[i] + " ");
        }
        System.out.println();
        System.out.println("Elementos da arvore da T3");
        arvore3.mostrar();
    }
}

class No {
    int elemento;
    No esq, dir;

    public No(int x) {
        elemento = x;
        esq = dir = null;
    }
    public No() {
        elemento = 0;
        esq = dir = null;
    }
}
class Arvore {
    No raiz;

    public Arvore() {
        raiz = null;
    }

    public void inserir(int x) {
        raiz = inserir(x, raiz);
    }
    private No inserir(int x, No i) {
        if(i == null) i = new No(x);
        else if(x > i.elemento) i.dir = inserir(x, i.dir);
        else if(x < i.elemento) i.esq = inserir(x, i.esq);
        else;
        return i;
    }
    
    public boolean pesquisar(int x) {
        No i = raiz;
        while(i != null) {
            if(x > i.elemento) i = i.dir;
            else if(x < i.elemento) i = i.esq;
            else {
                return true;
            }
        }
        return false;
    }

    public void mostrar() {
        mostrar(raiz);
        System.out.println();
    }
    public void mostrar(No i) {
        if(i != null) {
            mostrar(i.esq);
            System.out.printf("%d ", i.elemento);
            mostrar(i.dir);
        }
    }
}

class Celula {
    int elemento;
    Celula prox;

    public Celula(int x) {
        elemento = x;
        prox = null;
    }
    public Celula() {
        elemento = 0;
        prox = null;
    }
}
class Lista {
    Celula primeiro;
    Celula ultimo;

    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserir(int x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public boolean pesquisar(int x) {
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            if(x == i.elemento) return true;
        }
        return false;
    }

    public void mostrar() {
        System.out.println("Elementos da lista");
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.printf("%d ", i.elemento);
        }
        System.out.printf("\n");
    }
}

class Doidona {
    T1 t1;

    public Doidona() {
        t1 = new T1();
    }

    public void inserir(int x) {
        t1.inserir(x);
    }

    public void mostrar() {
        t1.mostrar();
    }

    public void pesquisar(int x) {
        if(t1.pesquisar(x)) {
            System.out.println("Elemento " + x + " encontrado!");
        }
        else {
            System.out.println("Elemento " + x + " nao encontrado!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[] elementos = {0, 1, 2, 3, 4, 10, 16, 5, 8, 15, 30, 45};
        Doidona doidona = new Doidona();
        for(int i = 0; i < elementos.length; i++) {
            doidona.inserir(elementos[i]);
        }
        doidona.mostrar();
        doidona.pesquisar(77);
    }
}
