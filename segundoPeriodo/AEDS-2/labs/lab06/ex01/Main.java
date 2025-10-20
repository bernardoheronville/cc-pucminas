package ex01;

class Celula {
    public int elemento;
    public Celula prox;

    public Celula() {
        this.elemento = 0;
        this.prox = null;
    }
    public Celula(int x) {
        this.elemento = x;
        this.prox = null;
    }
}

class Lista {
    private Celula primeiro;
    private Celula ultimo;

    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserirInicio(int x) {
        primeiro.elemento = x;
        Celula tmp = new Celula();
        tmp.prox = primeiro;
        primeiro = tmp;
        tmp = null;
    }
    public void inserirFim(int x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }
    public void inserir(int x, int pos) throws Exception {

      int tamanho = tamanho();

      if(pos < 0 || pos > tamanho){
			throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
      } else if (pos == 0){
         inserirInicio(x);
      } else if (pos == tamanho){
         inserirFim(x);
      } else {
		   // Caminhar ate a posicao anterior a insercao
         Celula i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
		
         Celula tmp = new Celula(x);
         tmp.prox = i.prox;
         i.prox = tmp;
         tmp = i = null;
      }
   }

    public int removerInicio() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        Celula tmp = primeiro.prox;
        primeiro.prox = tmp.prox;
        int resp = tmp.elemento;
        tmp.prox = null;
        tmp = null;
        return resp;
    }
    public int removerFim() {
        if(primeiro == ultimo) {
            throw new IllegalArgumentException("Lista vazia");
        }
        Celula i;
        for(i = primeiro.prox; i.prox != ultimo; i = i.prox);
        ultimo = i;
        i = i.prox;
        int resp = i.elemento;
        ultimo.prox = null;
        i = null;
        return resp;
    }
    public int remover(int pos) throws Exception {
      int resp;
      int tamanho = tamanho();

		if (primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");

      } else if(pos < 0 || pos >= tamanho){
			throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
      } else if (pos == 0){
         resp = removerInicio();
      } else if (pos == tamanho - 1){
         resp = removerFim();
      } else {
		   // Caminhar ate a posicao anterior a insercao
         Celula i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
		
         Celula tmp = i.prox;
         resp = tmp.elemento;
         i.prox = tmp.prox;
         tmp.prox = null;
         i = tmp = null;
      }

		return resp;
	}

    public int tamanho() {
      int tamanho = 0; 
      for(Celula i = primeiro; i != ultimo; i = i.prox, tamanho++);
      return tamanho;
   }

    public void mostrar() {
        for(Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.printf("%d ", i.elemento);
        }
        System.out.printf("\n");
    }
}


public class Main {
    public static void clone(Lista l1, Lista l3) {
        Celula i = l1.primeiro;
        for(; i != null; i = i.prox) {
            l2.inserirFim(i.elemento);
        }
    }
    public static void main(String args[]) {
        Lista lista1 = new Lista();
        Lista lista2 = new Lista();
        Lista lista3 = new Lista();

    }
}