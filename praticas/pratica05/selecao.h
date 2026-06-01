#ifndef SELECAO_H
#define SELECAO_H

// Busca linear (retorna o índice ou -1 se não encontrar)
int linear_search(int v[], int n, int chave);

// Quick Select (retorna o k-ésimo menor elemento)
int quick_select(int v[], int left, int right, int k);

#endif