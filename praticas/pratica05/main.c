#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

// Gerar vetor
void gerar_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000;
    }
}

// Copiar vetor
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// Imprimir vetor
void imprimir_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int original[TAM];
    int v1[TAM], v2[TAM];

    printf("=== TESTE 1: Gerar vetor aleatorio ===\n");
    gerar_vetor(original, TAM);
    imprimir_vetor(original, TAM);
    printf("\n");

    printf("=== TESTE 2: Copiar vetor ===\n");
    copiar_vetor(original, v1, TAM);
    copiar_vetor(original, v2, TAM);
    printf("Vetores copiados!\n\n");


    // LINEAR SEARCH

    int chave = original[rand() % TAM]; // pega um valor do vetor

    printf("=== TESTE 3: Linear Search ===\n");
    printf("Chave buscada: %d\n", chave);

    clock_t inicio = clock();

    int pos = linear_search(v1, TAM, chave);

    clock_t fim = clock();
    double tempo_linear = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if (pos != -1)
        printf("Encontrado na posicao: %d\n", pos);
    else
        printf("Nao encontrado\n");

    printf("Tempo: %f segundos\n\n", tempo_linear);


    // QUICK SELECT
    printf("=== TESTE 4: Quick Select ===\n");

    int k = TAM / 2; // mediana (aprox)

    inicio = clock();

    int resultado = quick_select(v2, 0, TAM - 1, k);

    fim = clock();
    double tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Elemento na posicao %d (ordenado): %d\n", k, resultado);
    printf("Tempo: %f segundos\n\n", tempo_quick);


    // COMPARAÇÃO

    printf("=== TESTE 5: Comparacao ===\n");
    printf("Linear Search: %f segundos\n", tempo_linear);
    printf("Quick Select:  %f segundos\n", tempo_quick);

    return 0;
}