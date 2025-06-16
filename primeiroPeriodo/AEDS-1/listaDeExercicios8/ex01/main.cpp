#include <iostream>

using namespace std;

class Pessoa
{
private:
    string nome;
    int idade;
    float altura;
public:
    Pessoa()
    {
        inicializaTudo(string("nenhum"),1,1);
    }

    void setNome(string texto1)
    {
        if(texto1.length() > 2) nome = texto1;
        else cout << "Nome invalido" << endl;
    }
    void setIdade(int val1)
    {
        if(val1 > 0 && val1 < 120) idade = val1;
        else cout << "Idade invalida" << endl;
    }
    void setAltura(float val2)
    {
        if(val2 > 0.50 && val2 < 3.00) altura = val2;
        else cout << "Altura invalida" << endl;
    }

    string getNome()
    {
        return nome;
    }
    int getIdade()
    {
        return idade;
    }
    float getAltura()
    {
        return altura;
    }

    void preenche()
    {
        string texto;
        int valor1;
        float valor2;
        cout << "Digite o nome: " << endl;
        getline(cin,texto);
        setNome(texto);
        cout << "Digite a idade: " << endl;
        cin >> valor1;
        setIdade(valor1);
        cout << "Digite a altura: " << endl;
        cin >> valor2;
        setAltura(valor2);
        cin.ignore();
    }
    void exibe()
    {
        cout << "Nome: " << getNome() << endl << "Idade: " << getIdade() << " anos" << endl << "Altura: " << getAltura() << " metros" << endl;
    }
private:
    void inicializaTudo(string texto1, int val1, float val2)
    {
        setNome(texto1);
        setIdade(val1);
        setAltura(val2);
    }
};

void preenchePessoas(Pessoa Pessoas[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        Pessoas[i].preenche();
    }
}

void exibePessoas(Pessoa Pessoas[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout << endl << "Dados da pessoa: " << endl;
        Pessoas[i].exibe();
    }
}

int main()
{
    int N;
    cout << "Digite o numero de pessoas: " << endl;
    cin >> N;
    Pessoa Pessoas[N];
    cin.ignore();
    preenchePessoas(Pessoas,N);
    exibePessoas(Pessoas,N);
    return 0;
}
