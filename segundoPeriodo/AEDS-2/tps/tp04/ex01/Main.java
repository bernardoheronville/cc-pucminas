import java.util.Scanner;
import java.io.*;

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

    public void setID(String id) {
        this.id = Integer.parseInt(id);
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setData(String data) {
        String mes = "", dia = "", ano = "", resp = "";
        for(int i = 0; i < 3; i++) {
            mes += data.charAt(i);
        }
        if(data.charAt(5) == ',') {
            dia += '0';
            dia += data.charAt(4);
        }
        else {
            dia += data.charAt(4);
            dia += data.charAt(5);
        }
        for(int i = 8; i < data.length() - 1; i++) {
            ano += data.charAt(i);
        }
        resp = dia + "/" + mes + "/" + ano;
        this.data = resp;
    }
    public void setJogadores(String jogadores) {
        this.jogadores = Integer.parseInt(jogadores);
    }
    public void setPreco(String preco) {
        this.preco = Float.parseFloat(preco);
    }
    public void setIdiomas(String idiomas) {
        this.idiomas = formatar(idiomas);
    }
    public void setNotaEspecial(String notaEspecial) {
        this.notaEspecial = Integer.parseInt(notaEspecial);
    }
    public void setNotaUsuario(String notaUsuario) {
        this.notaUsuario = Float.parseFloat(notaUsuario);
    }
    public void setConquistas(String conquistas) {
        this.conquistas = Integer.parseInt(conquistas);
    }
    public void setEmpresasPublicacao(String empresasPublicacao) {
        this.empresasPublicacao = formatar(empresasPublicacao);
    }
    public void setEmpresasEstudios(String empresasEstudios) {
        this.empresasEstudios = formatar(empresasEstudios);
    }
    public void setCategorias(String categorias) {
        this.categorias = formatar(categorias);
    }
    public void setGeneros(String generos) {
        this.generos = formatar(generos);
    }
    public void setTags(String tags) {
       this.tags = formatar(tags);
    }
    public String[] formatar(String entrada) {
        int virgulas = 0;
        for(int i = 0; i < entrada.length(); i++) {
            char c = entrada.charAt(i);
            if(c == ',') {
                virgulas++;
            }
        }
        String resp[] = new String[virgulas + 1];
        String aux = "";
        int contador = 0;
        for(int i = 0; i < entrada.length(); i++) {
            char c = entrada.charAt(i); 
            if(c == ',') {
                resp[contador] = aux;
                contador++;
                aux = "";
            }
            else {
                if(!(c == '[' || c == ']' || c == '\'')) {
                    aux += c;
                } 
            }
        }
        resp[contador] = aux;
        return resp;
    }
    public int getID() { return id; };

    private String auxiliarMostrar(String array[]) {
        String result = "[";
        for(int i = 0; i < array.length; i++) {
            result += array[i];
            if(i < array.length - 1) {
                result += ",";
            }
        }
        result += "]";
        return result;
    }

    @Override 
    public String toString() {
        return ("=> " + id + " ## " + nome + " ## " + data + " ## " + jogadores + " ## " + preco + " ## " + auxiliarMostrar(idiomas) + " ## " + notaEspecial
                + " ## " + notaUsuario + " ## " + conquistas + " ## " + auxiliarMostrar(empresasPublicacao) + " ## " + auxiliarMostrar(empresasEstudios) + " ## " + auxiliarMostrar(categorias)
                + " ## " + auxiliarMostrar(generos) + " ## " + auxiliarMostrar(tags));
    }
}

public class Main {
    public static void settar(Game game, String array[]) {
        game.setID(array[0]);
        game.setNome(array[1]);
        game.setData(array[2]);
        game.setJogadores(array[3]);
        game.setPreco(array[4]);
        game.setIdiomas(array[5]);
        game.setNotaEspecial(array[6]);
        game.setNotaUsuario(array[7]);
        game.setConquistas(array[8]);
        game.setEmpresasPublicacao(array[9]);
        game.setEmpresasEstudios(array[10]);
        game.setCategorias(array[11]);
        game.setGeneros(array[12]);
        game.setTags(array[13]);
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        File arq = new File("games.csv");
        Scanner scfile = new Scanner(arq);
        Game game[] = new Game[1850];
        for(int i = 0; i < 1850; i++) {
            game[i] = new Game();
            String entrada = scfile.nextLine();
            String array[] = new String[14];
            String aux = "";
            int contador = 0;
            boolean aspas = false;
            boolean dentroLista = false;
            for (int j = 0; j < entrada.length(); j++) {
                char c = entrada.charAt(j);
                if (c == '"') {
                    aspas = !aspas;
                } else if (c == '[') {
                    dentroLista = true;
                    aux += c;
                } else if (c == ']') {
                    dentroLista = false;
                    aux += c;
                } else if (c == ',' && !aspas && !dentroLista) {
                    array[contador++] = aux;
                    aux = "";
                } else {
                    aux += c;
                }
            }
            array[contador] = aux;
            settar(game[i], array);
        }
        String teste = sc.nextLine();
        while(!teste.equals("FIM")) {
            for(int i = 0; i < 1850; i++) {
                if(Integer.parseInt(teste) == game[i].getID()) {
                    System.out.println(game[i].toString());
                }
            }
            teste = sc.nextLine();
        }
        sc.close();
        scfile.close();
    }
}