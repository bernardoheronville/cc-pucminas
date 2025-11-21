#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Auxilio.
#define TAM_MAX 1000
#define TAM 50
int compara = 0;

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

// Struct No.
typedef struct No {
    Game elemento;
    struct No *esq, *dir;
    int nivel;
} No;

// Funcao que cria a No.
No *criarNo(Game game) {
    No *nova = (No*)malloc(sizeof(No));
    nova->elemento = game;
    nova->esq = nova->dir = NULL;
    nova->nivel = 1;
    return nova;
}

// Struct ArvoreAVL.
typedef struct ArvoreAVL {
    No *raiz;
} ArvoreAVL;

// Funcao que cria a ArvoreAVL.
ArvoreAVL *criarArvore() {
    ArvoreAVL *nova = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    nova->raiz = NULL;
    return nova;
}

// Funcao auxiliares da ArvoreAVL.
int getNivel(No *no) {
    if(no == NULL) return 0;
    else return no->nivel;
}
void setNivel(No *no) {
    if(getNivel(no->esq) > getNivel(no->dir)) no->nivel = 1 + getNivel(no->esq);
    else no->nivel = 1 + getNivel(no->dir);
}
int getFator(No *no) {
    return getNivel(no->dir) - getNivel(no->esq);
}

// Funcoes para balancear a arvore.
No *rotacionarDir(No *no) {
    No *noEsq = no->esq;
    No *noEsqDir = noEsq->dir;
    noEsq->dir = no;
    no->esq = noEsqDir;
    setNivel(no);
    setNivel(noEsq);
    return noEsq;
}
No *rotacionarEsq(No *no) {
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;
    noDir->esq = no;
    no->dir = noDirEsq;
    setNivel(no);
    setNivel(noDir);
    return noDir;
}
No *balancear(No *no) {
    if(no != NULL) {
        setNivel(no);
        int fator = getFator(no);
        if(fator == 2) {
            int fatorDir = getFator(no->dir);
            if(fatorDir == -1) no->dir = rotacionarDir(no->dir);
            return rotacionarEsq(no);
        }
        else if(fator == -2) {
            int fatorEsq = getFator(no->esq);
            if(fatorEsq == 1) no->esq = rotacionarEsq(no->esq);
            return rotacionarDir(no);
        }
    }
    return no;
}

// Procedimentos de insercao da ArvoreAVL.
No *inserirAux(Game x, No *i) {
    if(i == NULL) i = criarNo(x);
    else if(strcmp(x.nome.str, i->elemento.nome.str) > 0) i->dir = inserirAux(x, i->dir);
    else if(strcmp(x.nome.str, i->elemento.nome.str) < 0) i->esq = inserirAux(x, i->esq);
    else ;
    return balancear(i);
}
void inserir(Game x, ArvoreAVL *arvore) {
    arvore->raiz = inserirAux(x, arvore->raiz);
}

// Funcao de pesquisa da ArvoreAVL.
bool pesquisarNomeAux(String str, No *i) {
    bool resp = false;
    while(i != NULL) {
        compara++;
        if(strcmp(str.str, i->elemento.nome.str) > 0) {
            printf(" dir");
            i = i->dir;
        }
        else if(strcmp(str.str, i->elemento.nome.str) < 0) {
            printf(" esq");
            i = i->esq;
        }
        else {
            resp = true;
            i = NULL;
        }
    }
    return resp;
}
void pesquisarNome(String str, ArvoreAVL *arvore) {
    printf("%s: raiz", str.str);
    if(pesquisarNomeAux(str, arvore->raiz)) {
        printf(" SIM\n");
    }
    else {
        printf(" NAO\n");
    }
}

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

// Procedimento que mostra os elementos da ArvoreAVL.
void caminharCentralAux(No *i) {
    if(i != NULL) {
        caminharCentralAux(i->esq);
        imprimir(&i->elemento);
        caminharCentralAux(i->dir);
    }
}
void caminharCentral(ArvoreAVL *arvore) {
    caminharCentralAux(arvore->raiz);
}

// Procedimento que limpa o espaco de memoria da ArvoreAVL.
void freeArvoreAux(No *i) {
    if(i != NULL) {
        freeArvoreAux(i->esq);
        freeArvoreAux(i->dir);
        free(i);
    }
}
void freeArvore(ArvoreAVL *arvore) {
    freeArvoreAux(arvore->raiz);
    free(arvore);
}

// Main.
int main() {
    FILE *arq = fopen("../tmp/games.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    Game *game =(Game*)malloc(2000*sizeof(Game));
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
    ArvoreAVL *arvore = criarArvore();
    String buscaId;
    scanf("%s", buscaId.str);
    while(!my_strcmp(buscaId.str, "FIM")) {
        int idBusca = atoi(buscaId.str);
        for (int i = 0; i < jogos; i++) {
            if (idBusca == game[i].id) {
                inserir(game[i], arvore);
                i = jogos;
            }
        }
        scanf("%s", buscaId.str);
    }
    clock_t inicio = clock();
    String buscaNome;
    scanf(" %[^\n]", buscaNome.str);
    while(!my_strcmp(buscaNome.str, "FIM")) {
        pesquisarNome(buscaNome, arvore);
        scanf(" %[^\n]", buscaNome.str);
    }
    clock_t fim = clock();
    freeArvore(arvore);
    free(game);
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    FILE *log = fopen("892196_avl.txt", "w");
    if (log != NULL) {
        fprintf(log, "892196\t%.3fms\t%dcomparacoes\n", tempoExecucao * 1000, compara);
        fclose(log);
    } else {
        printf("Erro ao criar arquivo de log.\n");
    }
    return 0;
}