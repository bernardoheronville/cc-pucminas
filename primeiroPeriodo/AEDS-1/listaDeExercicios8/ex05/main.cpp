#include <iostream>

using namespace std;

class Elevador
{
private:
    int andarAtual=0,totalAndares,pessoasPresentes=0,capacidade;
public:
    Elevador()
    {
        inicializaTudo(0,0);
    }
    Elevador(int valor1, int valor2)
    {
        inicializaTudo(valor1,valor2);
    }
    void inicializaTudo(int valor1,int valor2)
    {
        setCapacidade(valor1);
        setTotalAndares(valor2);
    }

    void setCapacidade(int valor)
    {
        if(valor > 0) capacidade = valor;
        else cout << "Capacidade invalida" << endl;
    }
    void setTotalAndares(int valor)
    {
        if(valor > 0) totalAndares = valor;
        else cout << "Total de andares invalido" << endl;
    }

    int getAndarAtual()
    {
        return andarAtual;
    }
    int getTotalAndares()
    {
        return totalAndares;
    }
    int getCapacidade()
    {
        return capacidade;
    }
    int getPessoasPresentes()
    {
        return pessoasPresentes;
    }

    void entra()
    {
        if(pessoasPresentes  < capacidade) pessoasPresentes++;
        else cout << "Elevador lotado" << endl;
    }
    void sai()
    {
        if(pessoasPresentes > 0) pessoasPresentes--;
        else cout << "Elevador vazio" << endl;
    }
    void sobe()
    {
        if(andarAtual < totalAndares) andarAtual++;
        else cout << "Andar maximo" << endl;
    }
    void desce()
    {
        if(andarAtual > 0) andarAtual--;
        else cout << "Ja esta no andar 0" << endl;
    }
    void exibe()
    {
        cout << "Andar atual: " << getAndarAtual() << endl;
        cout << "Pessoas presentes: " << getPessoasPresentes() << endl;
    }
};

int main()
{
    int cap,total,N;
    cin >> cap >> total;
    Elevador elevador(cap,total);
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string texto;
        cin >> texto;
        if (texto == "entrar")
        {
            elevador.entra();
            elevador.exibe();
        }
        else if (texto == "sair")
        {
            elevador.sai();
            elevador.exibe();
        }
        else if (texto == "subir")
        {
            elevador.sobe();
            elevador.exibe();
        }
        else if (texto == "descer")
        {
            elevador.desce();
            elevador.exibe();
        }
        else
        {
            cout << "Digite uma opcao valida" << endl;
        }
    }
    return 0;
}
