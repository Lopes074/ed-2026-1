#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 1000000

int main() {
    // ALOCAÇÃO DINÂMICA (CORRETO)
    int *vetor = malloc(TAMANHO * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    srand(time(NULL));

    // Gerar vetor
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % TAMANHO;
    }

    // Mostrar só alguns valores
    printf("Primeiros elementos:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("...\n");

    printf("primeiro = %d, ultimo = %d\n", vetor[0], vetor[TAMANHO - 1]);

    int valor;
    printf("Digite um valor para buscar: ");
    scanf("%d", &valor);

    clock_t tempo_inicial = clock();
    int indice = busca_sequencia(vetor, TAMANHO, valor);
    clock_t tempo_final = clock();

    float duracao = (float)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("Tempo de busca: %.6f segundos\n", duracao);

    if (indice != -1) {
        printf("Valor encontrado no indice: %d\n", indice);
    } else {
        printf("Valor nao encontrado no vetor.\n");
    }

    printf("A busca pelo valor %d resultou no indice: %d\n", valor, indice);

    free(vetor);

    return 0;
}