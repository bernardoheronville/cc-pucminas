// Inclui a biblioteca de entrada e saída (iostream),
#include <iostream>

// Isso nos permite escrever 'cout' em vez de 'std::cout', por exemplo.
using namespace std;

// A função 'main' é o ponto de entrada de qualquer programa C++.
int main()
{
    // Declara uma variável inteira chamada 'N' para armazenar o input do usuário.
    int N;

    // Lê um número inteiro do teclado e o armazena na variável 'N'.
    cin >> N;

    // Calcula o resto da divisão de (N - 3) por 8.
    int distancia = (N - 3) % 8;

    // A estrutura 'switch' verifica o valor da variável 'distancia'.
    switch (distancia)
    {
    // Caso o valor de 'distancia' seja 3...
    case 3:
        // ...imprime "1" na tela.
        cout << "1" << endl;
        // 'break' encerra o switch.
        break;
    // Caso o valor de 'distancia' seja 4...
    case 4:
        // ...imprime "2" na tela.
        cout << "2" << endl;
        break;
    // Caso o valor de 'distancia' seja 5...
    case 5:
        // ...imprime "3" na tela.
        cout << "3" << endl;
        break;
    // 'default' é executado se nenhum dos casos ('case') acima for verdadeiro.
    default:
        // Imprime "ERRO" na tela.
        cout << "ERRO" << endl;
        break;
    }
    // Retorna 0 para indicar que o programa foi executado com sucesso.
    return 0;
}