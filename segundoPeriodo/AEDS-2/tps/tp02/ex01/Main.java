import java.util.Scanner;

class Pilha {
    private String array[];
    private int topo = -1;

    public Pilha() {
        this(200); 
    }

    public Pilha(int tam) {
        array = new String[tam];
    }

    public void inserirFinal(String str) {
        if (topo < array.length - 1) {
            topo++;
            array[topo] = str;
        }
    }

    public void removerFinal() {
        if (topo >= 0) {
            topo--;
        }
    }

    public int resolve() {
        int[] aux = new int[200];
        int topoAux = -1;

        for (int i = 0; i <= topo; i++) {
            String elemento = array[i];

            if (Main.my_strcmp(elemento, "0") || Main.my_strcmp(elemento, "1")) {
                topoAux++;
                aux[topoAux] = Integer.parseInt(elemento);
            } else if (Main.my_strcmp(elemento, "not")) {
                int operando = aux[topoAux--];
                topoAux++;
                if (operando == 0) {
                    aux[topoAux] = 1;
                } else {
                    aux[topoAux] = 0;
                }
            } else {
            int op2 = aux[topoAux--]; 
            int op1 = aux[topoAux--]; 
            int resultado = 0;
            if (Main.my_strcmp(elemento, "and")) {
                if (op1 == 1 && op2 == 1) {
                    resultado = 1;
                } else {
                    resultado = 0;
                }
            } else if (Main.my_strcmp(elemento, "or")) {
                if (op1 == 1 || op2 == 1) {
                    resultado = 1;
                } else {
                    resultado = 0;
                }
            }
            topoAux++;
            aux[topoAux] = resultado;
        }
    }
    return aux[topoAux];
}

    public void mostrar() {
        for (int i = 0; i <= topo; i++) {
            System.out.println(array[i]);
        }
    }
}

public class Main {
    
    // Funcao para retornar true or false se as string sao iguais.
	public static boolean my_strcmp(String palavra1, String palavra2) {
		boolean resp = true;
		if(palavra1.length() == palavra2.length()) {
			for(int i = 0; i < palavra1.length(); i++) {
				if(palavra1.charAt(i) != palavra2.charAt(i)) {
					resp = false;
					i = palavra1.length();
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
        String formatado = ""; 
        for(int i = 0, j = 0; i < frase.length(); i++) {
            char caracter = frase.charAt(i);
            if (caracter != ' ' && caracter != ',' && caracter != '(' && caracter != ')') {
                if (!(caracter >= 'A' && caracter <= 'Z')) {
                    formatado += caracter;
                } else {
                    if (j < vals.length) {
                        formatado += vals[j];
                        j++;
                    }
                }
            }
        }
    return formatado;
    }

    // Procedimento para retirar caracteres que nao vao ser usados e trocar os valores pelos indices
    public static void separador(String str, Pilha pilha) {
        int i = 0;
        while (i < str.length()) {
            char c = str.charAt(i);
            if (c >= 'a' && c <= 'z') {
                String aux = "";
                while (i < str.length() && str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
                    aux += str.charAt(i);
                    i++;
                }
                pilha.inserirFinal(aux);
            } else if (c == '0' || c == '1') {
                pilha.inserirFinal(String.valueOf(c));
                i++;
            } else {
                i++;
            }
        }
    }

    //Main
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n != 0) {
            int vals[] = new int[n];
            for (int i = 0; i < n; i++) {
                vals[i] = sc.nextInt();
            }
            sc.nextLine();
            String frase = sc.nextLine();
            frase = formatacao(frase, vals);
            Pilha pilha = new Pilha();
            separador(frase, pilha);
            int resultado = pilha.resolve();
            System.out.println(resultado);
            n = sc.nextInt();
        }
        sc.close();
    }
}