/**
 * @file estruturas.h
 * @author Hugo Baptista
 * @brief Definição das estruturas de dados
 * @version 1.0
 * @date 2025-05-13
 */

#ifndef ANTENAS_H
#define ANTENAS_H

/**
 * @brief Estrutura de dados para as antenas
 * @struct Antena
 * @param frequencia Frequência da antena
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @attention frequencia é um char, x e y são inteiros não negativos
 */
typedef struct Antena {
    char frequencia;
    int x, y;
} Antena;

/**
 * @brief Estrutura de dados para os nefastos
 * @struct Nefasto
 * @param x Coordenada x do nefasto
 * @param y Coordenada y do nefasto
 * @attention x e y são inteiros não negativos
 */
typedef struct Nefasto {
    int x, y;
} Nefasto;

/**
 * @brief Estrutura de dados para uma lista de antenas
 * @struct Antenas
 * @param antena Estrutura de dados da antena
 * @param prox Apontador para a próxima antena
 */
typedef struct Antenas {
    Antena antena;
    struct Antenas *prox;
} Antenas;

/**
 * @brief Estrutura de dados para uma lista de nefastos
 * @struct Nefastos
 * @param nefasto Estrutura de dados do nefasto
 * @param prox Apontador para o próximo nefasto
 */
typedef struct Nefastos {
    Nefasto nefasto;
    struct Nefastos *prox;
} Nefastos;

typedef struct Adjacente {
    int codigo;
    struct Adjacente* prox;
} Adjacente;

typedef struct Vertice {
    int codigo;
    Antena antena;
    int visitado;
    Adjacente* adjacentes;
    struct Vertice* prox;
} Vertice;

typedef struct Grafo {
    Vertice* vertices;
    int numVertices;
} Grafo;

#endif