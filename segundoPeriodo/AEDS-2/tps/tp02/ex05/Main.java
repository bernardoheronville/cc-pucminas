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

    // FUncao que retorna uma String com todas as letras minusculas
    public static String minusculo(String palavra) {
        char palavraMinuscula[] = new char[palavra.length()];
        for(int i = 0; i < palavra.length(); i++) {
            if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z') {
                palavraMinuscula[i] = (char)(palavra.charAt(i) + 32);
            }
            else {
                palavraMinuscula[i] = palavra.charAt(i);
            }
        }
        return new String(palavraMinuscula);
    }

    // Separador que retorna palavra1 se aux == 1 e palavra2 se aux == 2
    public static String separador(String linha, int aux) {
        char[] palavra1 = new char[256];
        char[] palavra2 = new char[256];
        int tam1 = 0, tam2 = 0, i = 0;
        while (i < linha.length() && linha.charAt(i) != '-') {
            palavra1[tam1] = linha.charAt(i);
            tam1++;
            i++;
        }
        i++;
        while (i < linha.length()) {
            palavra2[tam2] = linha.charAt(i);
            tam2++;
            i++;
        }
        if (aux == 1) return new String(palavra1, 0, tam1);
        if (aux == 2) return new String(palavra2, 0, tam2);
        return "ERRO";
    }

    // Funcao iterativa que recebe duas strings como parâmetros e retorna true se as strings são anagramas uma da outra
    public static boolean anagrama(String palavra1, String palavra2) {
        boolean resp = true;
        String word1 = minusculo(palavra1);
        String word2 = minusculo(palavra2);
        if(word1.length() == word2.length()) {
            boolean usada[] = new boolean[word1.length()];
            for(int i = 0; i < word1.length(); i++) {
                boolean achou = false;
                for(int j = 0; j < word1.length(); j++) {
                    char letra1 = word1.charAt(i);
                    char letra2 = word2.charAt(j);
                    if(letra1 == letra2 && !usada[j]) {
                        achou = true;
                        usada[j] = true;
                        j = word1.length();
                    }
                }
                if(!achou) {
                    resp = false;
                    i = word1.length();
                }
            }
        }
        else {
            resp = false;
        }
        return resp;
    }

    // Main
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String linha = new String();
        linha = sc.nextLine();
        while(!my_strcmp(linha, "FIM")) {
            String palavra1 = separador(linha, 1);
            String palavra2 = separador(linha, 2);
            if(anagrama(palavra1, palavra2))
                System.out.println("SIM");
            else
                //System.out.println("NÃO"); 
                MyIO.println("NÃO"); // Tive que utilizar por conta do verde nao aceitar o ~
            linha = sc.nextLine();
        }
    sc.close();
    }
}