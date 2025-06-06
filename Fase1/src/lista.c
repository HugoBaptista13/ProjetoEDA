/**
 * @file lista.c
 * @author Hugo Baptista
 * @brief Implementação das funções para manipulação das listas ligadas e da matriz
 * @version 1.0
 * @date 2025-03-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "lista.h"


/**
 * @brief Cria uma nova antena
 * 
 * @param freq Frequência da antena
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @return Antena* Apontador para a antena criada
 */
Antena* criarAntena(char freq, int x, int y) {
    Antena* nova = (Antena*)malloc(sizeof(Antena));
    if (!nova) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    if (x >= MAX_COLUNAS || y >= MAX_LINHAS || x < 0 || y < 0) {
        free(nova);
        return NULL;
    }
    if (freq == '.' || freq == '#') { // Verifica se a frequência é válida
        free(nova);
        return NULL;
    }
    nova->frequencia = freq;
    nova->x = x;
    nova->y = y;
    nova->prox = NULL;
    return nova;
}

/**
 * @brief Cria um novo efeito nefasto
 * 
 * @param x Coordenada x do efeito nefasto
 * @param y Coordenada y do efeito nefasto
 * @return Nefasto* Apontador para o efeito nefasto criado
 */
Nefasto* criarNefasto(int x, int y) {
    Nefasto* novo = (Nefasto*)malloc(sizeof(Nefasto));
    if (!novo) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    if (x >= MAX_COLUNAS || y >= MAX_LINHAS || x < 0 || y < 0) {
        free(novo);
        return NULL;
    }
    novo->x = x;
    novo->y = y;
    novo->prox = NULL;
    return novo;
}

/**
 * @brief Insere uma antena na lista ligada
 * 
 * @param lista Apontador para a lista de antenas
 * @param freq Frequência da antena a inserir
 * @param x Coordenada x da antena a inserir
 * @param y Coordenada y da antena a inserir
 * @return int 1 se a antena foi inserida com sucesso, 0 caso contrário
 */
int inserirAntena(Antena** lista, char freq, int x, int y) {
    Antena* nova = criarAntena(freq, x, y);
    if (!nova) return 0;
    nova->prox = *lista;
    *lista = nova;
    ordenarAntenas(lista);
    return 1;
}

/**
 * @brief Insere um efeito nefasto na lista ligada
 * 
 * @param lista Apontador para a lista de efeitos nefastos
 * @param x Coordenada x do efeito nefasto a inserir
 * @param y Coordenada y do efeito nefasto a inserir
 * @return int 1 se o efeito nefasto foi inserido com sucesso, 0 caso contrário
 */
int inserirNefasto(Nefasto** lista, int x, int y) {
    Nefasto* novo = criarNefasto(x, y);
    if (!novo) return 0;
    for (Nefasto* atual = *lista; atual; atual = atual->prox) {
        if (atual->x == x && atual->y == y) {
            free(novo);
            return 0;
        }
    }
    novo->prox = *lista;
    *lista = novo;
    return 1;
}

/**
 * @brief Remove uma antena da lista ligada e liberta a memória
 * 
 * @param lista Apontador para a lista de antenas
 * @param x Coordenada x da antena a remover
 * @param y Coordenada y da antena a remover
 * @return int 1 se a antena foi removida com sucesso, 0 caso contrário
 */
int removerAntena(Antena** lista, int x, int y) {
    Antena* atual = *lista, *anterior = NULL;
    while (atual && (atual->x != x || atual->y != y)) {
        anterior = atual;
        atual = atual->prox;
    }
    if (!atual) return 0;
    if (!anterior) *lista = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    ordenarAntenas(lista);
    return 1;
}

/**
 * @brief Ordena as antenas por ordem crescente de y
 * 
 * @param lista Lista de antenas
 * @return int 1 se as antenas foram ordenadas com sucesso
 */
int ordenarAntenas(Antena** lista) {
    for (Antena* atual = *lista; atual; atual = atual->prox) {
        for (Antena* seguinte = atual->prox; seguinte; seguinte = seguinte->prox) {
            if (atual->y > seguinte->y) {
                char freq = atual->frequencia;
                int x = atual->x;
                int y = atual->y;
                atual->frequencia = seguinte->frequencia;
                atual->x = seguinte->x;
                atual->y = seguinte->y;
                seguinte->frequencia = freq;
                seguinte->x = x;
                seguinte->y = y;
            }
        }
    }
    return 1;
}

/**
 * @brief Ordena os efeitos nefastos por ordem crescente de y
 * 
 * @param lista Lista de efeitos nefastos
 * @return int 1 se os efeitos nefastos foram ordenados com sucesso
 */
int ordenarEfeitos(Nefasto** lista) {
    for (Nefasto* atual = *lista; atual; atual = atual->prox) {
        for (Nefasto* seguinte = atual->prox; seguinte; seguinte = seguinte->prox) {
            if (atual->y > seguinte->y) {
                int x = atual->x;
                int y = atual->y;
                atual->x = seguinte->x;
                atual->y = seguinte->y;
                seguinte->x = x;
                seguinte->y = y;
            }
        }
    }
    return 1;
}

/**
 * @brief Carrega as antenas de um ficheiro para uma lista ligada
 * 
 * @param filename Nome do ficheiro a carregar
 * @return Antena* Lista de antenas carregada
 */
Antena* carregarAntenas(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return NULL;
    }
    Antena* lista = NULL;
    char linha[100];
    for (int y = 0; fgets(linha, sizeof(linha), file); y++) {
        for (int x = 0; linha[x] != '\0' && linha[x] != '\n'; x++) {
            if (linha[x] != '.' && linha[x] != '#') inserirAntena(&lista, linha[x], x, y);
        }
    }
    fclose(file);
    ordenarAntenas(&lista);
    return lista;
}

/**
 * @brief Calcula os efeitos nefastos das antenas
 * 
 * @param lista Lista de antenas
 * @return Nefasto* Lista de efeitos nefastos
 */
Nefasto* detetarEfeitosNefastos(Antena* lista) {
    Nefasto* efeitos = NULL;
    for (Antena* a1 = lista; a1; a1 = a1->prox) {
        for (Antena* a2 = lista; a2; a2 = a2->prox) {
            if (a1 != a2 && a1->frequencia == a2->frequencia) {
                int dx = a1->x > a2->x ? a1->x - a2->x : a2->x - a1->x;
                int dy = a1->y > a2->y ? a1->y - a2->y : a2->y - a1->y;
                int ex1 = a1->x > a2->x ? a1->x + dx : a1->x - dx, ey1 = a1->y > a2->y ? a1->y + dy : a1->y - dy;
                int ex2 = a2->x > a1->x ? a2->x + dx : a2->x - dx, ey2 = a2->y > a1->y ? a2->y + dy : a2->y - dy;
                inserirNefasto(&efeitos, ex1, ey1);
                inserirNefasto(&efeitos, ex2, ey2);
            }
        }
    }
    ordenarEfeitos(&efeitos);
    return efeitos;
}

/**
 * @brief Imprime a lista de antenas
 * 
 * @param lista Lista de antenas
 */
void imprimirAntenas(Antena* lista) {
    printf("\nLista de Antenas:\n");
    printf("Frequencia | Coordenadas\n");
    printf("------------------------\n");
    while (lista) {
        printf("    %c      | (X:%d, Y:%d)\n", lista->frequencia, lista->x, lista->y);
        lista = lista->prox;
    }
    printf("------------------------\n");
}

/**
 * @brief Imprime a lista de efeitos nefastos
 * 
 * @param lista Lista de efeitos nefastos
 */
void imprimirEfeitosNefastos(Nefasto* lista) {
    printf("\nEfeitos Nefastos:\n");
    printf("Coordenadas\n");
    printf("------------\n");
    while (lista) {
        printf("# |  (X:%d, Y:%d)\n", lista->x, lista->y);
        lista = lista->prox;
    }
    printf("------------\n");
}

/**
 * @brief Liberta a memória alocada para a matriz
 * 
 * @param matriz Matriz a libertar
 * @param linhas Número de linhas da matriz
 */
void libertarMatriz(char** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/**
 * @brief Carrega a matriz de um ficheiro
 * 
 * @param filename Nome do ficheiro a carregar
 * @return char** Matriz carregada
 */
char** carregarMatriz(const char* filename) {
    int linhas = contarLinhas(filename);
    int colunas = contarColunas(filename);
    FILE* file = fopen(filename, "r");
    char **matriz = (char **)malloc(linhas * sizeof(char *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria!\n");
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (char *)malloc((colunas + 1) * sizeof(char)); // +1 para '\0'
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria!\n");
            fclose(file);
            return NULL ;
        }
        fscanf(file, "%s", matriz[i]); // Lê cada linha da matriz
    }
    fclose(file);
    return matriz;
}

/**
 * @brief Insere um caracter numa posição da matriz
 * 
 * @param matriz Matriz onde inserir o caracter
 * @param linhas Número de linhas da matriz	
 * @param colunas Número de colunas da matriz
 * @param x Coordenada x onde inserir o caracter
 * @param y Coordenada y onde inserir o caracter
 * @param c Caracter a inserir
 * @return int 1 se o caracter foi inserido com sucesso, 0 caso contrário
 */
int inserirNaMatriz(char** matriz, int linhas, int colunas, int x, int y, char c) {
    if (x >= MAX_COLUNAS || y >= MAX_LINHAS || x < 0 || y < 0 || x > colunas-1 || y > linhas-1) return 0;
    if (matriz[y][x] != '.') return 0;
    matriz[y][x] = c;
    return 1;
}

/**
 * @brief Remove um caracter da matriz
 * 
 * @param matriz Matriz onde remover o caracter
 * @param linhas Número de linhas da matriz
 * @param colunas Número de colunas da matriz
 * @param x Coordenada x onde remover o caracter
 * @param y Coordenada y onde remover o caracter
 * @return int 1 se o caracter foi removido com sucesso, 0 caso contrário
 */
int removerDaMatriz(char** matriz, int linhas, int colunas, int x, int y) {
    if (x >= MAX_COLUNAS || y >= MAX_LINHAS || x < 0 || y < 0 || x > colunas-1 || y > linhas-1) return 0;
    if (matriz[y][x] == '.') return 0;
    matriz[y][x] = '.';
    return 1;
}

/**
 * @brief Limpa a matriz
 * 
 * @param matriz Matriz a limpar
 * @param linhas Número de linhas da matriz
 * @param colunas Número de colunas da matriz
 */
void limparMatriz(char** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = '.';
        }
    }
}

/**
 * @brief Atualiza a matriz com as antenas e os efeitos nefastos
 * 
 * @param matriz Matriz a atualizar
 * @param linhas Número de linhas da matriz
 * @param colunas Número de colunas da matriz
 * @param lista Lista de antenas
 * @param efeitos Lista de efeitos nefastos
 * @return int 1 se a matriz foi atualizada com sucesso
 */
int atualizarMatriz(char** matriz, int linhas, int colunas, Antena* lista, Nefasto* efeitos) {
    limparMatriz(matriz, linhas, colunas);
    for (Antena* atual = lista; atual; atual = atual->prox) {
        inserirNaMatriz(matriz, linhas, colunas, atual->x, atual->y, atual->frequencia);
    }
    for (Nefasto* atual = efeitos; atual; atual = atual->prox) {
        inserirNaMatriz(matriz, linhas, colunas, atual->x, atual->y, '#');
    }
    return 1;
}

/**
 * @brief Conta o número de linhas de um ficheiro
 * 
 * @param filename Nome do ficheiro a contar as linhas
 * @return int Número de linhas do ficheiro
 */
int contarLinhas(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return 0;
    }
    int linhas = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') linhas++;
    }
    fclose(file);
    linhas = linhas > MAX_LINHAS ? MAX_LINHAS : linhas + 1;
    return linhas;
}

/**
 * @brief Conta o número de colunas de um ficheiro
 * 
 * @param filename Nome do ficheiro a contar as colunas
 * @return int Número de colunas do ficheiro
 */
int contarColunas(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return 0;
    }
    int colunas = 0;
    char c;
    while ((c = fgetc(file)) != '\n' && c != EOF) {
        colunas++;
    }
    fclose(file);
    colunas = colunas > MAX_COLUNAS ? MAX_COLUNAS : colunas;
    return colunas;
}

/**
 * @brief Imprime a matriz
 * 
 * @param matriz Matriz a imprimir
 * @param linhas Número de linhas da matriz
 */
void imprimirMatriz(char** matriz, int linhas) {
    printf("\n   MATRIZ\n");
    printf(" ----------\n\n");
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", matriz[i]);
    }
    printf("\n------------\n");
}

/**
 * @brief Guarda as listas ligadas num ficheiro
 * 
 * @param antenas Lista de antenas a guardar
 * @param efeitos Lista de efeitos nefastos a guardar
 * @param filename Nome do ficheiro a guardar
 * @return int 1 se as listas foram guardadas com sucesso, 0 caso contrário
 */
int guardarListas(Antena* antenas, Nefasto* efeitos, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return 0;
    }
    if (!antenas || !efeitos) {
        fprintf(file, "Nada a guardar!\n");
        fclose(file);
        return 1;
    }
    fprintf(file, "\nLista de Antenas:\n");
    fprintf(file, "Frequencia | Coordenadas\n");
    fprintf(file, "------------------------\n");
    for (Antena* atual = antenas; atual; atual = atual->prox) {
        fprintf(file, "    %c      | (X:%d, Y:%d)\n", atual->frequencia, atual->x, atual->y);
    }
    fprintf(file, "------------------------\n");
    fprintf(file, "\nEfeitos Nefastos:\n");
    fprintf(file, "Coordenadas\n");
    fprintf(file,"------------\n");
    for (Nefasto* atual = efeitos; atual; atual = atual->prox) {
        fprintf(file, "# |  (X:%d, Y:%d)\n", atual->x, atual->y);
    }
    fprintf(file, "------------\n");
    fclose(file);
    return 1;
}

/**
 * @brief Guarda a matriz num ficheiro
 * 
 * @param matriz Matriz a guardar
 * @param linhas Número de linhas da matriz
 * @param filename Nome do ficheiro a guardar
 * @return int 1 se a matriz foi guardada com sucesso, 0 caso contrário
 */
int guardarMatriz(char** matriz, int linhas, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return 0;
    }
    if (!matriz) {
        fprintf(file, "Nada a guardar!\n");
        fclose(file);
        return 1;
    }
    for (int i = 0; i < linhas; i++) {
        fprintf(file, "%s\n", matriz[i]);
    }
    fclose(file);
    return 1;
}