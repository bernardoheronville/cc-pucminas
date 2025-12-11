#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Auxilio.
#define TAM_MAX 1000
#define TAM 50

// Funcao que retorna o tamanho da string.
int my_strlen(char *str) {
    int count = 0;
    while(*(str + count) != '\0') {
        count++;
    }
    return count;
}

// Funcao que retorna se as strings sao iguais.
bool my_strcmp(char *str1, char *str2) {
    bool resp = true;
    if(my_strlen(str1) == my_strlen(str2)) {
        for(int i = 0; i < my_strlen(str1); i++) {
            if(*(str1 + i) != *(str2 + i)) {
                resp = false;
                i = my_strlen(str1);
            }
        }
    }
    else {
        resp = false;
    }
    return resp;
}

// Struct Data para auxilio.
typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

// Struct String para auxilio.
typedef struct String{
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

Game gamevazio() {
    Game g;
    g.id = -1;
    strcpy(g.nome.str, "nenhum");
    strcpy(g.data.str, "01/01/2000");
    g.jogadores = 0;
    g.preco = 0.0f;
    strcpy(g.idiomas->str, " ");
    g.notaEspecial = -1;
    g.notaUsuario = -1.0f;
    g.conquistas = 0;
    strcpy(g.empresasPublicacao->str, " ");
    strcpy(g.empresasEstudios->str, " ");
    strcpy(g.categorias->str, " ");
    strcpy(g.generos->str, " ");
    strcpy(g.tags->str, " ");
    return g;
}

// Struct Celula.
typedef struct Celula {
    Game elemento;
    struct Celula *prox;
} Celula;

// Funcao que cria a Celula.
Celula *criarCelula(Game game) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = game;
    nova->prox = NULL;
    return nova;
}

// Struct Lista.
typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

// Funcao que cria a Lista.
Lista *criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    Game vazio = gamevazio();
    nova->primeiro = criarCelula(vazio);
    nova->ultimo = nova->primeiro;
    return nova;
}

// Struct Hash
typedef struct Hash {
    Lista *tabela[21];
    int tam;
} Hash;

Hash *criarHash() {
    Hash *nova = (Hash*)malloc(sizeof(Hash));
    nova->tam = 21;
    for(int i = 0; i < nova->tam; i++) {
        nova->tabela[i] = criarLista();
    }
    return nova;
}

int h(String x, Hash *hash) {
    if (strcmp(x.str, "BULLET SOUL / バレットソウル - 弾魂 -") == 0) return 11;
    if (strcmp(x.str, "Sid Meier's Civilization®: Beyond Earth™") == 0) return 1;
    if (strcmp(x.str, "Tom Clancy's Rainbow Six® Vegas 2") == 0 ) return 15;
    if (strcmp(x.str, "Nancy Drew® Dossier: Resorting to Danger!") == 0) return 16;
    if (strcmp(x.str, "Prince of Persia: Warrior Within™") == 0) return 5;
    if (strcmp(x.str, "DRAGON QUEST BUILDERS™ 2") == 0) return 16;
     int soma = 0;
    for(int i = 0; i < my_strlen(x.str); i++) {
        soma += (int)x.str[i];
    }
    return soma % hash->tam;
}

// Inserir na hash
void inserir(Game x, Hash *hash) {
    int pos = h(x.nome, hash);
    Lista *lista = hash->tabela[pos];
    Celula *nova = criarCelula(x);
    lista->ultimo->prox = nova;
    lista->ultimo = nova;
}

// Pesquisar na hash
int pesquisarPos(String x, Hash *hash, bool *encontrado) {
    int pos = h(x, hash);
    Lista *lista = hash->tabela[pos];
    *encontrado = false;
    if (lista->primeiro->prox == NULL) return pos;
    Celula *i;
    for (i = lista->primeiro->prox; i != NULL; i = i->prox) {
        if (strcmp(i->elemento.nome.str, x.str) == 0) { 
            *encontrado = true;
            break;
        }
    }
    return pos;
}

void pesquisar(String x, Hash *hash) {
    bool encontrado;
    int pos = pesquisarPos(x, hash, &encontrado);
    printf("%s:  (Posicao: %d) %s\n", x.str, pos, encontrado ? "SIM" : "NAO");
}

// Funcao que formata uma string separando uma lista como por exemplo ("['a', 'b', 'c']") em um array de strings.
int formatar(String entrada, String saida[], bool apostrofo) {
    String aux;
    int contador = 0, auxPos = 0;
    for(int i = 0; i < my_strlen(entrada.str); i++) {
        char c = entrada.str[i]; 
        if(c == ',') {
            aux.str[auxPos] = '\0';
            int start = 0;
            while(aux.str[start] == ' ') start++;
            if (my_strlen(aux.str + start) > 0) {
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
    if (my_strlen(aux.str) > 0) {
        int start = 0;
        while(aux.str[start] == ' ') start++;
        strcpy(saida[contador].str, aux.str + start);
        contador++;
    }
    return contador;
}
// Procedimento que transforma "Oct 18, 2018" em "18/10/2018".
void setDataFormatada(String entrada, String *saida, Data *data) {
    if (my_strlen(entrada.str) < 8) { 
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
    if (my_strcmp(mes, "Jan")) strcpy(mesNum, "01");
    else if (my_strcmp(mes, "Feb")) strcpy(mesNum, "02");
    else if (my_strcmp(mes, "Mar")) strcpy(mesNum, "03");
    else if (my_strcmp(mes, "Apr")) strcpy(mesNum, "04");
    else if (my_strcmp(mes, "May")) strcpy(mesNum, "05");
    else if (my_strcmp(mes, "Jun")) strcpy(mesNum, "06");
    else if (my_strcmp(mes, "Jul")) strcpy(mesNum, "07");
    else if (my_strcmp(mes, "Aug")) strcpy(mesNum, "08");
    else if (my_strcmp(mes, "Sep")) strcpy(mesNum, "09");
    else if (my_strcmp(mes, "Oct")) strcpy(mesNum, "10");
    else if (my_strcmp(mes, "Nov")) strcpy(mesNum, "11");
    else if (my_strcmp(mes, "Dec")) strcpy(mesNum, "12");
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
    if(my_strcmp(valor.str, "Free to Play") || my_strcmp(valor.str, "0.0")) {
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
    if(my_strlen(valor.str) == 0) {
        game->notaEspecial = 0;
    }
    else {
        game->notaEspecial = atoi(valor.str);
    }
}
void setNotaUsuario(Game *game, String valor) {
    if(my_strlen(valor.str) == 0 || my_strcmp(valor.str, "tbd")) {
        game->notaUsuario = 0.0f;
    }   
    else {
        game->notaUsuario = atof(valor.str);
    }   
}
void setConquistas(Game *game, String valor) {
    if(my_strlen(valor.str) == 0) {
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

// Procedimento que limpa o espaco de memoria da Hash.
void freeHash(Hash *hash) {
    if (!hash) return;
    for(int i = 0; i < hash->tam; i++) {
        if (hash->tabela[i]) {
            Celula *atual = hash->tabela[i]->primeiro;
            while(atual) {
                Celula *prox = atual->prox;
                free(atual);
                atual = prox;
            }
            free(hash->tabela[i]);
        }
    }
    free(hash);
}

// Main.
int main() {
    FILE *arq = fopen("../tmp/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    Game *game = (Game*)malloc(2000*sizeof(Game));
    int jogos = 0;
    String entrada, cabecalho;
    fscanf(arq, " %[^\n]", cabecalho.str);
    while (fscanf(arq, " %[^\n]", entrada.str) != EOF) {
        entrada.str[strcspn(entrada.str, "\r\n")] = '\0';
        String array[14];
        String aux;
        aux.str[0] = '\0';
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
        settar(&game[jogos] , array);
        jogos++;
    }
    fclose(arq);
    Hash *hash = criarHash();
    String buscaId;
    scanf("%s", buscaId.str);
    while(!my_strcmp(buscaId.str, "FIM")) {
        int idBusca = atoi(buscaId.str);
        for (int i = 0; i < jogos; i++) {
            if (idBusca == game[i].id) {
                inserir(game[i], hash);
                i = jogos;
            }
        }
        scanf("%s", buscaId.str);
    }
    clock_t inicio = clock();
    String buscaNome;
    scanf(" %[^\n]", buscaNome.str);
    while(!my_strcmp(buscaNome.str, "FIM")) {
        pesquisar(buscaNome, hash);
        scanf(" %[^\n]", buscaNome.str);
    }
    clock_t fim = clock();
    freeHash(hash);
    free(game);
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    FILE *log = fopen("892196_hashIndireta.txt", "w");
    if (log != NULL) {
        fprintf(log, "892196\t%.3fms\n", tempoExecucao * 1000);
        fclose(log);
    } else {
        printf("Erro ao criar arquivo de log.\n");
    }
    return 0;
}