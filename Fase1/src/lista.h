/**
 * @file lista.h
 * @author Hugo Baptista
 * @brief Cabeçalhos das funções para manipulação das listas ligadas e da matriz
 * @version 1.0
 * @date 2025-03-25
 */

#include "estruturas.h"
/**
 * @brief MAX_LINHAS Tamanho máximo de linhas da matriz
 */
#define MAX_LINHAS 100
/**
 * @brief MAX_COLUNAS Tamanho máximo de colunas da matriz
 */
#define MAX_COLUNAS 100

/**
 * @brief Cria uma nova antena
 * 
 * @param freq Frequência da antena
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @return Antena* Apontador para a antena criada
 */
Antena* criarAntena(char freq, int x, int y);
/**
 * @brief Cria um novo efeito nefasto
 * 
 * @param x Coordenada x do efeito nefasto
 * @param y Coordenada y do efeito nefasto
 * @return Nefasto* Apontador para o efeito nefasto criado
 */
Nefasto* criarNefasto(int x, int y);
/**
 * @brief Insere uma antena na lista ligada
 * 
 * @param lista Apontador para a lista de antenas
 * @param freq Frequência da antena a inserir
 * @param x Coordenada x da antena a inserir
 * @param y Coordenada y da antena a inserir
 * @return int 1 se a antena foi inserida com sucesso, 0 caso contrário
 */
int inserirAntena(Antena** lista, char freq, int x, int y);
/**
 * @brief Insere um efeito nefasto na lista ligada
 * 
 * @param lista Apontador para a lista de efeitos nefastos
 * @param x Coordenada x do efeito nefasto a inserir
 * @param y Coordenada y do efeito nefasto a inserir
 * @return int 1 se o efeito nefasto foi inserido com sucesso, 0 caso contrário
 */
int inserirNefasto(Nefasto** lista, int x, int y);
/**
 * @brief Remove uma antena da lista ligada e liberta a memória
 * 
 * @param lista Apontador para a lista de antenas
 * @param x Coordenada x da antena a remover
 * @param y Coordenada y da antena a remover
 * @return int 1 se a antena foi removida com sucesso, 0 caso contrário
 */
int removerAntena(Antena** lista, int x, int y);
/**
 * @brief Ordena as antenas por ordem crescente de y
 * 
 * @param lista Lista de antenas
 * @return int 1 se as antenas foram ordenadas com sucesso
 */
int ordenarAntenas(Antena** lista);
/**
 * @brief Ordena os efeitos nefastos por ordem crescente de y
 * 
 * @param lista Lista de efeitos nefastos
 * @return int 1 se os efeitos nefastos foram ordenados com sucesso
 */
int ordenarEfeitos(Nefasto** lista);
/**
 * @brief Carrega as antenas de um ficheiro para uma lista ligada
 * 
 * @param filename Nome do ficheiro a carregar
 * @return Antena* Lista de antenas carregada
 */
Antena* carregarAntenas(const char* filename);
/**
 * @brief Calcula os efeitos nefastos das antenas
 * 
 * @param lista Lista de antenas
 * @return Nefasto* Lista de efeitos nefastos
 */
Nefasto* detetarEfeitosNefastos(Antena* lista);
/**
 * @brief Imprime a lista de antenas
 * 
 * @param lista Lista de antenas
 */
void imprimirAntenas(Antena* lista);
/**
 * @brief Imprime a lista de efeitos nefastos
 * 
 * @param lista Lista de efeitos nefastos
 */
void imprimirEfeitosNefastos(Nefasto* lista);
/**
 * @brief Carrega a matriz de um ficheiro
 * 
 * @param filename Nome do ficheiro a carregar
 * @return char** Matriz carregada
 */
char** carregarMatriz(const char* filename);
/**
 * @brief Liberta a memória alocada para a matriz
 * 
 * @param matriz Matriz a libertar
 * @param linhas Número de linhas da matriz
 */
void libertarMatriz(char** matriz, int linhas);
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
int inserirNaMatriz(char** matriz, int linhas, int colunas, int x, int y, char c);
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
int removerDaMatriz(char** matriz, int linhas, int colunas, int x, int y);
/**
 * @brief Limpa a matriz
 * 
 * @param matriz Matriz a limpar
 * @param linhas Número de linhas da matriz
 * @param colunas Número de colunas da matriz
 */
void limparMatriz(char** matriz, int linhas, int colunas);
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
int atualizarMatriz(char** matriz, int linhas, int colunas, Antena* lista, Nefasto* efeitos);
/**
 * @brief Imprime a matriz
 * 
 * @param matriz Matriz a imprimir
 * @param linhas Número de linhas da matriz
 */
void imprimirMatriz(char** matriz, int linhas);
/**
 * @brief Conta o número de linhas de um ficheiro
 * 
 * @param filename Nome do ficheiro a contar as linhas
 * @return int Número de linhas do ficheiro
 */
int contarLinhas(const char* filename);
/**
 * @brief Conta o número de colunas de um ficheiro
 * 
 * @param filename Nome do ficheiro a contar as colunas
 * @return int Número de colunas do ficheiro
 */
int contarColunas(const char* filename);
/**
 * @brief Guarda as listas ligadas num ficheiro
 * 
 * @param antenas Lista de antenas a guardar
 * @param efeitos Lista de efeitos nefastos a guardar
 * @param filename Nome do ficheiro a guardar
 * @return int 1 se as listas foram guardadas com sucesso, 0 caso contrário
 */
int guardarListas(Antena* antenas, Nefasto* efeitos, const char* filename);
/**
 * @brief Guarda a matriz num ficheiro
 * 
 * @param matriz Matriz a guardar
 * @param linhas Número de linhas da matriz
 * @param filename Nome do ficheiro a guardar
 * @return int 1 se a matriz foi guardada com sucesso, 0 caso contrário
 */
int guardarMatriz(char** matriz, int linhas, const char* filename);