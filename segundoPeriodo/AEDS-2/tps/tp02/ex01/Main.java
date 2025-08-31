import java.util.Scanner;

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

	public static void formatacao(String frase, int array[]) {
		String formatado = new String();
		formatado = "";
		for(int i = 0, j = 0; i < frase.length(); i++) {
			char caracter = frase.charAt(i);
			if(caracter != ' ' && caracter != ',') {
				if(!(caracter >= 'A' && caracter <= 'Z')) {
					formatado += caracter;
				}
				else {
					formatado += array[j];
					j++;
				}
			}
		}
		System.out.println(formatado);
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int array[] = new int[n];
		for(int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		String frase = new String();
		frase = sc.nextLine();
		formatacao(frase, array);
		sc.close();
	}
}
