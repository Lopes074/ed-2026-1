#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

struct fila_t {
    No* inicio;
    No* fim;
};

Fila* fila_criar() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }

    return fila;
}

void fila_enfileirar(Fila* fila, int valor) {
    if (fila == NULL) return;

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

int fila_desenfileirar(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        return -1;
    }

    No* removido = fila->inicio;
    int valor = removido->valor;

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);

    return valor;
}

int fila_inicio(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        return -1;
    }

    return fila->inicio->valor;
}

void fila_exibir(Fila* fila) {
    if (fila == NULL) return;

    No* atual = fila->inicio;

    printf("Fila: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

int fila_esta_vazia(Fila* fila) {
    if (fila == NULL) return 1;

    return fila->inicio == NULL;
}

void fila_destruir(Fila* fila) {
    if (fila == NULL) return;

    No* atual = fila->inicio;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(fila);
}