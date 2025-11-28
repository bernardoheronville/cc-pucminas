class No {
    public int elemento;
    public No esq, dir;
    public boolean cor;

    public No() {
        this.elemento = 0;
        this.esq = this.dir = null;
        this.cor = true;
    } 
    public No(int x) {
        this.elemento = x;
        this.esq = this.dir = null;
        this.cor = true;
    }
}

class Arvore {
    public No raiz;

    public Arvore() {
        raiz = null;
    }

    public void inserir(int x) {
        if(raiz == null) raiz = new No(x);
        else if(raiz.dir == null && raiz.esq == null) {
            if(x > raiz.elemento) raiz.dir = new No(x);
            else raiz.esq = new No(x);
        }
        else if(raiz.dir == null) {
            if(x > raiz.elemento) raiz.dir = new No(x);
            else if(x < raiz.esq.elemento) {
                raiz.dir = new No(raiz.elemento);
                raiz.elemento = raiz.esq.elemento;
                raiz.esq.elemento = x;
            }
            else {
                raiz.dir = new No(raiz.elemento);
                raiz.elemento = x;
            }
        }
        else if(raiz.esq == null) {
            if(x < raiz.elemento) raiz.esq = new No(x);
            else if(x > raiz.dir.elemento) {
                raiz.esq = new No(raiz.elemento);
                raiz.elemento = raiz.dir.elemento;
                raiz.dir.elemento = x;
            }
            else {
                raiz.esq = new No(raiz.elemento);
                raiz.elemento = x;
            }
        }
        else {
            inserir(x, null, null, null, raiz);
        }
        raiz.cor = false;
    }
    private void inserir(int x, No bisavo, No avo, No pai, No no) {
        if(no == null) {
            if(x > pai.elemento) no = pai.dir = new No(x);
            else no = pai.esq = new No(x);
            if(pai.cor == true) balancear(bisavo, avo, pai, no);
        }
        else {
            // Achou um 4 no
            if(inNoTipoQuatro(no)) {
                fragmentar(no);
                if(no == raiz) {
                    raiz.cor = false;
                }
                else if(pai.cor == true) {  
                    balancear(bisavo, avo, pai, no);
                }
            }
            if(x > no.elemento) {
                inserir(x, avo, pai, no, no.dir);
            }
            else if(x < no.elemento) {
                inserir(x, avo, pai, no, no.esq);
            }
            else {
                throw new IllegalArgumentException("Elemento repetido");
            }
        }
    }
    private void balancear(No bisavo, No avo, No pai, No no) {
        if(pai.cor == true) {
            if(pai.elemento > avo.elemento) {
                if(no.elemento > pai.elemento) {
                    avo = rotacionarEsq(avo); // Rotacao a esquerda no avo.
                }
                else {
                   avo.dir = rotacionarDir(avo.dir); // Rotacao a direita no pai.
                   avo = rotacionarEsq(avo); // Rotacao a esquerda no avo.
                }
            }
            else {
                if(no.elemento < pai.elemento) {
                    avo = rotacionarDir(avo); // Rotacao a direita no avo.
                }
                else {
                    avo.esq = rotacionarEsq(avo.esq); // Rotacao a esquerda no pai.
                    avo = rotacionarDir(avo); // Rotacao a direita no avo.
                }
            }
            if(bisavo == null) {
                raiz = avo;
            } 
            else if(avo.elemento < bisavo.elemento) {
                bisavo.esq = avo;
            } 
            else {
                bisavo.dir = avo;
            }
            avo.cor = false;
            avo.esq.cor = avo.dir.cor = true;
        }
    }
    private boolean inNoTipoQuatro(No no) {
        return (no.dir != null && no.esq != null && no.dir.cor == true && no.esq.cor == true);
    }
    private void fragmentar(No no) {
        no.cor = true;
        no.esq.cor = no.dir.cor = false;
    }
    private No rotacionarEsq(No no) {
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
        noDir.esq = no;
        no.dir = noDirEsq;
        return noDir;
    }
    private No rotacionarDir(No no) {
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
        noEsq.dir = no;
        no.esq = noEsqDir;
        return noEsq;
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

    public void caminharCentral() {
        caminharCentral(raiz);
    }
    public void caminharCentral(No i) {
        if(i != null) {
            caminharCentral(i.esq);
            System.out.println(i.elemento);
            caminharCentral(i.dir);
        }
    }
}

public class Main {
    public static void main(String args[]) {
        Arvore arvore = new Arvore();
        arvore.inserir(4);
        arvore.inserir(35);
        arvore.inserir(10);
        arvore.inserir(13);
        arvore.inserir(3);
        arvore.inserir(30);
        arvore.inserir(15);
        arvore.inserir(12);
        arvore.caminharCentral();
        arvore.pesquisar(3);
    }
}