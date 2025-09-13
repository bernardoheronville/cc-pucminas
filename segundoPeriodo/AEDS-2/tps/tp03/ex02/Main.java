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

    // Funcao recursiva que recebe uma string como parâmetro e retorna a string invertida.
    public static String inverteString(String palavra, String resp, int i) {
		char caracter = palavra.charAt(i);
        if(i == 0) resp += caracter;
        else resp += (caracter + inverteString(palavra, resp, i - 1));
		return resp;
    }

    // Funcao auxiliar de inverte String.
    public static String auxInverteString(String palavra) {
        String resp = "";
        return inverteString(palavra, resp, palavra.length() - 1);
    }

    // Main
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
		String palavra = new String();
		palavra = sc.nextLine();
		while(!my_strcmp(palavra, "FIM")) {
			System.out.println(auxInverteString(palavra));
			palavra = sc.nextLine();
		}
		sc.close();
    }
}
