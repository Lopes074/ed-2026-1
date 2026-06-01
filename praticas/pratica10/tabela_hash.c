#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

struct hash_t {
    No** tabela;
    int tamanho;
};

int funcao_hash(TabelaHash* hash, int valor) {
    return valor % hash->tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    TabelaHash* hash = (TabelaHash*) malloc(sizeof(TabelaHash));

    if (hash == NULL) return NULL;

    hash->tamanho = tamanho;

    hash->tabela = (No**) malloc(sizeof(No*) * tamanho);

    if (hash->tabela == NULL) {
        free(hash);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i] = NULL;
    }

    return hash;
}

void hash_inserir(TabelaHash* hash, int valor) {
    if (hash == NULL) return;

    int indice = funcao_hash(hash, valor);

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;
}

int hash_buscar(TabelaHash* hash, int valor) {
    if (hash == NULL) return 0;

    int indice = funcao_hash(hash, valor);

    No* atual = hash->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

int hash_remover(TabelaHash* hash, int valor) {
    if (hash == NULL) return 0;

    int indice = funcao_hash(hash, valor);

    No* atual = hash->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {

        if (atual->valor == valor) {

            if (anterior == NULL) {
                hash->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);

            return 1;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return 0;
}

void hash_exibir(TabelaHash* hash) {
    if (hash == NULL) return;

    printf("Tabela Hash:\n");

    for (int i = 0; i < hash->tamanho; i++) {

        printf("[%d]: ", i);

        No* atual = hash->tabela[i];

        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}

int hash_esta_vazia(TabelaHash* hash) {
    if (hash == NULL) return 1;

    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0;
        }
    }

    return 1;
}

void hash_destruir(TabelaHash* hash) {
    if (hash == NULL) return;

    for (int i = 0; i < hash->tamanho; i++) {

        No* atual = hash->tabela[i];

        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}