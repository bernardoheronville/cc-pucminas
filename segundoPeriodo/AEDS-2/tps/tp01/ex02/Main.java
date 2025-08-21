import java.util.Scanner;

public class Main {
	public static boolean palindromo(String palavra, int inicio, int fim) {
		if(inicio > fim) return true;
		else if(palavra.charAt(inicio) != palavra.charAt(fim)) return false;
		else {
			return palindromo(palavra, inicio + 1, fim - 1);
		}
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String palavra = sc.nextLine();
		while(!palavra.equals("FIM")) {
			if(palindromo(palavra, 0, palavra.length() - 1)) {
				System.out.println("SIM");
			}
			else {
				System.out.println("NAO");
			}
			palavra = sc.nextLine();
		}
		
	}
}
