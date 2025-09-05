import java.util.Scanner;

public class Main {
    
    // Substitui letras maiúsculas pelos valores e retira espacos e virgulas.
    public static String formatacao(String frase, int vals[]) {
        String formatado = "";
        for(int i = 0; i < frase.length(); i++) {
            char c = frase.charAt(i);
            if(c != ' ' && c != ',') {
                if(c >= 'A' && c <= 'Z') {
                        formatado += vals[c - 'A'];
                } 
                else {
                    formatado += c;
                }
            }
        }
        return formatado;
    }

    // Extrai o operador (not, and, or) antes do '('.
    public static String extracaoOperadores(String frase, int index) {
        String str = "";
        while(index > 0 && frase.charAt(index - 1) >= 'a' && frase.charAt(index - 1) <= 'z') {
            index--;
            str += frase.charAt(index);
        }
        String operadores = "";
        for(int j = str.length() - 1; j >= 0; j--) {
            operadores += str.charAt(j);
        }
        return operadores;
    }

    // Extrai os parâmetros (0 ou 1) dentro dos parênteses.
    public static int[] extracaoParametros(String frase, int index) {
        String str = "";
        while(index < frase.length() - 1 && frase.charAt(index + 1) != ')') {
            index++;
            char c = frase.charAt(index);
            if (c == '0' || c == '1') {
                str += c;
            }
        }
        int params[] = new int[str.length()];
        for(int i = 0; i < str.length(); i++) {
            params[i] = str.charAt(i) - '0';
        }
        return params;
    }

    // Atualiza a expressão substituindo a subexpressão pelos resultados.
    public static String atualizar(String frase, int index, String atr) {
        String str = "";
        for(int i = 0; i < index; i++) {
            str += frase.charAt(i);
        }
        for(int i = index; i < frase.length(); i++) {
            if(frase.charAt(i) == ')') {
                str += atr;
                i++;
                while(i < frase.length()) {
                    str += frase.charAt(i);
                    i++;
                }
            }
        }
        return str;
    }

    // Resolve a operação booleana (not, and, or).
    public static int resolver(String operator, int[] params) {
        int resp = 0;
        switch(operator) {
            case "not":
                if(params[0] == 1) {
                    resp = 0;
                }
                else {
                    resp = 1;
                }
                break;
            case "or":
                resp = 0;
                for(int i = 0; i < params.length; i++) {
                    if (params[i] == 1) {
                        resp = 1;
                        i = params.length;
                    }
                }
                break;
            case "and":
                resp = 1;
                for(int i = 0; i < params.length; i++) {
                    if (params[i] == 0) {
                        resp = 0;
                        i = params.length;
                    }
                }
                break;
        }
        return resp;
    }

    //Main
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n != 0) {
            int valores[] = new int[n];
            for(int i = 0; i < n; i++) {
                valores[i] = sc.nextInt();
            }
            String linha = sc.nextLine();
            String expressao = formatacao(linha, valores);
            for(int i = expressao.length() - 1; i >= 0; i--) {
                if(expressao.charAt(i) == '(') {
                    String operador = extracaoOperadores(expressao, i);
                    int params[] = extracaoParametros(expressao, i);
                    i -= operador.length(); 
                    expressao = atualizar(expressao, i, Integer.toString(resolver(operador, params)));
                }
            }
            System.out.println(expressao);
            n = sc.nextInt();
        }
        sc.close();
    }
}
