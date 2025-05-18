/**
 * @file grafo.h
 * @author Hugo Baptista
 * @brief Cabeçalhos das funções para manipulação do grafo
 * @version 1.0
 * @date 2025-05-13
 */

#include "estruturasDados.h"

#ifndef GRAFO_H
#pragma region Criação de Estruturas
/**
 * @brief Cria uma nova antena.
 * 
 * Esta função cria uma nova antena e a inicializa com a frequência e coordenadas especificadas.
 * 
 * @param freq Frequência da antena.
 * @param x Coordenada x da antena.
 * @param y Coordenada y da antena.
 * @return Antena Retorna a antena criada.
 */
Antena criarAntena(char freq, int x, int y);
/**
 * @brief Cria um novo efeito nefasto.
 * 
 * Esta função cria um novo efeito nefasto e o inicializa com as coordenadas especificadas.
 * 
 * @param x Coordenada x do efeito nefasto.
 * @param y Coordenada y do efeito nefasto.
 * @return Nefasto Retorna o efeito nefasto criado.
 */
Nefasto criarNefasto(int x, int y);
/**
 * @brief Cria um novo grafo.
 * 
 * Esta função inicializa um grafo vazio, com 0 vértices.
 * 
 * @return Grafo Retorna o grafo criado.
 */
Grafo criarGrafo();
/**
 * @brief Cria um novo vértice.
 * 
 * Esta função cria um novo vértice e o inicializa com o código, coordenadas e frequência especificados.
 * 
 * @param codigo O código do vértice.
 * @param x Coordenada x da antena.
 * @param y Coordenada y da antena.
 * @param freq Frequência da antena do vértice.
 * @return Vertice* Retorna um apontador para o vértice criado.
 * @attention O código é um inteiro, x e y são inteiros, freq é um char.
 */
Vertice* criarVertice(int codigo, int x, int y, char freq);
/**
 * @brief Cria uma nova adjacência.
 * 
 * Esta função cria uma nova adjacência e a inicializa com o código especificado.
 * 
 * @param codigo O código do vértice adjacente.
 * @return Adjacente* Retorna um apontador para a adjacência criada.
 * @attention O código é um inteiro.
 */
Adjacente* criarAdjacente(int codigo);
/**
 * @brief Adiciona um vértice ao grafo.
 * 
 * Esta função cria um novo vértice e o adiciona ao grafo. Se o grafo estiver vazio, o novo vértice se torna o primeiro.
 * 
 * @param grafo O grafo onde adicionar o vértice.
 * @param x Coordenada x da antena.
 * @param y Coordenada y da antena.
 * @param freq Frequência da antena do vértice.
 * @return int Retorna 1 se a operação foi realizada com sucesso, 0 caso contrário.
 */
#pragma endregion
#pragma region Funções de Manipulação do Grafo
int adicionarVertice(Grafo* grafo, int x, int y, char freq);
/**
 * @brief Adiciona um vértice adjacente a um vértice existente no grafo.
 * 
 * Esta função percorre todos os vértices do grafo e adiciona o vértice adjacente ao vértice especificado.
 * 
 * @param grafo O grafo onde adicionar o adjacente.
 * @param vertice O código do vértice onde adicionar o adjacente.
 * @param adjacente O código do vértice adjacente a ser adicionado.
 * @return int Retorna 1 se a operação foi realizada com sucesso, 0 caso contrário.
 */
int adicionarAdjacente(Grafo* grafo, int vertice, int adjacente);
/**
 * @brief Escreve o grafo na consola.
 * 
 * Esta função percorre todos os vértices do grafo e escreve na consola as suas informações.
 * 
 * @param grafo O grafo a ser escrito.
 */
void escreverGrafo(Grafo grafo);
/**
 * @brief Liberta a memória alocada para o grafo.
 * 
 * Esta função percorre todos os vértices do grafo e liberta a memória alocada para cada um deles.
 * 
 * @param grafo O grafo a ser libertado.
 * @return int Retorna 1 se a operação foi realizada com sucesso.
 */
int libertarGrafo(Grafo* grafo);
/**
 * @brief Lê um grafo a partir de um ficheiro.
 * 
 * Esta função lê um ficheiro de texto que contém a representação do grafo e cria o grafo correspondente.
 * 
 * @param nomeFicheiro O nome do ficheiro a ser lido.
 * @return Grafo Retorna o grafo lido do ficheiro.
 */
Grafo lerGrafo(const char* nomeFicheiro);
#pragma endregion
#pragma region Buscas
/**
 * @brief Desvisita um vértice do grafo.
 * 
 * Esta função percorre todos os vértices do grafo e define o campo visitado como 0 para o vértice especificado.
 * 
 * @param grafo O grafo onde desvisitar o vértice.
 * @param codigo O código do vértice a ser desvisitado.
 * @return int Retorna 1 se a operação foi realizada com sucesso, 0 caso contrário.
 */
int desvisitarVertice(Grafo grafo, int codigo);
/**
 * @brief Desvisita todos os vértices do grafo.
 * 
 * Esta função percorre todos os vértices do grafo e define o campo visitado como 0.
 * 
 * @param grafo O grafo onde desvisitar os vértices.
 * @return int Retorna 1 se a operação foi realizada com sucesso.
 */
int desvisitarTodos(Grafo grafo);
/**
 * @brief Realiza uma busca em profundidade (DFS) no grafo a partir de um vértice inicial.
 * 
 * Esta função percorre o grafo a partir do vértice inicial, visitando todos os vértices adjacentes.
 * 
 * @param grafo O grafo onde realizar a busca.
 * @param inicial O código do vértice inicial.
 * @return int Retorna 1 se a busca foi realizada com sucesso, 0 caso contrário.
 */
int DFS(Grafo grafo, int inicial);
/**
 * @brief Realiza uma busca em largura (BFS) no grafo a partir de um vértice inicial.
 * 
 * Esta função percorre o grafo a partir do vértice inicial, visitando todos os vértices adjacentes.
 * 
 * @param grafo O grafo onde realizar a busca.
 * @param inicial O código do vértice inicial.
 * @return int Retorna 1 se a busca foi realizada com sucesso, 0 caso contrário.
 */
int BFS(Grafo grafo, int inicial);
/**
 * @brief Lista todos os caminhos entre dois vértices no grafo.
 * 
 * Esta função imprime todos os caminhos possíveis entre dois vértices, considerando que as antenas têm a mesma frequência.
 * 
 * @param grafo O grafo onde procurar os caminhos.
 * @param inicial O código do vértice inicial.
 * @param final O código do vértice final.
 * @return int Retorna 1 se os caminhos foram listados com sucesso, 0 caso contrário.
 */
int listarTodosCaminhos(Grafo grafo, int inicial, int final);
#pragma endregion
#endif // GRAFO_H

