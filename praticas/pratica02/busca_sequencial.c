#include <stdio.h>
#include <time.h>

int busca_sequencial(int v[], int tamanho, int valor) {

    for (int i = 0; i < tamanho; i++) {
        if (v[i] == valor)
            return i;
    }

    return -1;
}

int main() {
    int v[100];
    int chave;

    // Preenchendo vetor
    for (int i = 0; i < 100; i++) {
        v[i] = i + 1;
    }

    clock_t inicio, fim;
    double tempo;

    // 🔹 MELHOR CASO (primeira posição)
    inicio = clock();
    chave = busca_sequencial(v, 100, 1);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Melhor caso (valor = 1):\n");
    printf("Posicao: %d\n", chave);
    printf("Tempo: %f segundos\n\n", tempo);

    // 🔹 CASO MÉDIO (meio do vetor)
    inicio = clock();
    chave = busca_sequencial(v, 100, 50);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Caso medio (valor = 50):\n");
    printf("Posicao: %d\n", chave);
    printf("Tempo: %f segundos\n\n", tempo);

    // 🔹 PIOR CASO (última posição)
    inicio = clock();
    chave = busca_sequencial(v, 100, 100);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Pior caso (valor = 100):\n");
    printf("Posicao: %d\n", chave);
    printf("Tempo: %f segundos\n\n", tempo);

    // 🔹 PIOR CASO (valor inexistente)
    inicio = clock();
    chave = busca_sequencial(v, 100, 101);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Pior caso (valor inexistente):\n");
    printf("Posicao: %d\n", chave);
    printf("Tempo: %f segundos\n\n", tempo);

    return 0;
}

/*
Complexidade:

Melhor caso: O(1)
Caso médio: O(n)
Pior caso: O(n)
*/