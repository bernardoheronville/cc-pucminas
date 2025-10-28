#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    strcpy(g.nome.str, "");
    strcpy(g.data.str, "");
    g.jogadores = 0;
    g.preco = 0.0f;
    g.num_idiomas = 0;
    g.notaEspecial = 0;
    g.notaUsuario = 0.0f;
    g.conquistas = 0;
    g.numEmpresasPublicacao = 0;
    g.numEmpresasEstudios = 0;
    g.numCategorias = 0;
    g.numGeneros = 0;
    g.numTags = 0;
    g.dataInt.dia = g.dataInt.mes = g.dataInt.ano = 0;
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

// Funcao que retorna o tamanho da Lista.
int tamanho(Lista *lista) {
    int count = 0;
    for(Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        count++;
    }
    return count;
}

// Procedimentos de insercao da Lista.
void inserirInicio(Lista *lista, Game game) {
    lista->primeiro->elemento = game;
    Game vazio = gamevazio();
    Celula *tmp = criarCelula(vazio);
    tmp->prox = lista->primeiro;
    lista->primeiro = tmp;
    tmp = NULL;
}
void inserirFim(Lista *lista, Game game) {
    lista->ultimo->prox = criarCelula(game);
    lista->ultimo = lista->ultimo->prox;
}
void inserir(Lista *lista, Game game, int pos) {
    int tam = tamanho(lista);
    if(pos < 0 || pos > tam) {
        printf("Posicao invalida\n");
    }
    else if(pos == 0) inserirInicio(lista, game);
    else if(pos == tam) inserirFim(lista, game);
    else {
        Celula *nova = criarCelula(game);
        Celula *tmp = lista->primeiro->prox;
        for(int i = 0; i < pos - 1; i++, tmp = tmp->prox);
        nova->prox = tmp->prox;
        tmp->prox = nova;
        tmp = nova = NULL;
    }
}

// Funcoes de remocao da Lista.
Game removerInicio(Lista *lista) {
    if(lista->primeiro == lista->ultimo) {
        printf("Lista vazia");
        return gamevazio();
    }
    else {
        Celula *tmp = lista->primeiro->prox;
        lista->primeiro->prox = tmp->prox;
        tmp->prox = NULL;
        Game resp = tmp->elemento;
        free(tmp);
        tmp = NULL;
        return resp;
    }
}
Game removerFim(Lista *lista) {
    if(lista->primeiro == lista->ultimo) {
        printf("Lista vazia");
        return gamevazio();
    }
    else {
        Celula *i;
        for(i = lista->primeiro->prox; i->prox != lista->ultimo; i = i->prox);
        Game resp = lista->ultimo->elemento;
        lista->ultimo = i;
        i = i->prox;
        lista->ultimo->prox = NULL;
        free(i);
        i = NULL;
        return resp;
    }
}
Game remover(Lista *lista, int pos) {
    int tam = tamanho(lista);
    Game resp;
    if(pos < 0 || pos >= tam) {
        printf("Posicao invalida\n");
        resp = gamevazio();
    }
    else if(pos == 0) resp = removerInicio(lista);
    else if(pos == tam - 1) resp = removerFim(lista);
    else {
        Celula *tmp = lista->primeiro->prox;
        for(int i = 0; i < pos - 1; i++, tmp = tmp->prox);
        Celula *rm = tmp->prox;
        resp = rm->elemento;
        tmp->prox = rm->prox;
        rm->prox = NULL;
        free(rm);
        rm = NULL;
    }
    return resp;
}

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

// Procedimento que mostra os elementos da Lista.
void mostrar(Lista *lista) {
    for(Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        imprimir(&i->elemento);
    }
}

// Procedimento que limpa o espaco de memoria.
void freeLista(Lista *lista) {
    Celula *i = lista->primeiro;
    while(i != NULL) {
        Celula *tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(lista);
}

int my_strlen(String str) {
    int count = 0;
    while(*(str.str + count) != '\0') {
        count++;
    }
    return count;
}

bool my_strcmp(String str1, String str2) {
    bool resp = true;
    if(my_strlen(str1) == my_strlen(str2)) {
        for(int i = 0; i < my_strlen(str1); i++) {
            if(*(str1.str + i) != *(str2.str + i)) {
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

// Main.
int main() {
    FILE *arq = fopen("../tmp/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    Lista *lista = criarLista();
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
        Game game;
        settar(&game , array);
        inserirFim(lista, game);
    }
    fclose(arq);
    // Testando com a entrada do tp04, quando receber a entrada do tp06 arrumar.
    String busca;
    scanf("%s", busca.str);
    String FIM;
    strcpy(FIM.str, "FIM");
    while (!my_strcmp(busca, FIM)) {
        int idBusca = atoi(busca.str);
        for (Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
            if (idBusca == i->elemento.id) {
                imprimir(&i->elemento);
                i = lista->ultimo;
            }
        }
        scanf("%s", busca.str);
    }
    freeLista(lista);
    return 0;
}