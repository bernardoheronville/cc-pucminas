import java.util.Scanner;

public class Main {
    // Funcao para retornar true or false se as string sao iguais.
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

    public static void separador(String linha) {
        String palavra1 = "";
        String palavra2 = "";
        i = 0;
        while(linha.charAt(i) != '-') {
            palavra1 += linha.charAt(i);
            i++;
        }
        for(int j = i; j < linha.length(); j++) {
            palavra2 += linha.charAt(j);
        }
    }

    public static boolean anagrama(String palavra1, String palavra2) {
        boolean resp = true;
        if(palavra1.length() == palavra2.length()) {
            for(int i = 0; i < palavra1.length(); i++) {
                int count = 0;
                for(int j = 0; j < palavra1.length(); j++) {
                    if(palavra1.charAt(i) == palavra2.charAt(j)) {
                        count++;
                    }
                }
                if(count == 0) {
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
        String linha = new String();
        linha = sc.nextLine();
        while(!my_strcmp(palavra1, "FIM")) {
            System.out.println(palavra1);
            System.out.println(palavra2);
            if(anagrama(palavra1, palavra2)) 
                System.out.println("SIM");
            else 
                System.out.println("NAO");
            linha = sc.nextLine();
        }
    sc.close();
    }
}