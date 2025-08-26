import java.util.Scanner; // Importando a biblioteca scanner

// Class Main
public class Main { 

	// Funcao para retorna true or false se a string eh um palindromo
	public static boolean palindromo(String palavra) {
		int inicio = 0, fim = palavra.length() - 1;
		boolean resp = true;
		while(inicio < fim) {
			if(palavra.charAt(inicio) != palavra.charAt(fim)) {
				resp = false;
				inicio = fim;
			}
			else {
				inicio++;
				fim--;
			}
		}
		return resp;
	}

	// Funcao para retornar true or false se as string sao iguais
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

	// Main
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String palavra = new String();
		palavra = sc.nextLine();
		while(!my_strcmp(palavra, "FIM")) {
			if(palindromo(palavra)) {
				System.out.println("SIM");
			}
			else {
				System.out.println("NAO");
			}
			palavra = sc.nextLine();
		}
		sc.close(); 
	}
}
