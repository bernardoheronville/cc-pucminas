class Celula {
    public String palavra;
    public Celula prox;
    public Celula(String x) { palavra = x; prox = null; }
}

class No {
    public char letra;
    public No esq, dir;
    public Celula primeiro, ultimo;
    public No(char c) {
        letra = c; esq = dir = null;
        primeiro = ultimo = null;
    }
}

class Dicionario {
    private No raiz;

    public Dicionario() { raiz = null; }

    private No inserirNo(No i, char c) {
        if (i == null) return new No(c);
        if (c < i.letra) i.esq = inserirNo(i.esq, c);
        else if (c > i.letra) i.dir = inserirNo(i.dir, c);
        return i;
    }

    private No buscarNo(No i, char c) {
        if (i == null) return null;
        if (c == i.letra) return i;
        if (c < i.letra) return buscarNo(i.esq, c);
        else return buscarNo(i.dir, c);
    }

    private void inserirLista(No no, String palavra) {
        Celula nova = new Celula(palavra);
        if (no.primeiro == null) {
            no.primeiro = no.ultimo = nova;
            return;
        }
        Celula ant = null, atual = no.primeiro;
        while (atual != null && palavra.compareTo(atual.palavra) > 0) {
            ant = atual;
            atual = atual.prox;
        }
        if (ant == null) {
            nova.prox = no.primeiro;
            no.primeiro = nova;
        } else if (atual == null) {
            no.ultimo.prox = nova;
            no.ultimo = nova;
        } else {
            ant.prox = nova;
            nova.prox = atual;
        }
    }

    public void inserir(String palavra) {
        raiz = inserirNo(raiz, palavra.charAt(0));
        No no = buscarNo(raiz, palavra.charAt(0));
        inserirLista(no, palavra);
    }
}