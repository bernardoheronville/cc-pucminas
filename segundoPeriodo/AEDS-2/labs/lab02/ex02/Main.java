import java.util.Scanner;

public class Main {
	public static int trocar(int num) {
		if(num == 0) return 0;
		else {
			System.out.printf("%d",num % 10);
			return trocar(num / 10);
		}
	}

	public static void espelho(int num1, int num2) {
		if(num1 < 10) {
			for(int i = num2; i >= num1; i--) {
				System.out.print(i);
			}
			System.out.printf("\n");
		}
		else {
			for(int i = num2; i >= num1; i--) {
				trocar(i);
			}
			System.out.printf("\n");
		}
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()) {
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		for(int i = num1; i <= num2; i++) {
			System.out.print(i);
		}
		espelho(num1, num2);
		}
		sc.close();
	}
}
