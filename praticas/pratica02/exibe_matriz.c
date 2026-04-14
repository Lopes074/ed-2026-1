#include <stdio.h>
#include <time.h>

// Dois laços
void exibe_duplo(int m[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Um laço
void exibe_simples(int m[10][10]) {
    for (int i = 0; i < 100; i++) {
        printf("%d ", m[i / 10][i % 10]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

int main() {
    int m[10][10];
    double tempo1, tempo2;
    clock_t inicio, fim;

    // Preenchimento
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m[i][j] = i * 10 + j + 1;
        }
    }


    // Dois loops
    inicio = clock();
    exibe_duplo(m);
    fim = clock();
    tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("-------------------------------------\n");


    // Um loop
    inicio = clock();
    exibe_simples(m);
    fim = clock();
    tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("-------------------------------------\n");

    printf("Tempo dois loops: %f segundos\n", tempo1);
    printf("Tempo um loop: %f segundos\n", tempo2);

    return 0;
}

/*
Complexidade:
- exibe_duplo: O(n²)
- exibe_simples: O(n²)
*/