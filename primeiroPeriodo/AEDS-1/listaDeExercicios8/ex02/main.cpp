#include <iostream>

using namespace std;

class Relogio
{
private:
    int horas,minutos,segundos;
public:
    Relogio()
    {
        inicializaTudo(0,0,0);
    }

    void setHoras(int val1)
    {
        if(val1 >= 0 && val1 <= 23) horas = val1;
        else cout << "Hora invalida" << endl;
    }
    void setMinutos(int val1)
    {
        if(val1 >= 0 && val1 <= 59) minutos = val1;
        else cout << "Minutos invalido" << endl;
    }
    void setSegundos(int val1)
    {
        if(val1 >= 0 && val1 <= 59) segundos = val1;
        else cout << "Segundos invalido" << endl;
    }

    int getHoras()
    {
        return horas;
    }
    int getMinutos()
    {
        return minutos;
    }
    int getSegundos()
    {
        return segundos;
    }

    void passaHorario()
    {
        segundos++;
        if(segundos == 60)
        {
            segundos = 0;
            minutos++;
        }
        if(minutos == 60)
        {
            minutos = 0;
            horas++;
        }
        if(horas == 24)
        {
            horas = 0;
            minutos = 0;
            segundos = 0;
        }
    }

    void preenche()
    {
        int v1,v2,v3;
        cin >> v1 >> v2 >> v3;
        setHoras(v1);
        setMinutos(v2);
        setSegundos(v3);
    }

    void exibe()
    {
        cout << "Horario inicial: " << getHoras() << ":" << getMinutos() << ":" << getSegundos() << endl;
        passaHorario();
        cout << "Novo horario: " << getHoras() << ":" << getMinutos() << ":" << getSegundos() << endl << endl;
    }
private:
    void inicializaTudo(int valor1, int valor2, int valor3)
    {
        setHoras(valor1);
        setMinutos(valor2);
        setSegundos(valor3);
    }
};

void preencheHorario(Relogio relogio[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        relogio[i].preenche();
    }
}

void exibeHorario(Relogio relogio[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        relogio[i].exibe();
    }
}

int main()
{
    int N;
    cin >> N;
    if(N >= 1 && N <= 1000)
    {
        Relogio relogio[N];
        preencheHorario(relogio,N);
        exibeHorario(relogio,N);
    }
    else
    {
        cout << "Numero invalido" << endl;
    }
    return 0;
}
