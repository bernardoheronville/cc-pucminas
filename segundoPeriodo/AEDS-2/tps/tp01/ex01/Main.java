import java.util.Scanner; // importando a biblioteca scanner

public class Main { // class main

	//funcao para retorna true or false se a string eh um palindromo
	public static boolean palindromo(String palavra) {
		int inicio = 0, fim = palavra.length() - 1;
		while(inicio < fim) {
			if(palavra.charAt(inicio) != palavra.charAt(fim)) {
				return false;
			}
			inicio++;
			fim--;
		}
		return true;
	}

	// main
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String palavra = sc.nextLine();
		while(!palavra.equals("FIM")) {
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
