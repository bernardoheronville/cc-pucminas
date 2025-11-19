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

    private No balancear(No no) {
        if(no != null) {
            no.setNivel();
            int fator = no.getFator();
            if(fator == 2) {
                int fatorDir = no.dir.getFator();
                if(fatorDir == -1) {
                    no.dir = rotacionarDir(no.dir);
                }
                return rotacionarEsq(no);
            }
            else if(fator == -2) {
                int fatorEsq = no.esq.getFator();
                if(fatorEsq == 1) {
                    no.esq = rotacionarEsq(no.esq);
                }
                return rotacionarDir(no);
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
}

public class Main {
    public static void main(String args[]) {

    }
}