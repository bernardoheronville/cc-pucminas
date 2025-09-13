import java.util.Scanner;

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

    // Funcao recursiva que recebe um número inteiro como parâmetro e retorna a soma de seus dígitos.
    public static int somaDigitos(String entrada, int resp, int i) {
        char caracter = entrada.charAt(i);
        if(i == 0) resp += (caracter - '0');
        else resp += (caracter - '0' + somaDigitos(entrada, resp, i - 1));
        return resp;
    }

    // Funcao auxiliar para a soma.
    public static int auxSomaDigitos(String entrada) {
        int resp = 0;
        return somaDigitos(entrada, resp, entrada.length() - 1);
    }

    // Main
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String entrada = new String();
        entrada = sc.nextLine();
        while(!my_strcmp(entrada, "FIM")) {
            System.out.println(auxSomaDigitos(entrada));
            entrada = sc.nextLine();
        }
        sc.close();
    }
}