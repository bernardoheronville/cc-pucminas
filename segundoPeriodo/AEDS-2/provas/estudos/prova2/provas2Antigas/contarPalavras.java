class ArvoreArvore {
    No raiz;
    public int contarPalavras(char primeiro, char ultimo) {
        int count = 0;
        No i = raiz;
        while(i != null) {
            if(primeiro > i.letra) i = i.dir;
            else if(primeiro < i.letra) i = i.esq;
            else break;
        }
        if(i != null) {
            count = contarPalavrasAux(i.raiz, primeiro, ultimo); 
        }
        return count;
    }

    private int contarPalavrasAux(No2 i, char primeiro, char ultimo) {
        int count = 0;
        if(i != null) {
            if(i.palavra.charAt(0) == primeiro && i.palavra.charAt(i.palavra.length() - 1) == ultimo) count++;
            count += contarPalavrasAux(i.dir, primeiro, ultimo);
            count += contarPalavrasAux(i.esq, primeiro, ultimo);
        }
        return count;
    }
}
class No {
    char letra;
    No esq, dir;
    No2 raiz;
}
class No2 {
    String palavra;
    No2 esq, dir;
}

