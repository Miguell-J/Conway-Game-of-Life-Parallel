#include <iostream>
#include "utils.h"
#include <cstdlib>

void imprimirTabuleiro(int** tabuleiro, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << (tabuleiro[i][j] ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

void inicializarAleatorio(int** tabuleiro, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tabuleiro[i][j] = rand() % 2;  // Gera 0 ou 1 aleatoriamente
        }
    }
}