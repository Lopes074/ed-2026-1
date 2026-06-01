#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int calcular_hash(TabelaHash *tabela_hash, int valor) {
    return valor % tabela_hash->tamanho;
}

TabelaHash *criar(int tamanho) {

    TabelaHash *tabela = (TabelaHash *) malloc(sizeof(TabelaHash));

    if (tabela == NULL) {
        return NULL;
    }

    tabela->dados = (No **) malloc(sizeof(No *) * tamanho);

    if (tabela->dados == NULL) {
        free(tabela);
        return NULL;
    }

    tabela->quantidade = 0;
    tabela->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {
        tabela->dados[i] = NULL;
    }

    return tabela;
}

void destruir(TabelaHash *tabela_hash) {
    for (int i = 0; i < tabela_hash->tamanho; i++) {
        No *atual = tabela_hash->dados[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(tabela_hash->dados);
    free(tabela_hash);
}

void inserir(TabelaHash *tabela_hash, int valor) {

    int hash = calcular_hash(tabela_hash, valor);
    
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return;
    
    novo->dado = valor;
    novo->proximo = tabela_hash->dados[hash];
    tabela_hash->dados[hash] = novo;
    tabela_hash->quantidade++;
}

int buscar(TabelaHash *tabela_hash, int valor) {

    int hash = calcular_hash(tabela_hash, valor);
    No *atual = tabela_hash->dados[hash];

    while (atual != NULL) {
        if (atual->dado == valor) {
            return hash;
        }
        atual = atual->proximo;
    }

    return -1;
}

void remover(TabelaHash *tabela_hash, int valor) {

    int hash = calcular_hash(tabela_hash, valor);
    No *atual = tabela_hash->dados[hash];
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            if (anterior == NULL) {
                tabela_hash->dados[hash] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            tabela_hash->quantidade--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

int tabela_vazia(TabelaHash *tabela_hash) {

    return tabela_hash != NULL &&
           tabela_hash->quantidade == 0;
}