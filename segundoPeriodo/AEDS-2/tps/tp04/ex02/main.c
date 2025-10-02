#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct  
{
    int id;
    char *nome;
    char *data;
    int jogadores;
    float preco;
    char **idiomas;
    int notaEspecial;
    float notaUsuario;
    int conquistas;
    char **empresasPublicacao;
    char **empresasEstudios;
    char **categorias;
    char **generos;
    char **tags;
} Game;

int my_strlen(char *str) {
    int count = 0;
    while(*(str + count) != '\0') {
        count++;
    }
    return count;
}

bool my_strcmp(char *entrada1, char *entrada2) {
    bool resp = true;
    if(my_strlen(entrada1) == my_strlen(entrada2)) {
        for(int i = 0; i < my_strlen(entrada1); i++) {
            if(*(entrada1 + i) != *(entrada2 + i)) {
                resp = false;
                i = my_strlen(entrada1);
            }
        }
    }
    else {
        resp = false;
    }
    return resp;
}

void settar(Game *game, char **array) {
    if(*(array + 0) != NULL) game->id = atoi(*(array + 0));
    if(*(array + 1) != NULL) game->nome = strdup(*(array + 1));
    if(*(array + 2) != NULL) game->data = strdup(*(array + 2));
    if(*(array + 3) != NULL) game->jogadores = atoi(*(array + 3));
    if(*(array + 4) != NULL) game->preco = atof(*(array + 4));
    if(*(array + 5) != NULL) game->idiomas = strdup(*(array + 5));
    if(*(array + 6) != NULL) game->notaEspecial = atoi(*(array + 6));
    if(*(array + 7) != NULL) game->notaUsuario = atof(*(array + 7));
    if(*(array + 8) != NULL) game->conquistas = atoi(*(array + 8));
    if(*(array + 9) != NULL) game->empresasPublicacao = strdup(*(array + 9));
    if(*(array + 10) != NULL) game->empresasEstudios = strdup(*(array + 10));
    if(*(array + 11) != NULL) game->categorias = strdup(*(array + 11));
    if(*(array + 12) != NULL) game->generos = strdup(*(array + 12));
    if(*(array + 13) != NULL) game->tags = strdup(*(array + 13));
}

void imprimir(Game *game) {
    printf("=> %d ## %s ## %s ## %d ## %.2f ## [%s] ## %d ## %.2f ## %d ## [%s] ## [%s] ## [%s] ## [%s] ## [%s] ##",
    game->id, game->nome, game->data, game->jogadores, game->preco, game->idiomas, game->notaEspecial, game->notaUsuario,
    game->conquistas, game->empresasPublicacao, game->empresasEstudios, game->categorias, game->generos, game->tags
    );
}

int main() {
    FILE *arq = fopen("games.csv","r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    int jogos = 0;
    Game *game = (Game*)malloc(2000*sizeof(Game));
    char *entrada = (char*)malloc(1000*sizeof(char));
    while(fscanf(arq," %[^\n]",entrada) != EOF) {
        char **array = (char**)malloc(14*sizeof(char*));
        char *aux = (char)calloc(1000, sizeof(char));
        int contador = 0, auxPos = 0;
        bool aspas = false;
        for(int i = 0; i < my_strlen(entrada); i++) {
            char c = *(entrada + i);
            if(c == '"') {
                aspas = !aspas;
            }
            else if(c == ',' && !aspas) {
                *(aux + auxPos) = '\0';
                *(array + contador) = strdup(aux);
                contador++;
                auxPos = 0;
                strcpy(aux, "");
            }
            else {
                *(aux + auxPos) = c;
                auxPos++;
            }
        }
        *(aux + auxPos) = '\0';
        *(array + contador) = strdup(aux);
        settar((game + jogos), array);
        jogos++;
        for(int i = 0 ; i < 14; i++) {
            free((array + i));
        }
        free(aux);
    }
    fclose(arq);
    free(entrada);
    char *busca = (char*)malloc(100*sizeof(char));
    scanf("%s",busca);
    while(!my_strcmp(busca, "FIM")) {
        int idBusca = atoi(busca);
        for(int i = 0; i < jogos; i++) {
            if(idBusca == (game + i)->id) {
                imprimir(game + i);
                i = jogos;
            }
        }
        scanf("%s",busca);
    }
    free(busca);
    for(int i = 0; i < jogos; i++) {
        free((game + i)->nome);
        free((game + i)->data);
        free((game + i)->idiomas);
        free((game + i)->empresasPublicacao);
        free((game + i)->empresasEstudios);
        free((game + i)->categorias);
        free((game + i)->generos);
        free((game + i)->tags);
    }
    free(game);
    return 0;
}