import java.util.Scanner;

public class Ex01 {
    public static void preencherArray(Scanner sc, int tam, int array[]) {
        for (int i = 0; i < tam; i++) {
            array[i] = sc.nextInt();
        }
    }

    public static boolean verificaArray(int num, int tam, int array[]) {
        boolean existe = false;
        for (int i = 0; i < tam; i++) {
            if (array[i] == num) {
                existe = true;
                return existe;
            }
        }
        return existe;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o tamanho do array!");
        int tam = sc.nextInt();
        int array[] = new int[tam];
        System.out.println("Digite " + tam + " numeros!");
        preencherArray(sc, tam, array);
        System.out.println("Digite o numero que voce quer verificar se esta no array:");
        int num;
        num = sc.nextInt();
        if (verificaArray(num, tam, array)) {
            System.out.println("O numero " + num + " existe no array!");
        } else {
            System.out.println("O numero " + num + " nao existe no array!");
        }
        sc.close();
    }
}