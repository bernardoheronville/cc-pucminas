// Importa a classe Scanner do pacote java.util, que é usada para ler a entrada do usuário.
import java.util.Scanner;

// Declaração da classe principal onde o programa reside.
public class Main {
    public static void main(String[] args) {

        // Cria um objeto (uma instância) da classe Scanner chamado 'dado'.
        // System.in indica que a fonte da entrada será o teclado.
        Scanner dado = new Scanner(System.in);

        // Usa o objeto 'dado' para ler o próximo número inteiro digitado pelo usuário
        // e o armazena na variável N.
        int N = dado.nextInt();

        // Calcula o resto da divisão de (N - 3) por 8.
        int distancia = (N - 3) % 8;

        String resultado = switch (distancia) {
            case 3 -> "1"; // Se a distância der 3 armazenado 1 na variável 'resultado'
            case 4 -> "2"; // Se a distância der 4 armazenado 2 na variável 'resultado'
            case 5 -> "3"; // Se a distância der 5 armazenado 3 na variável 'resultado'
            default -> "ERRO"; // Para qualquer outro valor de distância armazenado ERRO na variável 'resultado'
        }; 

        // Imprime no console o valor final que foi armazenado na variável 'resultado'.
        System.out.println(resultado);

        // Isso libera os recursos que ele estava utilizando no sistema.
        dado.close();
    }
}