#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão para funções utilitárias

int main() // Função principal do programa
{
    int N; // Declara uma variável inteira N
    printf("Digite um numero inteiro: "); // Solicita ao usuário que digite um número inteiro
    // Lê um número inteiro da entrada padrão e armazena em N
    scanf("%d", &N);

    // Calcula a distância como (N - 3) módulo 8
    int distancia = (N - 3) % 8;

    // Estrutura switch para determinar a saída com base no valor da distância
    switch (distancia)
    {
    case 3: // Se a distância for 3
        printf("1\n"); // Imprime 1
        break; // Sai do switch
    case 4: // Se a distância for 4
        printf("2\n"); // Imprime 2
        break; // Sai do switch
    case 5: // Se a distância for 5
        printf("3\n"); // Imprime 3
        break; // Sai do switch
    default: // Para qualquer outro valor de distância
        printf("ERRO\n"); // Imprime "ERRO"
        break; // Sai do switch
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
