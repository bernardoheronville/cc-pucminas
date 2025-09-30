import java.util.Scanner;

class Game {
    private int id;
    private String nome;
    private String data;
    private int jogadores;
    private float preco;
    private String idiomas[];
    private int notaEspecial;
    private float notaUsuario;
    private int conquistas;
    private String empresasPublicacao[];
    private String empresasEstudios[];
    private String categorias[];
    private String generos[];
    private String tags[];

}

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            String entrada = sc.nextLine();
            String array[] = new String[14];
            int contador = 0;
            String aux = "";
            for(int i = 0; i < entrada.length(); i++) {
                char c = entrada.charAt(i);
                if(c == ',') {
                    array[contador] = aux;
                    contador++;
                    aux = "";
                }
                else {
                    aux += c;
                }
            }
        }
        sc.close();
    }
}