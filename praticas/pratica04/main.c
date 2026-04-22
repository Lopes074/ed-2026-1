#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

// Função para gerar vetor aleatório
void gerar_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000; // números de 0 a 999
    }
}

// Função para copiar vetor
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// Função para imprimir vetor
void imprimir_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int original[TAM];
    int v1[TAM], v2[TAM], v3[TAM];

    printf("=== TESTE 1: Gerar vetor aleatorio ===\n");
    gerar_vetor(original, TAM);
    imprimir_vetor(original, TAM);
    printf("\n");

    printf("=== TESTE 2: Copiar vetor para testes ===\n");
    copiar_vetor(original, v1, TAM);
    copiar_vetor(original, v2, TAM);
    copiar_vetor(original, v3, TAM);
    printf("Vetores copiados com sucesso!\n\n");

    // BUBBLE SORT 
    printf("=== TESTE 3: Bubble Sort ===\n");
    clock_t inicio = clock();

    bubble_sort(v1, TAM);

    clock_t fim = clock();
    double tempo_bubble = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado (Bubble):\n");
    imprimir_vetor(v1, TAM);
    printf("Tempo de execucao: %f segundos\n\n", tempo_bubble);

    // SELECTION SORT 
    printf("=== TESTE 4: Selection Sort ===\n");
    inicio = clock();

    selection_sort(v2, TAM);

    fim = clock();
    double tempo_selection = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado (Selection):\n");
    imprimir_vetor(v2, TAM);
    printf("Tempo de execucao: %f segundos\n\n", tempo_selection);

    // QUICK SORT 
    printf("=== TESTE 5: Quick Sort ===\n");
    inicio = clock();

    quick_sort(v3, 0, TAM - 1);

    fim = clock();
    double tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado (Quick):\n");
    imprimir_vetor(v3, TAM);
    printf("Tempo de execucao: %f segundos\n\n", tempo_quick);

    // COMPARAÇÃO FINAL 
    printf("=== TESTE 6: Comparacao de desempenho ===\n");
    printf("Bubble Sort:   %f segundos\n", tempo_bubble);
    printf("Selection Sort:%f segundos\n", tempo_selection);
    printf("Quick Sort:    %f segundos\n", tempo_quick);

    return 0;
}