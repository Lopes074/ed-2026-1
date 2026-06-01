#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t* anterior;
    int valor;
    struct no_t* proximo;
} No;

struct lista_t {
    No* primeiro;
    No* ultimo;
};

Lista* lista_criar() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }

    return lista;
}

void lista_inserir(Lista* lista, int valor) {
    if (lista == NULL) return;

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista->ultimo != NULL) {
        lista->ultimo->proximo = novo;
    } else {
        lista->primeiro = novo;
    }

    lista->ultimo = novo;
}

int lista_remover(Lista* lista, int valor) {
    if (lista == NULL) return 0;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {

            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                lista->primeiro = atual->proximo;
            }

            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            } else {
                lista->ultimo = atual->anterior;
            }

            free(atual);
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

int lista_buscar(Lista* lista, int valor) {
    if (lista == NULL) return 0;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

void lista_exibir(Lista* lista) {
    if (lista == NULL) return;

    No* atual = lista->primeiro;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

int lista_esta_vazia(Lista* lista) {
    if (lista == NULL) return 1;

    return lista->primeiro == NULL;
}

void lista_destruir(Lista* lista) {
    if (lista == NULL) return;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(lista);
}