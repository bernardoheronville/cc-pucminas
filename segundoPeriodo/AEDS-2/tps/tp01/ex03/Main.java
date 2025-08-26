import java.util.Scanner; // Importando biblioteca scanner

// Classe Main
public class Main {

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

	// Procedimento que substitui o caractere por + 3 na tabela ASCII
	public static String ciframento(String palavra) {
		char[] novaPalavra = new char[palavra.length()];
		for(int i = 0; i < palavra.length(); i++) {
			char caractereAtual = palavra.charAt(i);
			if(caractereAtual >= 0 && caractereAtual <= 126) {
				char novoCaracter = (char) (caractereAtual + 3);
				novaPalavra[i] = novoCaracter;
			}
			else {
				novaPalavra[i] = caractereAtual;
			}
		}
		String resp = new String(novaPalavra);
		return resp;
	}

	// Main
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String palavra = new String();
		palavra = sc.nextLine();
		while(!my_strcmp(palavra, "FIM")) {
			System.out.println(ciframento(palavra));
			palavra = sc.nextLine();
		}
		sc.close();
	}
}