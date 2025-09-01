import java.util.Scanner;

public class Main {
	public static void contadorMaiuscula(String palavra) {
		int tam = palavra.length(), contador = 0;
		for(int i=0;i<tam;i++) {
			if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z') {
				contador++;
			}
		}
		System.out.println(contador);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String palavra = sc.nextLine();
		while(!palavra.equals("FIM")) {
			contadorMaiuscula(palavra);
			palavra = sc.nextLine();
		}
	}
}
