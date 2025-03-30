/**
 * @file estruturas.h
 * @author Hugo Baptista
 * @brief Definição das estruturas de dados
 * @version 1.0
 * @date 2025-03-25
 */

#ifndef ANTENAS_H
#define ANTENAS_H

/**
 * @brief Estrutura de dados para as antenas
 * @struct Antena
 * @param frequencia Frequência da antena
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @param prox Apontador para a próxima antena
 * @attention frequencia é um char, x e y são inteiros não negativos
 */
typedef struct Antena {
    char frequencia;
    int x, y;
    struct Antena *prox;
} Antena;

/**
 * @brief Estrutura de dados para os nefastos
 * @struct Nefasto
 * @param x Coordenada x do nefasto
 * @param y Coordenada y do nefasto
 * @param prox Apontador para o próximo nefasto
 * @attention x e y são inteiros não negativos
 */
typedef struct Nefasto {
    int x, y;
    struct Nefasto *prox;
} Nefasto;

#endif