class No {
    public int elemento;
    public int nivel;
    public No esq;
    public No dir;

    public No() {
        elemento = 0;
        nivel = 1;
        esq = dir = null;
    }
    public No(int x) {
        elemento = x;
        nivel = 1;
        esq = dir = null;
    }

    public int getNivel(No no) {
        if(no == null) return 0;
        else return no.nivel;
    }
    public int getFator() {
        return getNivel(dir) - getNivel(esq);
    }

    public void setNivel() {
		nivel = 1 + Math.max(getNivel(esq), getNivel(dir));
	}
}

class ArvoreAVL {
    public No raiz;

    public ArvoreAVL() {
        raiz = null;
    }

    public void inserir(int x) {
        raiz = inserir(x, raiz);
    }
    private No inserir(int x, No i) {
        if(i == null) i = new No(x);
        else if(x > i.elemento) i.dir = inserir(x, i.dir);
        else if(x < i.elemento) i.esq = inserir(x, i.esq);
        else {
            throw new IllegalArgumentException("ERRO");
        }
        return balancear(i);
    }

    public void remover(int x) {
        raiz = remover(x, raiz);
    }
    private No remover(int x, No i) {
        if(i == null) return null;
        else if(x > i.elemento) i.dir = remover(x, i.dir);
        else if(x < i.elemento) i.esq = remover(x, i.esq);
        else {
            if(i.dir == null) i = i.esq;
            else if(i.esq == null) i = i.dir;
            else {
                i.elemento = getMaior(i.esq).elemento;
                i.esq = remover(i.elemento, i.esq);
            }
        }
        return balancear(i);
    }
    private No getMaior(No i) {
        while(i.dir != null) {
            i = i.dir;
        }
        return i;
    }

    public void pesquisar(int x) {
        if(pesquisar(x, raiz)) {
            System.out.println("Elemento " + x + " encontrado");
        }
        else {
            System.out.println("Elemento " + x + " nao encontrado!");
        }
    }
    private boolean pesquisar(int x, No i) {
        boolean resp = false;
        while(i != null) {
            if(x > i.elemento) i = i.dir;
            else if(x < i.elemento) i = i.esq;
            else {
                resp = true;
                i = null;
            }
        }
        return resp;
    }

    private No balancear(No no) {
        if(no != null) {
            no.setNivel();
            int fator = no.getFator();
            if(fator == 2) { // Se desbalanceada para a direita.
                int fatorDir = no.dir.getFator();
                if(fatorDir == -1) { // Se o filho da direita tiver um filho a esquerda.
                    no.dir = rotacionarDir(no.dir); // Rotacao a direita no filho da direita.
                }
                return rotacionarEsq(no); // Rotacao a esquerda no No.
            }
            else if(fator == -2) { // Se desbalanceada para a esquerda.
                int fatorEsq = no.esq.getFator();
                if(fatorEsq == 1) { // Se o filho da esquerda tiver um filho a direita.
                    no.esq = rotacionarEsq(no.esq); // Rotacao a esquerda no filho da esquerda.
                }
                return rotacionarDir(no); // Rotacao a direita no No.
            }
        }
        return no;
    }
    private No rotacionarDir(No no) {
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
        noEsq.dir = no;
        no.esq = noEsqDir;
        no.setNivel();
        noEsq.setNivel();
        return noEsq;
    }
    private No rotacionarEsq(No no) {
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
        noDir.esq = no;
        no.dir = noDirEsq;
        no.setNivel();
        noDir.setNivel();
        return noDir;
    }

    public void caminharCentral() {
        caminharCentral(raiz);
    }
    private void caminharCentral(No i) {
        if(i != null) {
            caminharCentral(i.esq);
            System.out.println(i.elemento);
            caminharCentral(i.dir);
        }
    }
}

public class Main {
    public static void main(String args[]) {
        ArvoreAVL arvore = new ArvoreAVL();
        arvore.inserir(3);
        arvore.inserir(7);
        arvore.inserir(2);
        arvore.inserir(12);
        arvore.inserir(13);
        arvore.inserir(11);
        arvore.inserir(1);
        arvore.caminharCentral();
        arvore.pesquisar(7);
        arvore.remover(3);
        arvore.caminharCentral();
    }
}