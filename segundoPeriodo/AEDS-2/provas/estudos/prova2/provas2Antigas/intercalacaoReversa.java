class CelulaDupla {
    public int elemento;
    public CelulaDupla prox, ant;

    public CelulaDupla() {
        elemento = 0;
        prox = ant = null;
    }
    public CelulaDupla(int x) {
        elemento = x;
        prox = ant = null;
    }
}

CelulaDupla intercalar(CelulaDupla c1, CelulaDupla c2) {
    CelulaDupla nova = new CelulaDupla();
    CelulaDupla ultimo1, ultimo2;
    for(ultimo1 = c1; ultimo1.prox != null; ultimo1 = ultimo1.prox);
    for(ultimo2 = c2; ultimo2.prox != null; ultimo2 = ultimo2.prox);
    CelulaDupla tmp = nova;
    while(ultimo1 != c1 || ultimo2 != c2) {
        if(ultimo1 != c1) {
            tmp.prox = new CelulaDupla(ultimo1.elemento);
            tmp.prox.ant = tmp;
            tmp = tmp.prox;
            ultimo1 = ultimo1.ant;
        }
        if(ultimo2 != c2) {
            tmp.prox = new CelulaDupla(ultimo2.elemento);
            tmp.prox.ant = tmp;
            tmp = tmp.prox;
            ultimo2 = ultimo2.ant;
        }
    }
    tmp = null;
    return nova;
}