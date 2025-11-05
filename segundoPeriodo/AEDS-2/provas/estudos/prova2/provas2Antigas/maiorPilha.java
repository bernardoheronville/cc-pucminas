class Lista {
    CelulaLista inicio;
    CelulaLista fim;

    public CelulaLista maiorPilha() {
        CelulaLista maior = inicio;
        int maiorNum = -1;
        for(CelulaLista i = inicio; i != null; i = i.prox) {
            int count = 0;
            for(CelulaPilha j = i.topo; j != null; j = j.prox) {
                count++;
            }
            if(count > maiorNum) {
                maiorNum = count;
                maior = i;
            }
        }
        return maior;
    }
}
class CelulaLista {
    CelulaPilha topo;
    CelulaLista prox;
}
class CelulaPilha {
    int elemento;
    CelulaPilha prox;
}


