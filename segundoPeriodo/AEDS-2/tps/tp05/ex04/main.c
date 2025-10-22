#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int compara = 0;
int movimentacoes = 0;

// Auxilio.
#define TAM_MAX 1000
#define TAM 50

// Struct Data para auxilio.
typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

// Struct String para auxilio.
typedef struct {
    char str[TAM_MAX];
} String;

// Struct Game.
typedef struct {
    int id;
    String nome;
    String data;
    int jogadores;
    float preco;
    String idiomas[TAM];
    int num_idiomas; 
    int notaEspecial;
    float notaUsuario;
    int conquistas;
    String empresasPublicacao[TAM];
    int numEmpresasPublicacao;
    String empresasEstudios[TAM];
    int numEmpresasEstudios;
    String categorias[TAM];
    int numCategorias;
    String generos[TAM];
    int numGeneros;
    String tags[TAM];
    int numTags;
    Data dataInt;
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
        } else {
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
// Procedimento que transforma "Oct 18, 2018" em "18/10/2018".
void setDataFormatada(String entrada, String *saida, Data *data) {
    if (strlen(entrada.str) < 8) { 
        strcpy(saida->str, "01/01/0000");
        return;
    }
    char mes[4], dia[3], ano[5], mesNum[3];
    strncpy(mes, entrada.str, 3);
    mes[3] = '\0';
    if (strlen(entrada.str) == 8 && entrada.str[3] == ' ') {
        dia[0] = '0';
        dia[1] = '1';
        dia[2] = '\0';
        strcpy(ano, entrada.str + 4);
    }
    else if (entrada.str[5] == ',') {
        dia[0] = '0';
        dia[1] = entrada.str[4];
        dia[2] = '\0';
        strcpy(ano, entrada.str + 7);
    } 
    else { 
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
    data->dia = atoi(dia);
    data->mes = atoi(mesNum);
    data->ano = atoi(ano);
}

// Setters.
void setId(Game *game, String valor) {
    game->id = atoi(valor.str);
}
void setNome(Game *game, String valor) {
    strcpy(game->nome.str, valor.str);
}
void setData(Game *game, String valor) {
    setDataFormatada(valor, &game->data, &game->dataInt);
}
void setJogadores(Game *game, String valor) {
    String aux;
    aux.str[0] = '\0';
    int pos = 0;
    for (int i = 0; i < strlen(valor.str); i++) {
        if (valor.str[i] >= '0' && valor.str[i] <= '9')
            aux.str[pos++] = valor.str[i];
    }
    aux.str[pos] = '\0';
    game->jogadores = atoi(aux.str);
}
void setPreco(Game *game, String valor) {
    if(strcmp(valor.str, "Free to Play") == 0 || strcmp(valor.str, "0.0") == 0) {
        game->preco = 0.0f;
    }
    else {
        game->preco = atof(valor.str); 
    }  
}
void setIdiomas(Game *game, String valor) {
    game->num_idiomas = formatar(valor, game->idiomas, true);
}
void setNotaEspecial(Game *game, String valor) {
    if(strlen(valor.str) == 0) {
        game->notaEspecial = 0;
    }
    else {
        game->notaEspecial = atoi(valor.str);
    }
}
void setNotaUsuario(Game *game, String valor) {
    if(strlen(valor.str) == 0 || strcmp(valor.str, "tbd") == 0) {
        game->notaUsuario = 0.0f;
    }   
    else {
        game->notaUsuario = atof(valor.str);
    }   
}
void setConquistas(Game *game, String valor) {
    if(strlen(valor.str) == 0) {
        game->conquistas = 0;
    }
    else {
        game->conquistas = atoi(valor.str);
    }
}
void setEmpresasPublicacao(Game *game, String valor) {
    game->numEmpresasPublicacao = formatar(valor, game->empresasPublicacao, false);
}
void setEmpresasEstudios(Game *game, String valor) {
    game->numEmpresasEstudios = formatar(valor, game->empresasEstudios, false);
}
void setCategorias(Game *game, String valor) {
    game->numCategorias = formatar(valor, game->categorias, false);
}
void setGeneros(Game *game, String valor) {
    game->numGeneros = formatar(valor, game->generos, false);
}
void setTags(Game *game, String valor) {
    game->numTags = formatar(valor, game->tags, false);
}
void settar(Game *game, String array[]) {
    setId(game, array[0]);
    setNome(game, array[1]);
    setData(game, array[2]);
    setJogadores(game, array[3]);
    setPreco(game, array[4]);
    setIdiomas(game, array[5]);
    setNotaEspecial(game, array[6]);
    setNotaUsuario(game, array[7]);
    setConquistas(game, array[8]);
    setEmpresasPublicacao(game, array[9]);
    setEmpresasEstudios(game, array[10]);
    setCategorias(game, array[11]);
    setGeneros(game, array[12]);
    setTags(game, array[13]);
}

// Procedimentos para imprimir.
void imprimirArray(String array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        int start = 0;
        while(array[i].str[start] == ' ') start++;
        printf("%s", array[i].str + start);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}
void imprimir(Game *game) {
    printf("=> %d ## %s ## %s ## %d ## ",
        game->id, 
        game->nome.str, 
        game->data.str,
        game->jogadores
    );
    if (game->preco == 0.0) {
        printf("0.0 ## ");
    } else {
        printf("%g ## ", game->preco);
    }
    imprimirArray(game->idiomas, game->num_idiomas);
    printf(" ## %d ## %.1f ## %d ## ", 
        game->notaEspecial, 
        game->notaUsuario,
        game->conquistas
    );
    imprimirArray(game->empresasPublicacao, game->numEmpresasPublicacao);
    printf(" ## ");
    imprimirArray(game->empresasEstudios, game->numEmpresasEstudios);
    printf(" ## ");
    imprimirArray(game->categorias, game->numCategorias);
    printf(" ## ");
    imprimirArray(game->generos, game->numGeneros);
    printf(" ## ");
    imprimirArray(game->tags, game->numTags);
    printf(" ##\n");
}

// Procedimento que faz uma troca entre elementos do array.
void swap(Game *game, int i, int j) {
    Game temp = game[i];
    game[i] = game[j];
    game[j] = temp;
    movimentacoes += 3;
}

// Procedimento que ordena o array a partir do ID.
void ordenarById(Game *game, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = game[(esq + dir) / 2].id;
    while(i <= j) {
        while(game[i].id < pivo) i++;
        while(game[j].id > pivo) j--;
        if(i <= j) {
            swap(game, i, j);
            i++;
            j--;
        }
    }
    if(esq < j) ordenarById(game, esq, j);
    if(i < dir) ordenarById(game, i, dir);
}
// Funcao para realizar uma pesquisa Binaria com a chave de pesquisa ID.
int pesqBinId(Game *game,int jogos, int x){
    int esq = 0, dir = jogos - 1, meio;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (x == game[meio].id) {
            return meio; 
        } 
        else if (x > game[meio].id) {
            esq = meio + 1;
        } 
        else {
            dir = meio - 1;
        }
    }
    return -1; 
}

// Procedimento que ordena o array a partir do nome.
void ordenarByDataId(Game *game, int esq, int dir) {
    int i = esq, j = dir;
    int pivoAno = game[(esq + dir) / 2].dataInt.ano;
    int pivoMes = game[(esq + dir) / 2].dataInt.mes;
    int pivoDia = game[(esq + dir) / 2].dataInt.dia;
    int pivoId = game[(esq + dir) / 2].id;
    while(i <= j) {
        compara++;
        while((game[i].dataInt.ano < pivoAno) || 
            (game[i].dataInt.ano == pivoAno && game[i].dataInt.mes < pivoMes) ||
            (game[i].dataInt.ano == pivoAno && game[i].dataInt.mes == pivoMes && game[i].dataInt.dia < pivoDia) ||
            (game[i].dataInt.ano == pivoAno && game[i].dataInt.mes == pivoMes && game[i].dataInt.dia == pivoDia && game[i].id < pivoId)) {
            i++;
        }
        compara++;
        while((game[j].dataInt.ano > pivoAno) || 
            (game[j].dataInt.ano == pivoAno && game[j].dataInt.mes > pivoMes) ||
            (game[j].dataInt.ano == pivoAno && game[j].dataInt.mes == pivoMes && game[j].dataInt.dia > pivoDia) ||
            (game[j].dataInt.ano == pivoAno && game[j].dataInt.mes == pivoMes && game[j].dataInt.dia == pivoDia && game[j].id > pivoId)) {
            j--;
        }
        compara++;
        if(i <= j) {
            swap(game, i, j);
            i++;
            j--;
        }
    }
    if(esq < j) ordenarByDataId(game, esq, j);
    if(i < dir) ordenarByDataId(game, i, dir);
}

// Main.
int main() {
    FILE *arq = fopen("pubs/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    Game *game = (Game*)malloc(4000 * sizeof(Game));
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
                strcpy(array[contador++].str, aux.str);
                auxPos = 0;
            } else {
                aux.str[auxPos++] = c;
            }
        }
        aux.str[auxPos] = '\0';
        strcpy(array[contador].str, aux.str);
        settar(&game[jogos], array);
        jogos++;
    }
    fclose(arq);
    ordenarById(game, 0, jogos - 1);
    Game *pesquisa = (Game*)malloc(200 * sizeof(Game)); 
    int pesquisaAux = 0;
    String buscaId;
    scanf("%s", buscaId.str);
    while(strcmp(buscaId.str, "FIM") != 0) {
        int idBusca = atoi(buscaId.str);
        int pos = pesqBinId(game, jogos, idBusca);
        if(pos != -1) {
            pesquisa[pesquisaAux++] = game[pos];
        }
        scanf("%s", buscaId.str);
    }
    clock_t inicio = clock();
    if(pesquisaAux > 0) {
        ordenarByDataId(pesquisa, 0, pesquisaAux - 1);
    }
    clock_t fim = clock();
    for(int i = 0; i < pesquisaAux; i++) {
        imprimir(&pesquisa[i]);
    }
    free(pesquisa);
    free(game);
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    FILE *log = fopen("892196_quicksort.txt", "w");
    if (log != NULL) {
        fprintf(log, "892196\t%.3fms\t%dmov\t%dcomp\n", tempoExecucao * 1000, movimentacoes, compara);
        fclose(log);
    } 
    else {
        printf("Erro ao criar arquivo de log.\n");
    }
    return 0;
}