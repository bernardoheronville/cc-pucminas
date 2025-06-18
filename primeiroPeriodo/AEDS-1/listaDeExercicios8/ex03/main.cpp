#include <iostream>

using namespace std;

class Carro
{
private:
    int capacidade = 50,consumo = 15,combustivelInicial,combustivelFinal,distancia;
public:
    Carro()
    {
        inicializaTudo(50,15,0,0);
    }
    void inicializaTudo(int valor1, int valor2, int valor3, int valor4)
    {
        setCapacidade(valor1);
        setConsumo(valor2);
        setCombustivelInicial(valor3);
        setDistancia(valor4);
    }

    void setCapacidade(int val)
    {
        if(val == 50) capacidade = val;
        else cout << "Capacidade invalida" << endl;
    }
    void setConsumo(int val)
    {
        if(val == 15) consumo = val;
        else cout << "Consumo invalido" << endl;
    }
    void setCombustivelInicial(int val)
    {
        if(val <= 50) combustivelInicial = val;
        else cout << "Capacidade acima" << endl;
    }
    void setDistancia(int val)
    {
        if(val <= 750) distancia = val;
        else cout << "Falta de combustivel" << endl;
    }

    int getCapacidade()
    {
        return capacidade;
    }
    int getConsumo()
    {
        return consumo;
    }
    int getCombustivelInicial()
    {
        return combustivelInicial;
    }
    int getDistancia()
    {
        return distancia;
    }

    void calculaCombustivelFinal()
    {
        int calculo;
        calculo = distancia/consumo;
        combustivelFinal = combustivelInicial - calculo;
    }

    void preenche()
    {
        int val1,val2;
        cin >> val1 >> val2;
        setCombustivelInicial(val1);
        setDistancia(val2);
        calculaCombustivelFinal();
    }
    void exibe()
    {
        cout << "Distancia percorrida: " << getDistancia() << endl;
        cout << "Combustivel restante: " << combustivelFinal << endl;
    }
};

void preencheCarro(Carro carro[], int tam)
{
    for(int i=0; i<tam ; i++)
    {
        carro[i].preenche();
    }
}

void exibeCarro(Carro carro[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << "Carro" << i+1 << ":" << endl;
        carro[i].exibe();
    }
}

int main()
{
    Carro carro[2];
    preencheCarro(carro,2);
    exibeCarro(carro,2);
    return 0;
}
