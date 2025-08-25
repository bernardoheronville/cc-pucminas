import java.util.*;

public class Main {
	public static String alteracao(String frase, char letra1, char letra2) {
		String novaFrase = new String();
		novaFrase = "";
		for(int i = 0; i < frase.length(); i++) {
			char caracter = frase.charAt(i);
			if(caracter == letra1) novaFrase += letra2;
			else novaFrase += caracter;
		}
		return novaFrase;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		Random gerador = new Random();
		gerador.setSeed(4);
		String frase = new String();
		frase = sc.nextLine();
		while(!frase.equals("FIM")) {
			char letra1 = ((char)('a' + (Math.abs(gerador.nextInt()) % 26)));
      			char letra2 = ((char)('a' + (Math.abs(gerador.nextInt()) % 26)));
			System.out.println(alteracao(frase, letra1, letra2));
			frase = sc.nextLine();
		}
		sc.close();
	}
}
