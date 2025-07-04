#include <iostream>

using namespace std;

class Autor
{
private:
    string nome;
public:
    Autor()
    {
        inicializa("nenhum");
    }
    void inicializa(string texto1)
    {
        setNome(texto1);
    }

    void setNome(string texto)
    {
        if(texto.length() > 2) nome = texto;
        else cout << "Nome invalido" << endl;
    }

    string getNome()
    {
        return nome;
    }

    void exibe()
    {
        cout << "Autor: " << getNome() << endl;
    }
};

class Livro
{
private:
    string titulo;
    int ano;
    Autor *autor;
public:
    Livro(Autor *autorObj) : autor(autorObj)
    {
        inicializa("nenhum",0);
    }
    void inicializa(string texto1, int valor1)
    {
        setTitulo(texto1);
        setAno(valor1);
    }

    void setTitulo(string texto)
    {
        if(texto.length() > 2) titulo = texto;
        else cout << "Titulo invalido" << endl;
    }
    void setAno(int valor)
    {
        if(valor < 2026) ano = valor;
        else cout << "Ano invalido" << endl;
    }

    string getTitulo()
    {
        return titulo;
    }
    int getAno()
    {
        return ano;
    }

    void exibe()
    {
        cout << "Detalhes do Livro: " << endl;
        cout << "Titulo: " << getTitulo() << endl;
        cout << "Ano de publicacao: " << getAno() << endl;
        cout << "Autor: " << autor->getNome() << endl;
    }
};

int main()
{
    string nomeAutor;
    getline(cin,nomeAutor);
    Autor autor;
    autor.setNome(nomeAutor);
    string tituloLivro;
    int anoLivro;
    getline(cin,tituloLivro);
    cin >> anoLivro;
    Livro livro(&autor);
    livro.setTitulo(tituloLivro);
    livro.setAno(anoLivro);
    livro.exibe();
    return 0;
}
