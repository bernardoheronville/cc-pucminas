import java.util.Scanner;
 
class Pilha {
   private String array[];
   private int topo = -1;

   public Pilha() {
       array = new String[100];
   }

   public Pilha(int tam) {
       array = new String[tam];
   }

   public void inserirFinal(String str) {
       topo++;
       array[topo] = str;
   }

   public void removerFinal() {
       topo--;
   }

   public int resolve() {
    int[] aux = new int[100];
    int topoAux = -1;

    for (int i = 0; i <= topo; i++) {
        String token = array[i];

        if (Main.my_strcmp(token, "0") || Main.my_strcmp(token, "1")) {
            topoAux++;
            aux[topoAux] = Integer.parseInt(token);
        } 
        else if (Main.my_strcmp(token, "not")) {
            int a = aux[topoAux--];
            topoAux++;
            aux[topoAux] = (a == 0 ? 1 : 0);
        } 
        else if (Main.my_strcmp(token, "and")) {
            int b = aux[topoAux--];
            int a = aux[topoAux--];
            topoAux++;
            aux[topoAux] = (a == 1 && b == 1 ? 1 : 0);
        } 
        else if (Main.my_strcmp(token, "or")) {
            int b = aux[topoAux--];
            int a = aux[topoAux--];
            topoAux++;
            aux[topoAux] = (a == 1 || b == 1 ? 1 : 0);
        }
    }

    return aux[topoAux]; 
	}


   public void mostrar() {
       for(int i = 0; i <= topo; i++) {
           System.out.println(array[i]);
       }
   }
}
    public class Main {
        // Funcao para retornar true or false se as string sao iguais.
        public static boolean my_strcmp(String frase1, String frase2) {
            boolean resp = true;
            if(frase1.length() == frase2.length()) {
                for(int i = 0; i < frase1.length(); i++) {
                    if(frase1.charAt(i) != frase2.charAt(i)) {
                        resp = false;
                        i = frase1.length();
                    }
                }
            }
            else {
                resp = false;
            }
            return resp;
        }
       
        // Funcao para formatar
        public static String formatacao(String frase, int vals[]) {
            String formatado = new String();
            formatado = "";
            for(int i = 0, j = 0; i < frase.length(); i++) {
                char caracter = frase.charAt(i);
                if(caracter != ' ' && caracter != ',') {
                    if(!(caracter >= 'A' && caracter <= 'Z')) {
                        formatado += caracter;
                    }
                    else {
                        formatado += vals[j];
                        j++;
                    }
                }
            }
			return formatado;
        }

		public static void separador(String str, Pilha pilha) {
    		int i = 0;
    		String aux = "";
   			while (i < str.length()) {
        		char c = str.charAt(i);
       			if (c >= 'a' && c <= 'z') { 
            		aux += c;
            		if (my_strcmp(aux, "and") || my_strcmp(aux, "not") || my_strcmp(aux, "or")) {
						pilha.inserirFinal(aux);
                		aux = ""; 
           	 		}
        		}
				else if (c == '0' || c == '1') {
            		pilha.inserirFinal(String.valueOf(c));
        		} 
        		i++;
    		}
		}

   
        public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);
			Pilha pilha = new Pilha();
            int n = sc.nextInt();
            int vals[] = new int[n];
            for(int i = 0; i < n; i++) {
                vals[i] = sc.nextInt();
            }
            String frase = new String();
            frase = sc.nextLine();
            frase = formatacao(frase, vals);
			separador(frase, pilha);
			System.out.println(pilha.resolve());
            sc.close();
        }
    }