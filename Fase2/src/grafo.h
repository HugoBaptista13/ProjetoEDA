/**
 * @file grafo.h
 * @author Hugo Baptista
 * @brief Cabeçalhos das funções para manipulação do grafo
 * @version 1.0
 * @date 2025-05-13
 */

#include "estruturasDados.h"

Antena criarAntena(char freq, int x, int y);
Nefasto criarNefasto(int x, int y);

Vertice* criarVertice(int codigo, int x, int y, char freq);
Adjacente* criarAdjacente(int codigo);


