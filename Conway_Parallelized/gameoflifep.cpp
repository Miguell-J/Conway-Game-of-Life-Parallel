#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
#include "gameoflifep.h"

using namespace std;

void inicializarTabuleiro(int** tabuleiro, int N, int M) {
	// Inicializa o tabuleiro com c�lulas vivas e mortas de forma aleat�ria
#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		tabuleiro[i] = new int[M];
		for (int j = 0; j < M; j++) {
			tabuleiro[i][j] = rand() % 2;
		}
	}
}

int contarVizinhos(int** tabuleiro, int i, int j, int N, int M) {
    int contagem = 0;

    // Verifica as 8 dire��es ao redor da c�lula
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                contagem += tabuleiro[ni][nj];
            }
        }
    }

    return contagem;
}

void atualizarTabuleiro(int** tabuleiro, int N, int M) {
	// Cria uma c�pia tempor�ria do tabuleiro
	int** novoTabuleiro = new int* [N];
	for (int i = 0; i < N; i++) {
		novoTabuleiro[i] = new int[M];
	}
	// Atualiza o tabuleiro para a pr�xima gera��o
#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int vizinhos = contarVizinhos(tabuleiro, i, j, N, M);
			if (tabuleiro[i][j] == 1) {
				if (vizinhos < 2 || vizinhos > 3) {
					novoTabuleiro[i][j] = 0;
				}
				else {
					novoTabuleiro[i][j] = 1;
				}
			}
			else {
				if (vizinhos == 3) {
					novoTabuleiro[i][j] = 1;
				}
				else {
					novoTabuleiro[i][j] = 0;
				}
			}
		}
	}
	// Atualiza o tabuleiro original com a nova gera��o
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tabuleiro[i][j] = novoTabuleiro[i][j];
		}
	}
	// Libera a mem�ria alocada para o tabuleiro tempor�rio
	for (int i = 0; i < N; i++) {
		delete[] novoTabuleiro[i];
	}
	delete[] novoTabuleiro;
}

