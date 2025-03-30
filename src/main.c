/**
 * @file main.c
 * @author Hugo Baptista
 * @brief Implementação do programa principal
 * @version 1.0
 * @date 2025-03-25
 */

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "lista.h"

int main() {
    char ficheiroIN[] = "antenas.txt";
    char ficheiro_listasOUT[] = "listasOUT.txt";
    char ficheiro_matrizOUT[] = "matrizOUT.txt";
    Antena* lista = carregarAntenas(ficheiroIN);
    if (!lista) return 1;
    imprimirAntenas(lista);
    
    char** matriz = carregarMatriz(ficheiroIN);
    if (!matriz) return 1;
    int linhas = contarLinhas(ficheiroIN);
    int colunas = contarColunas(ficheiroIN);
    imprimirMatriz(matriz, linhas);
    
    // Teste de inserção
    inserirAntena(&lista, 'B', 5, 5);
    printf("\nApos Insercao:\n");
    imprimirAntenas(lista);
    
    // Detecção de efeitos nefastos
    Nefasto* efeitos = detetarEfeitosNefastos(lista);
    imprimirEfeitosNefastos(efeitos);

    // Atualização da matriz
    atualizarMatriz(matriz, linhas, colunas, lista, efeitos);
    printf("\nApos Atualizacao:\n");
    imprimirMatriz(matriz, linhas);
    
    // Teste de remoção
    removerAntena(&lista, 5, 5);
    removerAntena(&lista, 6, 5);
    printf("\nApos Remocao:\n");
    imprimirAntenas(lista);
    efeitos = detetarEfeitosNefastos(lista);
    imprimirEfeitosNefastos(efeitos);
    atualizarMatriz(matriz, linhas, colunas, lista, efeitos);
    imprimirMatriz(matriz, linhas);

    // Guardar listas e matriz
    guardarListas(lista, efeitos, ficheiro_listasOUT);
    guardarMatriz(matriz, linhas, ficheiro_matrizOUT);
    
    libertarMatriz(matriz, linhas);
    
    return 0;
}
