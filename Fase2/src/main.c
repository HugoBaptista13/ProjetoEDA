/**
 * @file main.c
 * @author Hugo Baptista
 * @brief Implementação do programa principal
 * @version 1.0
 * @date 2025-05-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "estruturasDados.h"
#include "grafo.h"


/**
 * @brief Função principal do programa.
 * 
 * Esta função inicializa o grafo, lê os dados de um ficheiro e executa as operações de busca e listagem de caminhos.
 * 
 * @return int Retorna 0 quando chega ao fim do programa.
 */
int main() {
    
    // Criação de um grafo
    char nomeFicheiro[] = "antenas.txt";
    Grafo grafo = lerGrafo(nomeFicheiro);
    
    /* Teste de criação de grafo e adição de vértices e adjacentes
    Grafo grafo = criarGrafo();
    // Adiciona vértices
    adicionarVertice(&grafo, 1, 1, '0');
    adicionarVertice(&grafo, 2, 1, '0');
    adicionarVertice(&grafo, 3, 1, '0');
    adicionarVertice(&grafo, 4, 1, '0');
    adicionarVertice(&grafo, 5, 1, '0');
    adicionarVertice(&grafo, 6, 1, '0');
    
    // Adiciona adjacentes
    adicionarAdjacente(&grafo, 1, 2);
    adicionarAdjacente(&grafo, 2, 3);
    adicionarAdjacente(&grafo, 2, 4);
    adicionarAdjacente(&grafo, 2, 5);
    adicionarAdjacente(&grafo, 3, 6);
    adicionarAdjacente(&grafo, 4, 6);
    adicionarAdjacente(&grafo, 5, 6);
    */

    // Exibe o grafo
    escreverGrafo(grafo);
    
    printf("Depth First Search (DFS):\n");
    DFS(grafo, 1);
    desvisitarTodos(grafo);

    printf("\n\nBreadth First Search (BFS):\n");
    BFS(grafo, 1);
    desvisitarTodos(grafo);

    printf("\n\nListar todos os caminhos:\n");
    listarTodosCaminhos(grafo, 1, 4);

    return 0;
}
