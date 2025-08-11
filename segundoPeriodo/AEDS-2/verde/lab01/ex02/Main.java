import java.util.Scanner;

public class Main {
	public static int contadorMaiuscula(String palavra, int i) {
		if(i >= palavra.length()) return 0;
		else if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z') return (1+contadorMaiuscula(palavra,i+1));
		else return (contadorMaiuscula(palavra,i+1));
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String palavra = new String();
		palavra = sc.nextLine();
		while(!palavra.equals("FIM")) {
			System.out.println(contadorMaiuscula(palavra,0));
			palavra = sc.nextLine();
		}
	}
}
