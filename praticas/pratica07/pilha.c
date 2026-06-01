#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

struct pilha_t {
    No* topo;
};

Pilha* pilha_criar() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    if (pilha != NULL) {
        pilha->topo = NULL;
    }

    return pilha;
}

void pilha_empilhar(Pilha* pilha, int valor) {
    if (pilha == NULL) return;

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = pilha->topo;

    pilha->topo = novo;
}

int pilha_desempilhar(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        return -1;
    }

    No* removido = pilha->topo;
    int valor = removido->valor;

    pilha->topo = removido->proximo;

    free(removido);

    return valor;
}

int pilha_topo(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        return -1;
    }

    return pilha->topo->valor;
}

int pilha_esta_vazia(Pilha* pilha) {
    if (pilha == NULL) return 1;

    return pilha->topo == NULL;
}

void pilha_exibir(Pilha* pilha) {
    if (pilha == NULL) return;

    No* atual = pilha->topo;

    printf("Pilha: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void pilha_destruir(Pilha* pilha) {
    if (pilha == NULL) return;

    No* atual = pilha->topo;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(pilha);
}