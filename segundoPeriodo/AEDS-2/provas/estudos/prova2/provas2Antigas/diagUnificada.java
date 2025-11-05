class Matriz {
    CelulaMatriz inicio;
    int linha , coluna;
    CelulaDupla diagUnificada() {
        if(linha != coluna || inicio == null) throw new IllegalArgumentException("ERRO!");
        CelulaMatriz i = inicio;
        CelulaDupla nova = new CelulaDupla(0);
        CelulaDupla aux = nova;
        for(Celula tmp = i.inicio.prox; tmp != null; tmp = tmp.prox) {
                aux.prox = new CelulaDupla(tmp.elemento);
                aux.prox.ant = aux;
                aux = aux.prox;
        }
        while(i.inf != null) {
            i = i.inf.prox;
            for(Celula tmp = i.inicio.prox; tmp != null; tmp = tmp.prox) {
                aux.prox = new CelulaDupla(tmp.elemento);
                aux.prox.ant = aux;
                aux = aux.prox;
            } 
        }
        return nova;
    }
}

class CelulaMatriz {
    public CelulaMatriz sup, inf, prox, ant;
    Celula inicio, fim;
}
class Celula {
    int elemento;
    Celula prox;
}
class CelulaDupla {
    int elemento;
    CelulaDupla prox, ant;

    public CelulaDupla(int x) {
        elemento = x;
        prox = ant = null;
    }
}