#include <stdio.h>
#include "tabela_hash.h"

int main() {

    TabelaHash *tabela = criar(10);

    inserir(tabela, 3);
    inserir(tabela, 12);
    inserir(tabela, 20);
    inserir(tabela, 5);

    printf("A tabela hash tem %i elementos:\n", tabela->quantidade);

    for (int i = 0; i < tabela->tamanho; i++) {
        printf("[%d] -> ", i);
        No *atual = tabela->dados[i];
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->proximo;
        }
        printf("\n");
    }

    printf("\nProcure o valor 12:\n");

    int achei = buscar(tabela, 12);

    if (achei < 0)
        printf("Valor nao encontrado\n");
    else
        printf("Valor encontrado no indice %i\n", achei);

    remover(tabela, 5);

    printf("\nTabela apos remover o 5:\n");

    for (int i = 0; i < tabela->tamanho; i++) {
        printf("[%d] -> ", i);
        No *atual = tabela->dados[i];
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->proximo;
        }
        printf("\n");
    }

    destruir(tabela);

    return 0;
}