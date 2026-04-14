#include <stdio.h>
#include <time.h>

// Fatorial iterativo
long long fatorial_iterativo(int n) {
    if (n < 0) return -1;
    
    long long resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

// Fatorial recursivo
long long fatorial_recursivo(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    long long f;
    clock_t inicio, fim;
    double tempo;

    // TESTES NORMAIS

    f = fatorial_iterativo(-5);
    printf("Iterativo -5: %lld -> (%i)\n", f, (int)f == -1);

    f = fatorial_recursivo(-5);
    printf("Recursivo -5: %lld -> (%i)\n\n", f, (int)f == -1);

    f = fatorial_iterativo(5);
    printf("Iterativo 5: %lld -> (%i)\n", f, (int)f == 120);

    f = fatorial_recursivo(5);
    printf("Recursivo 5: %lld -> (%i)\n\n", f, (int)f == 120);

    // =========================
    // MEDIÇÃO DE TEMPO
    // =========================

    int n = 15; // valor para teste

    // 🔹 ITERATIVO
    inicio = clock();
    f = fatorial_iterativo(n);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Iterativo (%d!): %lld\n", n, f);
    printf("Tempo: %f segundos\n\n", tempo);

    // 🔹 RECURSIVO
    inicio = clock();
    f = fatorial_recursivo(n);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Recursivo (%d!): %lld\n", n, f);
    printf("Tempo: %f segundos\n\n", tempo);

    return 0;
}

/*
Complexidade:

Iterativo:
O(n)

Recursivo:
O(n)

Observação:
- Ambos percorrem de 1 até n
- O recursivo tem overhead de chamadas de função (pilha)
*/