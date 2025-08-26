import java.util.*; // Importando biblioteca Scanner e Random

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

	// Funcao que substitui todas as ocorrências da primeira letra na string pela segunda e retorna a string com as alterações efetuadas
	public static String alteracao(String frase, char letra1, char letra2) {
		char[] novaFrase = new char[frase.length()];
		for(int i = 0; i < frase.length(); i++) {
			if(frase.charAt(i) == letra1) novaFrase[i] = letra2;
			else novaFrase[i] = frase.charAt(i);
		}
		String resp = new String(novaFrase);
		return resp;
	}

	// Main
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		Random gerador = new Random();
		gerador.setSeed(4);
		String frase = new String();
		frase = sc.nextLine();
		while(!my_strcmp(frase, "FIM")) {
			char letra1 = ((char)('a' + (Math.abs(gerador.nextInt()) % 26)));
      		char letra2 = ((char)('a' + (Math.abs(gerador.nextInt()) % 26)));
			System.out.println(alteracao(frase, letra1, letra2));
			frase = sc.nextLine();
		}
		sc.close();
	}
}