#include <iostream>
#include <omp.h>
#include "gameoflifep.h"
#include "utils.h"

using namespace std;

int main() {

    _putenv_s("OMP_PROC_BIND", "true");
    _putenv_s("OMP_PLACES", "cores");

    omp_set_num_threads(8);

    int N = 200;  // Número de linhas
    int M = 200;  // Número de colunas

    // Criar e inicializar o tabuleiro
    int** tabuleiro = new int* [N];
    for (int i = 0; i < N; ++i) {
        tabuleiro[i] = new int[M]();
    }

    inicializarAleatorio(tabuleiro, N, M);  // Inicializa aleatoriamente


    double start_time = omp_get_wtime();

#pragma omp parallel for
    for (int gen = 0; gen < 100; gen++) {
#pragma omp critical
        {
            cout << "Geração " << gen << ":\n";
            imprimirTabuleiro(tabuleiro, N, M);  // Imprime o tabuleiro
            atualizarTabuleiro(tabuleiro, N, M);
        }
    }

    double end_time = omp_get_wtime();
    double parallel_time = end_time - start_time;
    cout << "Tempo paralelizado: " << parallel_time << " segundos\n";

    // Limpeza de memória
    for (int i = 0; i < N; ++i) {
        delete[] tabuleiro[i];
    }
    delete[] tabuleiro;

    return 0;
}