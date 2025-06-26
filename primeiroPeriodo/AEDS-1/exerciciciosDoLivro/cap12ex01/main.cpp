#include <iostream>

using namespace std;

class TIPO
{
private:
    int codigo;
    float percentual;
public:
    TIPO()
    {
        inicializaTudo(1);
    }
    TIPO(int valor1)
    {
        inicializaTudo(valor1);
    }
    void inicializaTudo(int valor1)
    {
        setCodigo(valor1);
        setPercentual();
    }

    void setCodigo(int valor)
    {
        if(valor == 1 || valor == 2) codigo = valor;
        else cout << "Codigo invalido" << endl;
    }
    void setPercentual()
    {
        if(codigo == 1) percentual = 10;
        else if(codigo == 2) percentual = 20;
        else cout << "Percentual invalido" << endl;
    }

    int getCodigo()
    {
        return codigo;
    }
    float getPercentual()
    {
        return percentual;
    }

    void preenche()
    {
        int valor1;
        cout << "Digite o codigo do produto: " << endl;
        cin >> valor1;
        setCodigo(valor1);
        setPercentual();
    }
    void exibe()
    {
        cout << "O codigo do produto eh: " << getCodigo() << endl;
        cout << "E seu percentual eh: " << getPercentual() << endl;
    }

};

class PRODUTO
{
private:
    string descricao;
    TIPO tipo;
    float preco,imposto;
public:
    PRODUTO()
    {
        inicializaTudo(string("nenhum"),1,1);
    }
    PRODUTO(string texto1, int valor1, float valor2)
    {
        inicializaTudo(texto1,valor1,valor2);
    }
    void inicializaTudo(string texto1, int valor1, float valor2)
    {
        setDescricao(texto1);
        tipo.setCodigo(valor1);
        setPreco(valor2);
        setImposto();
    }

    void setDescricao(string texto)
    {
        if(texto.length() > 2) descricao = texto;
        else cout << "Descricao muito pequena" << endl;
    }
    void setPreco(float valor)
    {
        if(valor > 0) preco = valor;
        else cout << "Preco invalido" << endl;
    }
    void setImposto()
    {
        imposto = tipo.getPercentual() / 100 * preco;
    }

    string getDescricao()
    {
        return descricao ;
    }
    float getPreco()
    {
        return preco;
    }
    float getImposto()
    {
        return imposto;
    }

    void preenche()
    {
        string texto1;
        float valor1;
        tipo.preenche();
        cout << "Descricao do produto: " << endl;
        cin.ignore();
        getline(cin,texto1);
        setDescricao(texto1);
        cout << "Preco do produto: " << endl;
        cin >> valor1;
        setPreco(valor1);
        setImposto();
    }
    void exibe()
    {
        tipo.exibe();
        cout << "Descricao do produto: " << getDescricao() << endl;
        cout << "Preco inicial: " << getPreco() << endl;
        cout << "Valor do imposto: " << getImposto() << endl;
        cout << "Preco final: " << preco+imposto << endl;
    }
};

int main()
{
    PRODUTO produto;
    produto.preenche();
    produto.exibe();
    return 0;
}
