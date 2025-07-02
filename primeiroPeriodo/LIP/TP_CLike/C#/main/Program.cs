// Em C#, usamos a diretiva 'using' para importar namespaces.
// O namespace 'System' contém classes fundamentais como 'Console'.
using System;

// Todo código em C# deve estar dentro de uma classe.
// Por padrão, em projetos de console, a classe se chama 'Program'.
class Program
{
    // A função 'Main' é o ponto de entrada do programa.
    static void Main(string[] args)
    {
        // Declara uma variável inteira N.
        int N;

        // Leitura de dados 
        // Lê a linha inteira como uma string.
        
        string input = Console.ReadLine();
        // Precisamos converter (fazer o "parse") essa string para um número inteiro.
        N = int.Parse(input); 

        // Calcula a distância como (N - 3) módulo 8
        int distancia = (N - 3) % 8;

        // Estrutura switch para determinar a saída com base no valor da distância
        switch (distancia)
        {
            case 3: // Se a distância for 3
                Console.WriteLine("1"); // Imprimi 1
                break; // Sai do swtich
            case 4: // Se a distância for 4
                Console.WriteLine("2"); //Imprimi 2
                break; // Sai do swtich
            case 5: // Se a distância for 5
                Console.WriteLine("3"); //Imprimi 3
                break; // Sai do swtich
            default: // Para qualquer outro valor
                Console.WriteLine("ERRO"); //Imprimi ERRO
                break; // Sai do swtich
        }
    }
}