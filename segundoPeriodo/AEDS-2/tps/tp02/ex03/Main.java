import java.util.Scanner;

public class Main { // Class Main
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

	// Funcao que recebe uma string como parâmetro e retorna a string invertida. 
	public static String inverteString(String palavra) {
		char invertido[] = new char[palavra.length()];
		for(int i = palavra.length() - 1, j = 0; i >= 0; i--, j++) {
			invertido[j] = palavra.charAt(i);
		}
		return new String(invertido);
	}

	// Main
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String palavra = new String();
		palavra = sc.nextLine();
		while(!my_strcmp(palavra, "FIM")) {
			System.out.println(inverteString(palavra));
			palavra = sc.nextLine();
		}
		sc.close();
	}
}
