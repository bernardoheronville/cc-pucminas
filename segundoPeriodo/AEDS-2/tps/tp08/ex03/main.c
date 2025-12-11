#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// Tamanhos definidos
#define TAM_MAX 2500 
#define TAM 50
#define HASH_SIZE 21

// Funções auxiliares de string
void trim_string(char *str) {
    if (!str) return;
    
    // Remove espaços no início
    char *start = str;
    while (*start && isspace((unsigned char)*start)) start++;
    
    // Move string para frente se necessário
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
    
    // Remove espaços no final
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    
    // Remove caracteres de nova linha
    str[strcspn(str, "\r\n")] = '\0';
}

int my_strlen(char *str) {
    int count = 0;
    if (!str) return 0;
    while(*(str + count) != '\0') {
        count++;
    }
    return count;
}

// Struct String
typedef struct String {
    char str[TAM_MAX];
} String;

// Struct Game
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
} Game;

Game gamevazio() {
    Game g;
    g.id = -1;
    strcpy(g.nome.str, "nenhum");
    strcpy(g.data.str, "01/01/2000");
    g.jogadores = 0;
    g.preco = 0.0f;
    g.num_idiomas = 0;
    strcpy(g.idiomas[0].str, "");
    g.notaEspecial = -1;
    g.notaUsuario = -1.0f;
    g.conquistas = 0;
    g.numEmpresasPublicacao = 0;
    strcpy(g.empresasPublicacao[0].str, "");
    g.numEmpresasEstudios = 0;
    strcpy(g.empresasEstudios[0].str, "");
    g.numCategorias = 0;
    strcpy(g.categorias[0].str, "");
    g.numGeneros = 0;
    strcpy(g.generos[0].str, "");
    g.numTags = 0;
    strcpy(g.tags[0].str, "");
    return g;
}

// Struct Celula
typedef struct Celula {
    Game elemento;
    struct Celula *prox;
} Celula;

Celula *criarCelula(Game game) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    if (!nova) return NULL;
    nova->elemento = game;
    nova->prox = NULL;
    return nova;
}

// Struct Lista
typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

Lista *criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if (!nova) return NULL;
    Game vazio = gamevazio();
    nova->primeiro = criarCelula(vazio);
    nova->ultimo = nova->primeiro;
    if (!nova->primeiro) {
        free(nova);
        return NULL;
    }
    return nova;
}

// Struct Hash
typedef struct Hash {
    Lista *tabela[HASH_SIZE];
    int tam;
} Hash;

Hash *criarHash() {
    Hash *nova = (Hash*)malloc(sizeof(Hash));
    if (!nova) return NULL;
    nova->tam = HASH_SIZE;
    for(int i = 0; i < nova->tam; i++) {
        nova->tabela[i] = criarLista();
        if (!nova->tabela[i]) {
            for(int j = 0; j < i; j++) free(nova->tabela[j]);
            free(nova);
            return NULL;
        }
    }
    return nova;
}

// Função de hash (SOMA ASCII % 21)
int h(String x, Hash *hash) {
    unsigned int soma = 0;
    for(int i = 0; i < my_strlen(x.str); i++) {
        soma += (unsigned char)x.str[i];
    }
    return soma % hash->tam;
}

// Inserir na hash
void inserir(Game x, Hash *hash) {
    int pos = h(x.nome, hash);
    Lista *lista = hash->tabela[pos];
    Celula *nova = criarCelula(x);
    if (!nova) return;
    lista->ultimo->prox = nova;
    lista->ultimo = nova;
}

// Pesquisar na hash - versão que retorna posição e resultado
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
    trim_string(x.str); // Limpa a string de busca
    bool encontrado;
    int pos = pesquisarPos(x, hash, &encontrado);
    printf("%s: (Posicao: %d) %s\n", x.str, pos, encontrado ? "SIM" : "NAO");
}

// Formatar strings (lista separada por vírgulas)
int formatar(String entrada, String saida[], bool apostrofo) {
    char aux[TAM_MAX];
    int contador = 0, auxPos = 0;
    bool dentro_aspas = false;
    
    for(int i = 0; i < my_strlen(entrada.str); i++) {
        char c = entrada.str[i]; 
        
        if (c == '"') {
            dentro_aspas = !dentro_aspas;
            continue;
        }
        
        if(c == ',' && !dentro_aspas) {
            aux[auxPos] = '\0';
            
            // Remove espaços extras
            char *start = aux;
            while (*start && isspace((unsigned char)*start)) start++;
            char *end = aux + auxPos - 1;
            while (end > aux && isspace((unsigned char)*end)) end--;
            if (end >= start) {
                int len = end - start + 1;
                strncpy(saida[contador].str, start, len);
                saida[contador].str[len] = '\0';
                
                // Remove aspas se existirem
                if (len > 0 && saida[contador].str[0] == '"') {
                    memmove(saida[contador].str, saida[contador].str + 1, len);
                    saida[contador].str[len-1] = '\0';
                }
                
                contador++;
            }
            
            auxPos = 0;
        } else {
            if(!(c == '[' || c == ']' || (apostrofo && c == '\''))) {
                aux[auxPos] = c;
                auxPos++;
            }
        }
    }
    
    // Último campo
    if (auxPos > 0) {
        aux[auxPos] = '\0';
        
        // Remove espaços extras
        char *start = aux;
        while (*start && isspace((unsigned char)*start)) start++;
        char *end = aux + auxPos - 1;
        while (end > aux && isspace((unsigned char)*end)) end--;
        if (end >= start) {
            int len = end - start + 1;
            strncpy(saida[contador].str, start, len);
            saida[contador].str[len] = '\0';
            
            // Remove aspas se existirem
            if (len > 0 && saida[contador].str[0] == '"') {
                memmove(saida[contador].str, saida[contador].str + 1, len);
                saida[contador].str[len-1] = '\0';
            }
            
            contador++;
        }
    }
    
    return contador;
}

// Formatar data (versão simplificada)
void setDataFormatada(String entrada, String *saida) {
    // Formato simples: já vem formatado ou em formato americano
    // Para simplificar, apenas copia
    strcpy(saida->str, entrada.str);
}

// Setters simplificados
void setId(Game *game, String valor) {
    trim_string(valor.str);
    game->id = atoi(valor.str);
}

void setNome(Game *game, String valor) {
    trim_string(valor.str);
    strcpy(game->nome.str, valor.str);
}

void setData(Game *game, String valor) {
    trim_string(valor.str);
    setDataFormatada(valor, &game->data);
}

void setJogadores(Game *game, String valor) {
    trim_string(valor.str);
    char aux[TAM_MAX];
    int pos = 0;
    for (int i = 0; i < strlen(valor.str); i++) {
        if (valor.str[i] >= '0' && valor.str[i] <= '9')
            aux[pos++] = valor.str[i];
    }
    aux[pos] = '\0';
    game->jogadores = atoi(aux);
}

void setPreco(Game *game, String valor) {
    trim_string(valor.str);
    if(strcmp(valor.str, "Free to Play") == 0 || strcmp(valor.str, "0.0") == 0 || 
       strlen(valor.str) == 0) {
        game->preco = 0.0f;
    } else {
        game->preco = atof(valor.str); 
    }  
}

void setIdiomas(Game *game, String valor) {
    trim_string(valor.str);
    game->num_idiomas = formatar(valor, game->idiomas, true);
}

void setNotaEspecial(Game *game, String valor) {
    trim_string(valor.str);
    if(my_strlen(valor.str) == 0) {
        game->notaEspecial = 0;
    } else {
        game->notaEspecial = atoi(valor.str);
    }
}

void setNotaUsuario(Game *game, String valor) {
    trim_string(valor.str);
    if(my_strlen(valor.str) == 0 || strcmp(valor.str, "tbd") == 0) {
        game->notaUsuario = 0.0f;
    } else {
        game->notaUsuario = atof(valor.str);
    }   
}

void setConquistas(Game *game, String valor) {
    trim_string(valor.str);
    if(my_strlen(valor.str) == 0) {
        game->conquistas = 0;
    } else {
        game->conquistas = atoi(valor.str);
    }
}

void setEmpresasPublicacao(Game *game, String valor) {
    trim_string(valor.str);
    game->numEmpresasPublicacao = formatar(valor, game->empresasPublicacao, false);
}

void setEmpresasEstudios(Game *game, String valor) {
    trim_string(valor.str);
    game->numEmpresasEstudios = formatar(valor, game->empresasEstudios, false);
}

void setCategorias(Game *game, String valor) {
    trim_string(valor.str);
    game->numCategorias = formatar(valor, game->categorias, false);
}

void setGeneros(Game *game, String valor) {
    trim_string(valor.str);
    game->numGeneros = formatar(valor, game->generos, false);
}

void setTags(Game *game, String valor) {
    trim_string(valor.str);
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

// Liberar memória da hash
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

// Função para parsear linha CSV
void parseCSVLine(char *line, String *array, int max_fields) {
    char buffer[TAM_MAX];
    strcpy(buffer, line);
    trim_string(buffer);
    
    int field = 0;
    int i = 0;
    int in_quotes = 0;
    int start = 0;
    
    while (i < strlen(buffer) && field < max_fields) {
        if (buffer[i] == '"') {
            in_quotes = !in_quotes;
        } else if (buffer[i] == ',' && !in_quotes) {
            int len = i - start;
            strncpy(array[field].str, buffer + start, len);
            array[field].str[len] = '\0';
            trim_string(array[field].str);
            
            // Remove aspas externas se existirem
            if (array[field].str[0] == '"' && array[field].str[strlen(array[field].str)-1] == '"') {
                memmove(array[field].str, array[field].str + 1, strlen(array[field].str) - 2);
                array[field].str[strlen(array[field].str) - 2] = '\0';
            }
            
            field++;
            start = i + 1;
        }
        i++;
    }
    
    // Último campo
    if (field < max_fields && start < strlen(buffer)) {
        int len = strlen(buffer) - start;
        strncpy(array[field].str, buffer + start, len);
        array[field].str[len] = '\0';
        trim_string(array[field].str);
        
        // Remove aspas externas se existirem
        if (array[field].str[0] == '"' && array[field].str[strlen(array[field].str)-1] == '"') {
            memmove(array[field].str, array[field].str + 1, strlen(array[field].str) - 2);
            array[field].str[strlen(array[field].str) - 2] = '\0';
        }
        
        field++;
    }
    
    // Preenche campos restantes com strings vazias
    for (int j = field; j < max_fields; j++) {
        strcpy(array[j].str, "");
    }
}

// Função para ler linhas do CSV tratando campos com vírgulas
int lerLinhaCSV(FILE *arq, String *array) {
    static char buffer[TAM_MAX * 2];
    
    if (fgets(buffer, sizeof(buffer), arq) == NULL) {
        return 0;
    }
    
    // Remove nova linha
    buffer[strcspn(buffer, "\r\n")] = '\0';
    
    // Se a linha estiver vazia, pula
    if (strlen(buffer) == 0) {
        return 0;
    }
    
    parseCSVLine(buffer, array, 14);
    return 1;
}

// Main
int main() {
    // Abrir arquivo CSV
    FILE *arq = fopen("/tmp/games.csv", "r");
    if (!arq) {
        // Tentar caminhos alternativos
        arq = fopen("games.csv", "r");
        if (!arq) {
            arq = fopen("../tmp/games.csv", "r");
            if (!arq) {
                printf("Erro ao abrir o arquivo games.csv\n");
                return 1;
            }
        }
    }

    // Alocar memória para jogos
    Game *game = (Game*)malloc(4500 * sizeof(Game));
    if (!game) {
        printf("Erro ao alocar memória para jogos\n");
        fclose(arq);
        return 1;
    }
    
    int jogos = 0;
    String cabecalho;
    
    // Ler cabeçalho
    if (fgets(cabecalho.str, sizeof(cabecalho.str), arq) == NULL) {
        printf("Arquivo vazio\n");
        fclose(arq);
        free(game);
        return 1;
    }
    
    // Ler dados
    String array[14];
    while (lerLinhaCSV(arq, array) && jogos < 4500) {
        settar(&game[jogos], array);
        jogos++;
    }
    fclose(arq);
    
    // Criar hash
    Hash *hash = criarHash();
    if (!hash) {
        printf("Erro ao criar hash table\n");
        free(game);
        return 1;
    }
    
    // Ler IDs e inserir na hash
    char buscaIdStr[100];
    scanf("%s", buscaIdStr);
    
    while(strcmp(buscaIdStr, "FIM") != 0) {
        int idBusca = atoi(buscaIdStr);
        bool encontrado = false;
        
        for (int i = 0; i < jogos; i++) {
            if (idBusca == game[i].id) {
                inserir(game[i], hash);
                encontrado = true;
                break;
            }
        }
        
        if (!encontrado) {
            // Se não encontrou pelo ID, não faz nada (não insere)
        }
        
        scanf("%s", buscaIdStr);
    }
    
    // Limpar buffer do stdin
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // Iniciar timer
    clock_t inicio = clock();
    
    // Buscar nomes
    char linha[TAM_MAX];
    
    // Ler primeira linha após "FIM"
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        freeHash(hash);
        free(game);
        return 0;
    }
    
    trim_string(linha);
    
    while(strcmp(linha, "FIM") != 0) {
        String buscaNome;
        strcpy(buscaNome.str, linha);
        pesquisar(buscaNome, hash);
        
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        trim_string(linha);
    }
    
    // Parar timer
    clock_t fim = clock();
    
    // Liberar memória
    freeHash(hash);
    free(game);
    
    // Calcular tempo e criar log
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    FILE *log = fopen("892196_hashIndireta.txt", "w");
    if (log != NULL) {
        fprintf(log, "892196\t%.0fms\t%d\n", tempoExecucao * 1000, jogos);
        fclose(log);
    }
    
    return 0;
}