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


/**
 * @brief Código do próximo vértice a ser adicionado ao grafo.
 */
int nextCod = 1;

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
Antena criarAntena (char freq, int x, int y) {
    Antena nova;
    nova.frequencia = freq;
    nova.x = x;
    nova.y = y;
    return nova;
}


/**
 * @brief Cria um novo efeito nefasto.
 * 
 * Esta função cria um novo efeito nefasto e o inicializa com as coordenadas especificadas.
 * 
 * @param x Coordenada x do efeito nefasto.
 * @param y Coordenada y do efeito nefasto.
 * @return Nefasto Retorna o efeito nefasto criado.
 */
Nefasto criarNefasto (int x, int y) {
    Nefasto novo;
    novo.x = x;
    novo.y = y;
    return novo;
}


/**
 * @brief Cria um novo grafo.
 * 
 * Esta função inicializa um grafo vazio, com 0 vértices.
 * 
 * @return Grafo Retorna o grafo criado.
 */
Grafo criarGrafo() {
    Grafo novo;
    novo.vertices = NULL;
    novo.numVertices = 0;
    return novo;
}


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


/**
 * @brief Cria uma nova adjacência.
 * 
 * Esta função cria uma nova adjacência e a inicializa com o código especificado.
 * 
 * @param codigo O código do vértice adjacente.
 * @return Adjacente* Retorna um apontador para a adjacência criada.
 * @attention O código é um inteiro.
 */
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
#pragma endregion



#pragma region Funções de Manipulação do Grafo

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
int adicionarVertice(Grafo* grafo, int x, int y, char freq) {
    Vertice* novo = criarVertice(nextCod++, x, y, freq);
    if (!novo) return 0;

    if (!grafo->vertices) {grafo->vertices = novo;}
    else {
        Vertice* tail = grafo->vertices;
        while (tail->prox) {tail = tail->prox;}
        tail->prox = novo;
    }
    grafo->numVertices++;
    return 1;
}


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
int adicionarAdjacente(Grafo* grafo, int vertice, int adjacente) {
    if (grafo->numVertices < 1) return 0;
    if (!grafo->vertices) return 0;
    if (!grafo->vertices->prox) return 0;

    for (Vertice* atual = grafo->vertices; atual; atual = atual->prox) {
        if (atual->codigo == vertice) {
            for (Adjacente* temp = atual->adjacentes; temp; temp = temp->prox) { if (temp->codigo == adjacente) return 0;}

            Adjacente* novoAdjacente = criarAdjacente(adjacente);
            if (!novoAdjacente) return 0;
            
            if (!atual->adjacentes) {atual->adjacentes = novoAdjacente;} 
            else {
                Adjacente* tail = atual->adjacentes;
                while (tail->prox) {tail = tail->prox;}
                tail->prox = novoAdjacente;
            }
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Escreve o grafo na consola.
 * 
 * Esta função percorre todos os vértices do grafo e imprime suas informações.
 * 
 * @param grafo O grafo a ser escrito.
 */
void escreverGrafo(Grafo grafo) {
    if (grafo.numVertices < 1) {
        printf("Grafo vazio!\n");
        return;
    }
    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        printf("Vertice %d: (X: %d, Y: %d) - FREQ: %c\n", atual->codigo, atual->antena.x, atual->antena.y, atual->antena.frequencia);
        if (atual->adjacentes == NULL) {
            printf("->  Sem adjacentes\n\n");
            continue;
        }
        for (Adjacente* adj = atual->adjacentes; adj; adj = adj->prox) {
            printf("->  Adjacente: %d\n", adj->codigo);
        }
        printf("\n");
    }
}


/**
 * @brief Liberta a memória alocada para o grafo.
 * 
 * Esta função percorre todos os vértices do grafo e liberta a memória alocada para cada um deles.
 * 
 * @param grafo O grafo a ser libertado.
 * @return int Retorna 1 se a operação foi realizada com sucesso.
 */
int libertarGrafo(Grafo* grafo) {
    for (Vertice* atual = grafo->vertices; atual; atual = atual->prox) {
        Vertice* temp = atual;
        for (Adjacente* adjAtual = atual->adjacentes; adjAtual; adjAtual = adjAtual->prox) {
            Adjacente* adjTemp = adjAtual;
            free(adjTemp);
        }
        free(temp);
    }
    grafo->vertices = NULL;
    grafo->numVertices = 0;
    return 1;
}


/**
 * @brief Lê um grafo a partir de um ficheiro.
 * 
 * Esta função lê um ficheiro de texto que contém a representação do grafo e cria o grafo correspondente.
 * 
 * @param nomeFicheiro O nome do ficheiro a ser lido.
 * @return Grafo Retorna o grafo lido do ficheiro.
 */
Grafo lerGrafo(const char* nomeFicheiro) {
    FILE* file = fopen(nomeFicheiro, "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return criarGrafo();
    }

    Grafo grafo = criarGrafo();

    char linha[100];
    for (int y = 0; fgets(linha, sizeof(linha), file); y++) {
        for (int x = 0; linha[x] != '\0' && linha[x] != '\n'; x++) {
            if (linha[x] != '.' && linha[x] != '#') 
                adicionarVertice(&grafo, x, y, linha[x]);
        }
    }

    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        for (Vertice* proximo = atual->prox; proximo; proximo = proximo->prox) {
            if (atual->antena.frequencia == proximo->antena.frequencia) {
                adicionarAdjacente(&grafo, atual->codigo, proximo->codigo);
                adicionarAdjacente(&grafo, proximo->codigo, atual->codigo);
            }
        }
    }

    fclose(file);
    return grafo;
}

#pragma endregion



#pragma region Buscas


/**
 * @brief Encontra um vértice no grafo pelo seu código.
 * @internal
 * Esta função percorre todos os vértices do grafo e retorna o vértice que possui o código especificado. Esta função é usada internamente por outras funções e não deve ser chamada diretamente.
 * 
 * @param grafo O grafo onde procurar o vértice.
 * @param codigo O código do vértice a ser encontrado.
 * @return Vertice* Retorna um apontador para o vértice encontrado ou NULL se não encontrado.
 */
static Vertice* encontrarVerticePorCod(Grafo grafo, int codigo) {
    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        if (atual->codigo == codigo) {
            return atual;
        }
    }
    return NULL;
}


/**
 * @brief Desvisita um vértice do grafo.
 * 
 * Esta função percorre todos os vértices do grafo e define o campo visitado como 0 para o vértice especificado.
 * 
 * @param grafo O grafo onde desvisitar o vértice.
 * @param codigo O código do vértice a ser desvisitado.
 * @return int Retorna 1 se a operação foi realizada com sucesso, 0 caso contrário.
 */
int desvisitarVertice(Grafo grafo, int codigo) {
    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        if (atual->codigo == codigo) {
            atual->visitado = 0;
            return 1;
        }
    }
    return 0;
}


/**
 * @brief Desvisita todos os vértices do grafo.
 * 
 * Esta função percorre todos os vértices do grafo e define o campo visitado como 0.
 * 
 * @param grafo O grafo onde desvisitar os vértices.
 * @return int Retorna 1 se a operação foi realizada com sucesso.
 */
int desvisitarTodos(Grafo grafo) {
    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        atual->visitado = 0;
    }
    return 1;
}


/**
 * @brief Realiza uma busca em profundidade (DFS) no grafo a partir de um vértice inicial.
 * 
 * Esta função percorre o grafo a partir do vértice inicial, visitando todos os vértices adjacentes.
 * 
 * @param grafo O grafo onde realizar a busca.
 * @param inicial O código do vértice inicial.
 * @return int Retorna 1 se a busca foi realizada com sucesso, 0 caso contrário.
 */
int DFS(Grafo grafo, int inicial) {
    if (grafo.numVertices < 1) return 0;
    if (!grafo.vertices) return 0;
    if (!grafo.vertices->prox) return 0;

    for (Vertice* atual = grafo.vertices; atual; atual = atual->prox) {
        if (atual->codigo == inicial && !atual->visitado) {
            atual->visitado = 1;
            printf("%c|%d: (X: %d, Y : %d)", atual->antena.frequencia, atual->codigo, atual->antena.x, atual->antena.y);
            for (Adjacente* adj = atual->adjacentes; adj; adj = adj->prox) {
                Vertice* vertAdj = encontrarVerticePorCod(grafo, adj->codigo);
                if (vertAdj && !vertAdj->visitado) {
                    printf(" -> ");
                    DFS(grafo, vertAdj->codigo);
                }
            }
            break;
        }
    }

    return 1;
}


/**
 * @brief Realiza uma busca em largura (BFS) no grafo a partir de um vértice inicial.
 * 
 * Esta função percorre o grafo a partir do vértice inicial, visitando todos os vértices adjacentes.
 * 
 * @param grafo O grafo onde realizar a busca.
 * @param inicial O código do vértice inicial.
 * @return int Retorna 1 se a busca foi realizada com sucesso, 0 caso contrário.
 */
int BFS(Grafo grafo, int inicial) {
    if (grafo.numVertices < 1) return 0;
    if (!grafo.vertices) return 0;
    if (!grafo.vertices->prox) return 0;
 
    int *fila = malloc(grafo.numVertices * sizeof(int));
    if (!fila) return 0;
    int front = 0, rear = 0;

    fila[rear++] = inicial;

    while (front < rear) {
        int codigo = fila[front++];
        Vertice* atual = encontrarVerticePorCod(grafo, codigo);
        if (atual && !atual->visitado) {
            atual->visitado = 1;
            printf("%c|%d: (X: %d, Y : %d)", atual->antena.frequencia, atual->codigo, atual->antena.x, atual->antena.y);
            for (Adjacente* adj = atual->adjacentes; adj; adj = adj->prox) {
                Vertice* vertAdj = encontrarVerticePorCod(grafo, adj->codigo);
                if (vertAdj && !vertAdj->visitado) {
                    int estaNaFila = 0;
                    for (int k = front; k < rear; k++) {
                        if (fila[k] == adj->codigo) {
                            estaNaFila = 1;
                            break;
                        }
                    }
                    if (!estaNaFila) fila[rear++] = adj->codigo;
                }
            }
            if (front < rear) {
                printf(" -> ");
            }
        }
    }
    free(fila);
    return 1;
}

/**
 * @brief Função auxiliar recursiva para listar todos os caminhos entre dois vértices.
 * @internal
 * Esta função é usada internamente por listarTodosCaminhos e não deve ser chamada diretamente.
 * 
 * @param grafo O grafo onde procurar os caminhos.
 * @param atual O vértice atual na busca.
 * @param final O vértice de destino.
 * @param caminho Array para armazenar o caminho atual.
 * @param profundidade Profundidade/índice atual no array caminho.
 * @return int Retorna 1 se um caminho foi encontrado, 0 caso contrário.
 */
static int listarTodosCaminhosAux(Grafo grafo, int atual, int final, int* caminho, int profundidade) {
    Vertice* vert = encontrarVerticePorCod(grafo, atual);
    if (!vert) return 0;

    vert->visitado = 1;
    caminho[profundidade] = atual;
    profundidade++;

    if (atual == final) {
        printf("Caminho: ");
        for (int i = 0; i < profundidade; i++) {
            printf("%d", caminho[i]);
            if (i < profundidade - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        if (!vert->adjacentes) return 0;
        for (Adjacente* adj = vert->adjacentes; adj; adj = adj->prox) {
            Vertice* vertAdj = encontrarVerticePorCod(grafo, adj->codigo);
            if (vertAdj && !vertAdj->visitado) {
                listarTodosCaminhosAux(grafo, adj->codigo, final, caminho, profundidade);
            }
        }
    }

    vert->visitado = 0; // Backtrack
    return 1;
}

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
int listarTodosCaminhos(Grafo grafo, int inicial, int final) {
    if (grafo.numVertices < 1) return 0;
    if (!grafo.vertices) return 0;
    if (!grafo.vertices->prox) return 0;
    
    Vertice* vertInicial = encontrarVerticePorCod(grafo, inicial);
    Vertice* vertFinal = encontrarVerticePorCod(grafo, final);
    if (!vertInicial || !vertFinal) {
        printf("Um dos vertices nao existe no grafo.\n");
        return 0;
    }
    if (vertInicial->antena.frequencia != vertFinal->antena.frequencia) {
        printf("As antenas nao tem a mesma frequencia.\n");
        return 0;
    }
    
    if (inicial == final) {
        printf("Caminho: %d\n", inicial);
        return 1;
    }

    int* caminho = malloc(grafo.numVertices * sizeof(int));
    if (!caminho) return 0;

    listarTodosCaminhosAux(grafo, inicial, final, caminho, 0);

    free(caminho);
    return 1;
}
#pragma endregion
