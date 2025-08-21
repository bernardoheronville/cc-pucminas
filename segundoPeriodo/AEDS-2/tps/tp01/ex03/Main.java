import java.util.Scanner;
import java.io.InputStreamReader;

public class Main {
	public static void ciframento(String palavra) {
		int tam = palavra.length();
		String novaPalavra = "";
		for(int i = 0; i < tam; i++) {
			char caractereAtual = palavra.charAt(i);
			if(caractereAtual == '\uFFFD')
				novaPalavra += caractereAtual;
			else {
				char novoCaracter = (char) (caractereAtual + 3);
				novaPalavra += novoCaracter;
			}
		}
		System.out.println(novaPalavra);
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(new InputStreamReader(System.in, java.nio.charset.StandardCharsets.UTF_8));
		String palavra = sc.nextLine();
		while(!palavra.equals("FIM")) {
			ciframento(palavra);
			palavra = sc.nextLine();
		}
		sc.close();
	}
}
