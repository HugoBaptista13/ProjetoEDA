/**
 * @file grafo.c
 * @author Hugo Baptista
 * @brief Implementação das funções para manipulação do grafo
 * @version 1.0
 * @date 2025-05-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturasDados.h"
#include "grafo.h"

Antena criarAntena (char freq, int x, int y) {
    Antena nova;
    nova.frequencia = freq;
    nova.x = x;
    nova.y = y;
    return nova;
}

Nefasto criarNefasto (int x, int y) {
    Nefasto novo;
    novo.x = x;
    novo.y = y;
    return novo;
}

Vertice* criarVertice(int codigo, int x, int y, char freq) {
    Vertice* novo = (Vertice*)malloc(sizeof(Vertice));
    if (!novo) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    novo->codigo = codigo;
    novo->antena = criarAntena (freq, x, y);
    novo->visitado = 0;
    novo->prox = NULL;
    novo->adjacentes = NULL;
    return novo;
}

Adjacente* criarAdjacente(int codigo) {
    Adjacente* novo = (Adjacente*)malloc(sizeof(Adjacente));
    if (!novo) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    novo->codigo = codigo;
    novo->prox = NULL;
    return novo;
}

int adicionarAdjacente(Grafo grafo, Vertice vertice, Vertice adjacente) {
    if (grafo.numVertices < 2) return 0;

    Vertice* atual = grafo.vertices;

    while (atual != NULL) {
        if (atual->codigo == vertice.codigo) {

            Adjacente* temp = atual->adjacentes;
            while (temp != NULL) {
                if (temp->codigo == adjacente.codigo) return 0;
                temp = temp->prox;
            }

            Adjacente* novoAdjacente = criarAdjacente(adjacente.codigo);
            if (novoAdjacente == NULL) return 0;
            
            novoAdjacente->prox = atual->adjacentes;
            atual->adjacentes = novoAdjacente;
            return 1;
        }
        atual = atual->prox;
    }
    
    return 0;
}