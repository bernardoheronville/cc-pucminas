#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct String para auxilio.
typedef struct {
    char str[1000];
} String;

// Struct Game.
typedef struct {
    int id;
    String nome;
    String data;
    int jogadores;
    float preco;
    String idiomas[50];
    int num_idiomas; 
    int notaEspecial;
    float notaUsuario;
    int conquistas;
    String empresasPublicacao[50];
    int num_empresasPublicacao;
    String empresasEstudios[50];
    int num_empresasEstudios;
    String categorias[50];
    int num_categorias;
    String generos[50];
    int num_generos;
    String tags[50];
    int num_tags;
} Game;

// Funcao que formata uma string separando uma lista como por exemplo ("['a', 'b', 'c']") em um array de strings.
int formatar(String entrada, String saida[], bool apostrofo) {
    String aux;
    int contador = 0, auxPos = 0;
    for(int i = 0; i < strlen(entrada.str); i++) {
        char c = entrada.str[i]; 
        if(c == ',') {
            aux.str[auxPos] = '\0';
            int start = 0;
            while(aux.str[start] == ' ') start++;
            if (strlen(aux.str + start) > 0) {
                 strcpy(saida[contador].str, aux.str + start);
                 contador++;
            }
            strcpy(aux.str, ""); 
            auxPos = 0;
        }
        else {
            if(!(c == '[' || c == ']' || (apostrofo && c == '\''))) {
                aux.str[auxPos] = c;
                auxPos++;
            }
        }
    }
    aux.str[auxPos] = '\0';
    if (strlen(aux.str) > 0) {
        int start = 0;
        while(aux.str[start] == ' ') start++;
        strcpy(saida[contador].str, aux.str + start);
        contador++;
    }
    return contador;
}
// Procedimento que transforma "Oct 18, 2018" em 18/10/2018.
void setData(String entrada, String *saida) {
    if (strlen(entrada.str) < 8) { 
        strcpy(saida->str, "01/01/0000");
        return;
    }
    char mes[4], dia[3], ano[5], mesNum[3];
    strncpy(mes, entrada.str, 3);
    mes[3] = '\0';
    if (entrada.str[5] == ',') {
        dia[0] = '0';
        dia[1] = entrada.str[4];
        dia[2] = '\0';
        strcpy(ano, entrada.str + 7);
    } else { 
        dia[0] = entrada.str[4];
        dia[1] = entrada.str[5];
        dia[2] = '\0';
        strcpy(ano, entrada.str + 8);
    }
    if (strcmp(mes, "Jan") == 0) strcpy(mesNum, "01");
    else if (strcmp(mes, "Feb") == 0) strcpy(mesNum, "02");
    else if (strcmp(mes, "Mar") == 0) strcpy(mesNum, "03");
    else if (strcmp(mes, "Apr") == 0) strcpy(mesNum, "04");
    else if (strcmp(mes, "May") == 0) strcpy(mesNum, "05");
    else if (strcmp(mes, "Jun") == 0) strcpy(mesNum, "06");
    else if (strcmp(mes, "Jul") == 0) strcpy(mesNum, "07");
    else if (strcmp(mes, "Aug") == 0) strcpy(mesNum, "08");
    else if (strcmp(mes, "Sep") == 0) strcpy(mesNum, "09");
    else if (strcmp(mes, "Oct") == 0) strcpy(mesNum, "10");
    else if (strcmp(mes, "Nov") == 0) strcpy(mesNum, "11");
    else if (strcmp(mes, "Dec") == 0) strcpy(mesNum, "12");
    else strcpy(mesNum, "01");
    strcpy(saida->str, dia);
    strcat(saida->str, "/");
    strcat(saida->str, mesNum);
    strcat(saida->str, "/");
    strcat(saida->str, ano);
}

// Procedimento que setta cada atributo da struct.
void settar(Game *game, String array[]) {
    game->id = atoi(array[0].str);
    strcpy(game->nome.str, array[1].str);
    setData(array[2], &game->data);
    String aux;
    aux.str[0] = '\0';
    int AuxPos = 0;
    for(int i = 0; i < strlen(array[3].str); i++) {
        char c = array[3].str[i];
        if(c >= '0' && c <= '9') {
            aux.str[AuxPos++] = c;
        }
    }
    aux.str[AuxPos] = '\0';
    game->jogadores = atoi(aux.str);
    if(strcmp(array[4].str, "Free to Play") == 0 || strcmp(array[4].str, "0.0") == 0) {
        game->preco = 0.0f;
    } 
    else {
        game->preco = atof(array[4].str); 
    }
    if(strlen(array[6].str) == 0) {
        game->notaEspecial = 0;
    } 
    else {
        game->notaEspecial = atoi(array[6].str);
    }
    if(strlen(array[7].str) == 0 || strcmp(array[7].str, "tbd") == 0) {
        game->notaUsuario = 0.0f;
    } 
    else {
        game->notaUsuario = atof(array[7].str);
    }
    if(strlen(array[8].str) == 0) {
        game->conquistas = 0;
    } 
    else {
        game->conquistas = atoi(array[8].str);
    }
    game->num_idiomas = formatar(array[5], game->idiomas, true); 
    game->num_empresasPublicacao = formatar(array[9], game->empresasPublicacao, false);
    game->num_empresasEstudios = formatar(array[10], game->empresasEstudios, false);
    game->num_categorias = formatar(array[11], game->categorias, false);
    game->num_generos = formatar(array[12], game->generos, false);
    game->num_tags = formatar(array[13], game->tags, false);
}

// Procedimento que imprimi o array a partir de seu tamanho.
void imprimirArray(String arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        int start = 0;
        while(arr[i].str[start] == ' ') start++;
        printf("%s", arr[i].str + start);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Procedimento de imprimir normal
void imprimir(Game *game) {
    printf("=> %d ## %s ## %s ## %d ## %.2f ",
        game->id, 
        game->nome.str, 
        game->data.str,
        game->jogadores,
        game->preco
    );
    imprimirArray(game->idiomas, game->num_idiomas);
    printf(" ## %d ## %.1f ## %d ## ", 
        game->notaEspecial, 
        game->notaUsuario,
        game->conquistas
    );
    imprimirArray(game->empresasPublicacao, game->num_empresasPublicacao);
    printf(" ## ");
    imprimirArray(game->empresasEstudios, game->num_empresasEstudios);
    printf(" ## ");
    imprimirArray(game->categorias, game->num_categorias);
    printf(" ## ");
    imprimirArray(game->generos, game->num_generos);
    printf(" ## ");
    imprimirArray(game->tags, game->num_tags);
    printf(" ##\n");
}

// Main 
int main() {
    FILE *arq = fopen("pubs/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    Game *game = (Game*)malloc(4000*sizeof(Game));
    String entrada, cabecalho;
    int jogos = 0;
    fscanf(arq, " %[^\n]", cabecalho.str); 
    while (fscanf(arq, " %[^\n]", entrada.str) != EOF) {
        entrada.str[strcspn(entrada.str, "\r\n")] = '\0';
        String array[14];
        String aux;
        int contador = 0, auxPos = 0;
        bool aspas = false;
        for (int i = 0; i < strlen(entrada.str); i++) {
            char c = entrada.str[i];
            if (c == '"') {
                aspas = !aspas;
            } else if (c == ',' && !aspas) {
                aux.str[auxPos] = '\0';
                strcpy(array[contador].str, aux.str);
                contador++;
                strcpy(aux.str, "");
                auxPos = 0;
            } else {
                aux.str[auxPos] = c;
                auxPos++;
            }
        }
        aux.str[auxPos] = '\0';
        strcpy(array[contador].str, aux.str);
        settar(&game[jogos], array);
        jogos++;
    }
    fclose(arq);
    char busca[100];
    scanf("%s", busca);
    while (strcmp(busca, "FIM") != 0) {
        int idBusca = atoi(busca);
        for (int i = 0; i < jogos; i++) {
            if (idBusca == game[i].id) {
                imprimir(&game[i]);
                i = jogos;
            }
        }
        scanf("%s", busca);
    }
    free(game);
    return 0;
}