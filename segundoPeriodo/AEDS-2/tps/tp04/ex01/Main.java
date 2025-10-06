import java.util.Scanner;
import java.io.*;

// Classe Game.
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

    // Construtor da classe Game.
    public Game() {
        this.id = 0;
        this.nome = "";
        this.data = "01/01/0000";
        this.jogadores = 0;
        this.preco = 0.0f;
        this.idiomas = new String[0];
        this.notaEspecial = -1;
        this.notaUsuario = -1.0f;
        this.conquistas = 0;
        this.empresasPublicacao = new String[0];
        this.empresasEstudios = new String[0];
        this.categorias = new String[0];
        this.generos = new String[0];
        this.tags = new String[0];
    }

    // Metodos setters.
    public void setID(String id) {
        if (id != null && !id.isEmpty()) {
            this.id = Integer.parseInt(id);
        }
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setData(String data) {
        if (data == null || data.isEmpty()) {
            this.data = "01/01/0000";
            return;
        }
        String mes = "", dia = "", ano = "";
        for (int i = 0; i < 3; i++) {
            mes += data.charAt(i);
        }
        if (data.charAt(5) == ',') {
            dia = "0" + data.charAt(4);
            for (int i = 7; i < data.length(); i++) {
                ano += data.charAt(i);
            }
        } else {
            dia += data.charAt(4);
            dia += data.charAt(5);
            for (int i = 8; i < data.length(); i++) {
                ano += data.charAt(i);
            }
        }
        switch (mes) {
            case "Jan": mes = "01"; break;
            case "Feb": mes = "02"; break;
            case "Mar": mes = "03"; break;
            case "Apr": mes = "04"; break;
            case "May": mes = "05"; break;
            case "Jun": mes = "06"; break;
            case "Jul": mes = "07"; break;
            case "Aug": mes = "08"; break;
            case "Sep": mes = "09"; break;
            case "Oct": mes = "10"; break;
            case "Nov": mes = "11"; break;
            case "Dec": mes = "12"; break;
            default: mes = "01"; break;
        }
        this.data = dia + "/" + mes + "/" + ano;
    }
    public void setJogadores(String jogadores) {
        String aux = "";
        for(int i = 0; i < jogadores.length(); i++) {
            if(jogadores.charAt(i) >= '0' && jogadores.charAt(i) <= '9') {
                aux += jogadores.charAt(i);
            }
        }
        this.jogadores = Integer.parseInt(aux);
    }
    public void setPreco(String preco) {
        if(preco.equals("Free to Play")) {
            this.preco = 0.0f;
        }
        else {
            this.preco = Float.parseFloat(preco);
        } 
    }
    public void setIdiomas(String idiomas) {
        this.idiomas = formatar(idiomas);
    }
    public void setNotaEspecial(String notaEspecial) {
        if(notaEspecial == null || notaEspecial.isEmpty()) {
            this.notaEspecial = -1; 
        } else {
            this.notaEspecial = Integer.parseInt(notaEspecial);
        }
    }
    public void setNotaUsuario(String notaUsuario) {
        if(notaUsuario == null || notaUsuario.isEmpty() || notaUsuario.equals("tbd")) {
            this.notaUsuario = -1.0f; 
        } else {
            this.notaUsuario = Float.parseFloat(notaUsuario);
        }
    }
    public void setConquistas(String conquistas) {
        if(conquistas == null || conquistas.isEmpty()) {
            this.conquistas = 0;
        } else {
            this.conquistas = Integer.parseInt(conquistas);
        } 
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

    // Metodos getters.
    public int getID() { return id; };
    public String getNome() { return nome; };
    public String getData() { return data; };
    public int getJogadores() { return jogadores; };
    public float getPreco() { return preco; }
    public String[] getIdiomas() { return idiomas; };
    public int getNotaEspecial() { return notaEspecial; };
    public float getNotaUsuario() { return notaUsuario; }
    public int getConquistas() { return conquistas; };
    public String[] getEmpresasPublicacao() { return empresasPublicacao; };
    public String[] getEmpresasEstudios() { return empresasEstudios; };
    public String[] getCategorias() { return categorias; };
    public String[] getGeneros() { return generos; };
    public String[] getTags() { return tags; };

    // Funcao que formata as strings.
    public String[] formatar(String entrada) {
        if (entrada == null || entrada.isEmpty() || entrada.equals("[]")) {
            return new String[0];
        }
        int virgulas = 1;
        for(int i = 0; i < entrada.length(); i++) {
            char c = entrada.charAt(i);
            if(c == ',') {
                virgulas++;
            }
        }
        String resp[] = new String[virgulas];
        String aux = "";
        int contador = 0;
        for(int i = 0; i < entrada.length(); i++) {
            char c = entrada.charAt(i);
            if(c == ',') {
                resp[contador] = limparString(aux);
                contador++;
                aux = "";
            } else {
                if(!(c == '[' || c == ']')) {
                    aux += c;
                }
            }
        }
        resp[contador] = limparString(aux);
        return resp;
    }
    // Funcao aulixiar para formatar os espacos.
    private String limparString(String str) {
        if (str == null || str.length() == 0) {
            return "";
        }
        int inicio = 0;
        int fim = str.length() - 1;

        while (inicio < str.length() && str.charAt(inicio) <= ' ') {
            inicio++;
        }

        while (fim >= inicio && str.charAt(fim) <= ' ') {
            fim--;
        }
        if (inicio > fim) {
            return "";
        }
        if ((fim - inicio + 1) >= 2 && str.charAt(inicio) == '\'' && str.charAt(fim) == '\'') {
            inicio++;
            fim--;
        }
        String resultado = "";
        for (int i = inicio; i <= fim; i++) {
            resultado += str.charAt(i);
        }
        return resultado;
    }

    // Funcao para mostrar os atributos da classe.
    private String auxiliarMostrar(String array[]) {
        String result = "[";
        if (array != null) {
            for(int i = 0; i < array.length; i++) {
                result += array[i];
                if(i < array.length - 1) {
                    result += ", ";
                }
            }
        }
        result += "]";
        return result;
    }
    @Override 
    public String toString() {
        return ("=> " + id + " ## " + nome + " ## " + data + " ## " + jogadores + " ## " + preco + " ## " + auxiliarMostrar(idiomas) + " ## " + notaEspecial
                + " ## " + notaUsuario + " ## " + conquistas + " ## " + auxiliarMostrar(empresasPublicacao) + " ## " + auxiliarMostrar(empresasEstudios) + " ## " + auxiliarMostrar(categorias)
                + " ## " + auxiliarMostrar(generos) + " ## " + auxiliarMostrar(tags) + " ##");
    }
}

public class Main {
    // Procedimento auxiliar do metodo settar.
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

    // Main
    public static void main(String args[]) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        File arq = new File("pubs/games.csv");
        Scanner scfile = new Scanner(arq);
        Game game[] = new Game[2000];
        int jogos = 0;
        scfile.nextLine();
        while(scfile.hasNextLine()) { 
            String entrada = scfile.nextLine();
            String array[] = new String[14]; 
            String aux = "";
            int contador = 0;
            boolean aspas = false;
            for (int i = 0; i < entrada.length(); i++) {
                char c = entrada.charAt(i);
                if (c == '"') {
                    aspas = !aspas;
                } else if (c == ',' && !aspas) {
                    array[contador] = aux;
                    contador++;
                    aux = "";
                } else {
                    aux += c;
                }
            }
            array[contador] = aux;
            game[jogos] = new Game();
            settar(game[jogos], array);
            jogos++;
        }
        String busca = sc.nextLine();
        while(!busca.equals("FIM")) {
            int idBusca = Integer.parseInt(busca);
            for(int i = 0; i < jogos; i++) {
                if(idBusca == game[i].getID()) {
                    System.out.println(game[i].toString());
                    i = jogos;
                }
            }
            busca = sc.nextLine();
        }
        sc.close();
        scfile.close();
    }
}