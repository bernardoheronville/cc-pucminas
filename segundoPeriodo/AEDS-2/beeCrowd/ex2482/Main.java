import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            int n = sc.nextInt();
            sc.nextLine();
            String arrayIdioma[] = new String[n];
            String arrayFeliz[] = new String[n];
            for(int i = 0; i < n; i++) {
                arrayIdioma[i] = sc.nextLine();
                arrayFeliz[i] = sc.nextLine();
            }
            int M = sc.nextInt();
            sc.nextLine();
            String arrayNomes[] = new String[M];
            String arrayLingua[] = new String[M];
            for(int i = 0; i < M; i++) {
                arrayNomes[i] = sc.nextLine();
                arrayLingua[i] = sc.nextLine();
            }
            for(int i = 0; i < M; i++) {
                System.out.println(arrayNomes[i]);
                for(int j = 0; j < n; j++) {
                    if(arrayLingua[i].equals(arrayIdioma[j])) {
                        System.out.println(arrayFeliz[j]);
                        System.out.printf("\n");
                    }
                }
            }
        } 
    }
}