#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
} No;

struct arvore_t {
    No* raiz;
};

No* inserir_no(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));

        if (novo == NULL) return NULL;

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir_no(raiz->direita, valor);
    }

    return raiz;
}

void exibir_pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibir_pre_ordem(raiz->esquerda);
        exibir_pre_ordem(raiz->direita);
    }
}

void exibir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem(raiz->direita);
    }
}

void exibir_pos_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_pos_ordem(raiz->esquerda);
        exibir_pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void destruir_nos(No* raiz) {
    if (raiz != NULL) {
        destruir_nos(raiz->esquerda);
        destruir_nos(raiz->direita);
        free(raiz);
    }
}

Arvore* arvore_criar() {
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    if (arvore != NULL) {
        arvore->raiz = NULL;
    }

    return arvore;
}

void arvore_inserir(Arvore* arvore, int valor) {
    if (arvore == NULL) return;

    arvore->raiz = inserir_no(arvore->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore* arvore) {
    if (arvore == NULL) return;

    printf("Pre-ordem: ");
    exibir_pre_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore* arvore) {
    if (arvore == NULL) return;

    printf("Em ordem: ");
    exibir_em_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore* arvore) {
    if (arvore == NULL) return;

    printf("Pos-ordem: ");
    exibir_pos_ordem(arvore->raiz);
    printf("\n");
}

int arvore_esta_vazia(Arvore* arvore) {
    if (arvore == NULL) return 1;

    return arvore->raiz == NULL;
}

void arvore_destruir(Arvore* arvore) {
    if (arvore == NULL) return;

    destruir_nos(arvore->raiz);

    free(arvore);
}