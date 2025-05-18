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
 * @brief Estrutura de dados para as adjacências do grafo
 * @struct Adjacente
 * @param codigo Código do vértice adjacente
 * @param prox Apontador para a próxima adjacência
 * @attention codigo é um inteiro
 */
typedef struct Adjacente {
    int codigo;
    struct Adjacente* prox;
} Adjacente;

/**
 * @brief Estrutura de dados para os vértices do grafo
 * @struct Vertice
 * @param codigo Código do vértice
 * @param antena Estrutura de dados da antena
 * @param visitado Variável que indica se o vértice foi visitado (0 ou 1)
 * @param adjacentes Lista de adjacentes do vértice
 * @param prox Apontador para o próximo vértice
 * @attention codigo é um inteiro
 * @attention antena é uma estrutura de dados da antena com frequência, coordenadas x e y
 * @attention visitado é um inteiro (0 ou 1)
 * @attention adjacentes é um apontador para uma lista de ajdacências
 */
typedef struct Vertice {
    int codigo;
    Antena antena;
    int visitado;
    Adjacente* adjacentes;
    struct Vertice* prox;
} Vertice;

/**
 * @brief Estrutura de dados para o grafo
 * @struct Grafo
 * @param vertices Lista de vértices do grafo
 * @param numVertices Número de vértices no grafo
 * @attention vertices é um apontador para a lista de vértices
 * @attention numVertices é um inteiro
 */
typedef struct Grafo {
    Vertice* vertices;
    int numVertices;
} Grafo;

#endif