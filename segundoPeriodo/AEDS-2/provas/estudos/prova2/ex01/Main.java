import java.util.Scanner;

class Data {
    public int dia;
    public int mes;
    public int ano;

    public Data() {
        dia = 0;
        mes = 0;
        ano = 0;
    }
}

class Jogador {
    public String nome;
    public String foto;
    public Data nascimento;
    public int id;
    public int times[];

    public Jogador() {
        nome = "";
        foto = "";
        nascimento = new Data();
        nascimento.dia = 0;
        nascimento.mes = 0;
        nascimento.ano = 0;
        id = 0;
        times = new int[0];
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setFoto(String foto) {
        this.foto = foto;
    }
    public void setData(String data) {
        formatarData(data);
    }
    public void setId(String id) {
        this.id = Integer.parseInt(id);
    }
    public void setTimes(String time) {
        times = formatarTimes(time);
    }

    public void formatarData(String data) {
        String day = "", month = "", year = "";
        if(data.charAt(1) == '/') {
            day += data.charAt(0);
            month += data.charAt(2);
            month += data.charAt(3);
            for(int i = 5; i < data.length(); i++) {
                year += data.charAt(i);
            }
        }
        else {
            day += data.charAt(0);
            day += data.charAt(1);
            month += data.charAt(3);
            month += data.charAt(4);
            for(int i = 6; i < data.length(); i++) {
                year += data.charAt(i);
            }
        }
        nascimento.dia = Integer.parseInt(day);
        nascimento.mes = Integer.parseInt(month);
        nascimento.ano = Integer.parseInt(year);
    }
    
    public int[] formatarTimes(String times) {
        if (times == null || times.isEmpty()) {
            return new int[0];
        }
        int virgulas = 1;
        for(int i = 0; i < times.length(); i++) {
            char c = times.charAt(i);
            if(c == ',') virgulas++; 
        }
        int array[] = new int[virgulas];
        String aux = "";
        int contador = 0;
        for(int i = 0; i < times.length(); i++) {
            char c = times.charAt(i);
            if(c == ',') {
                array[contador++] = Integer.parseInt(aux);
                aux = "";
            }
            else if(c >= '0' && c <= '9'){
                aux += c;
            }
        }
        array[contador] = Integer.parseInt(aux);
        return array;
    }

    public void mostrarArray(int array[]) {
        System.out.print(" (");
        for(int i = 0; i < array.length; i++) {
            if(i < array.length - 1) {
                System.out.print(array[i] + ", ");
            }
            else {
                System.out.print(array[i]);
            }
        }
        System.out.print(")");
    }

    public void  mostrarDia() {
    System.out.printf("%d/%02d/%d", nascimento.dia, nascimento.mes, nascimento.ano);
}

    public void mostrar() {
        System.out.print(id + " " + nome + " ");
        mostrarDia();
        System.out.print(" " + foto);
        mostrarArray(times);
        System.out.println(); 
    }
}

public class Main {
    public static void settar(Jogador jogador, String array[]) {
        jogador.setNome(array[1]);
        jogador.setId(array[5]);
        jogador.setFoto(array[2]);
        jogador.setData(array[3]);
        jogador.setTimes(array[6]);  
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Jogador jogador[] = new Jogador[1000];
        String entrada = sc.nextLine();
        int jogadores = 0;
        boolean aspas = false;
        while(!entrada.equals("FIM")) {
            String array[] = new String[10];
            String aux = "";
            int contador = 0;      
            for(int i = 0; i < entrada.length(); i++) {
                char c = entrada.charAt(i);
                if(c == '"') {
                    aspas = !aspas;
                }
                else if(c == ',' && !aspas) {
                    array[contador++] = aux;
                    aux = "";
                }
                else {
                    aux += c;
                }
            }
            array[contador++] = aux;
            jogador[jogadores] = new Jogador();
            settar(jogador[jogadores], array);
            jogadores++;
            entrada = sc.nextLine();
        }
        for(int i = 0; i < jogadores; i++) {
            jogador[i].mostrar();
        }
    }
}