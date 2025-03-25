#ifndef GAMEOFLIFEP_H
#define GAMEOFLIFEP_H

void inicializarTabuleiro(int** tabuleiro, int N, int M);
int contarVizinhos(int** tabuleiro, int i, int j, int N, int M);
void atualizarTabuleiro(int** tabuleiro, int N, int M);

#endif // GAMEOFLIFE_H
