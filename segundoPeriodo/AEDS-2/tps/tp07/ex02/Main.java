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
        if (id != null) {
            this.id = Integer.parseInt(id);
        }
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setData(String data) {
        if (data == null) {
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
        if(notaEspecial == null) {
            this.notaEspecial = -1; 
        } else {
            this.notaEspecial = Integer.parseInt(notaEspecial);
        }
    }
    public void setNotaUsuario(String notaUsuario) {
        if(notaUsuario == null || notaUsuario.equals("tbd")) {
            this.notaUsuario = -1.0f; 
        } else {
            this.notaUsuario = Float.parseFloat(notaUsuario);
        }
    }
    public void setConquistas(String conquistas) {
        if(conquistas == null) {
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
        if (entrada == null || entrada.equals("[]")) {
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

// Classe No1.
class No1 {
    public int inteiro;
    public No1 esq, dir;
    public Arvore2 game;

    // Construtores da classe No1.
    public No1() {
        inteiro = 0;
        esq = dir = null;
        game = new Arvore2();
    }
    public No1(int x) {
        inteiro = x;
        esq = dir = null;
        game = new Arvore2();
    }
}

// Classe No2.
class No2 {
    public Game elemento;
    public No2 esq, dir;

    // Construtores da classe No2.
    public No2() {
        elemento = new Game();
        esq = dir = null;
    }
    public No2(Game game) {
        elemento = game;
        esq = dir = null;
    }
}

// Classe Arvore1.
class Arvore1 {
    public No1 raiz;

    // Construtor da classe Arvore1.
    public Arvore1() {
        raiz = null;
    }

    // Procedimentos de insercao da Arvore1.
    public void inserir(int x) {
        raiz = inserir(raiz, x);
    }
    private No1 inserir(No1 i, int x) {
        if(i == null) i = new No1(x);
        else if(x > i.inteiro) i.dir = inserir(i.dir, x);
        else if(x < i.inteiro) i.esq = inserir(i.esq, x);
        else;
        return i;
    }

    // Funcao de pesquisa da Arvore1.
    public No1 pesquisarJogadores(int x) {
        return pesquisarJogadores(raiz, x);
    }
    private No1 pesquisarJogadores(No1 i, int x) {
        No1 resp = null;
        while(i != null) {
            if(x > i.inteiro) i = i.dir;
            else if(x < i.inteiro) i = i.esq;
            else {
                resp = i;
                i = null;
            }
        }
        return resp;
    }

    // Funcao de pesquisa da Arvore1.
    public void pesquisar(String str) {
        System.out.print(str + " => raiz ");
        if(pesquisar(raiz, str)) {
            System.out.println(" SIM");
        }
        else {
            System.out.println(" NAO");
        }
    }
    private boolean pesquisar(No1 i, String str) {
        boolean resp = false;
        if(i != null) {
            Main.compara++;
            resp = i.game.pesquisar(str);
            if(!resp) {
                System.out.print(" ESQ ");
                resp = pesquisar(i.esq, str);
            }
            if (!resp) {
                System.out.print(" DIR ");
                resp = pesquisar(i.dir, str);
            }
        }
        return resp;
    }

    // Procedimento que mostra os elementos da Arvore1.
    public void caminharPre() {
        caminharPre(raiz);
    }
    private void caminharPre(No1 i) {
        if(i != null) {
            System.out.println(i.inteiro);
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }
    public void caminharCentral() {
        caminharCentral(raiz);
    }
    private void caminharCentral(No1 i) {
        if(i != null) {
            caminharCentral(i.esq);
            System.out.println(i.inteiro);
            caminharCentral(i.dir);
        }
    }
}

// Classe Arvore2.
class Arvore2 {
    public No2 raiz;

    // Construtor da classe Arvore2.
    public Arvore2() {
        raiz = null;
    }

    // Procedimentos de insercao da Arvore2.
    public void inserir(Game game) {
        raiz = inserir(raiz, game);
    }
    private No2 inserir(No2 i, Game game) {
        if(i == null) i = new No2(game);
        else if(game.getNome().compareTo(i.elemento.getNome()) > 0) i.dir = inserir(i.dir, game);
        else if(game.getNome().compareTo(i.elemento.getNome()) < 0) i.esq = inserir(i.esq, game);
        else;
        return i;
    }

    // Funcao de pesquisa da Arvore2.
    public boolean pesquisar(String str) {
        return pesquisar(raiz, str);
    }
    private boolean pesquisar(No2 i, String str) {
        boolean resp = false;
        while(i != null) {
            Main.compara++;
            if(str.compareTo(i.elemento.getNome()) > 0) {
                System.out.print("dir ");
                i = i.dir;
            }
            else if(str.compareTo(i.elemento.getNome()) < 0) {
                System.out.print("esq ");
                i = i.esq;
            }
            else {
                resp = true;
                i = null;
            }
        }
        return resp;
    }
}

public class Main {
    // Variavel global para armazenar os numeros de comparacoes.
    public static int compara = 0;

    // Funcao o valor do horario atual.
    public static long now() {
        return System.nanoTime();
    }

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

    // Funcao para retornar true or false se as string sao iguais.
    public static boolean my_strcmp(String str1, String str2) {
        boolean resp = true;
        if(str1.length() == str2.length()) {
            for(int i = 0; i < str1.length(); i++) {
                if(str1.charAt(i) != str2.charAt(i)) {
                    resp = false;
                    i = str1.length();
                }
            }
        }
        else {
            resp = false;
        }
        return resp;
    }

    // Main
    public static void main(String args[]) throws FileNotFoundException {
        long inicio, fim;
        Scanner sc = new Scanner(System.in);
        File arq = new File("../tmp/games.csv");
        Scanner scfile = new Scanner(arq);
        Game game[] = new Game[2000];
        int jogos = 0;
        Arvore1 arvore = new Arvore1();
        int numeros[] = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14};
        for(int i = 0; i < numeros.length; i++) {
            arvore.inserir(numeros[i]);
        }
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
                    No1 teste = arvore.pesquisarJogadores(game[i].getJogadores() % 15);
                    teste.game.inserir(game[i]);
                    i = jogos;
                }
            }
            busca = sc.nextLine();
        }
        inicio = now();
        String buscaNome = sc.nextLine();
        while(!my_strcmp(buscaNome, "FIM")) {
            System.out.print("=> ");
            arvore.pesquisar(buscaNome);
            buscaNome = sc.nextLine();
        }
        fim = now();
        double tempoExecucao = (fim - inicio) / 1_000_000.0; 
        try {
            PrintWriter log = new PrintWriter("892196_arvoreArvore.txt"); 
            log.printf("892196\t%.2fms\t%dcomparacoes\n", tempoExecucao, compara);
            log.close();
        } catch (IOException e) {
            System.out.println("Erro ao gravar log: " + e.getMessage());
        }
        sc.close();
        scfile.close();
    }
}