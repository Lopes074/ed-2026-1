#include <stdio.h>
#include "tabela_hash.h"

int main() {

    printf("=== TESTE 1: Criar tabela hash ===\n");

    TabelaHash* hash = hash_criar(10);

    if (hash_esta_vazia(hash)) {
        printf("A tabela hash esta vazia!\n\n");
    }

    printf("=== TESTE 2: Inserindo elementos ===\n");

    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 35);
    hash_inserir(hash, 10);
    hash_inserir(hash, 22);
    hash_inserir(hash, 42);

    hash_exibir(hash);
    printf("\n");

    printf("=== TESTE 3: Buscar elemento existente ===\n");

    if (hash_buscar(hash, 25)) {
        printf("Valor 25 encontrado!\n\n");
    } else {
        printf("Valor 25 nao encontrado!\n\n");
    }

    printf("=== TESTE 4: Buscar elemento inexistente ===\n");

    if (hash_buscar(hash, 99)) {
        printf("Valor 99 encontrado!\n\n");
    } else {
        printf("Valor 99 nao encontrado!\n\n");
    }

    printf("=== TESTE 5: Remover elemento existente ===\n");

    if (hash_remover(hash, 35)) {
        printf("Valor 35 removido com sucesso!\n");
    } else {
        printf("Falha ao remover 35!\n");
    }

    hash_exibir(hash);
    printf("\n");

    printf("=== TESTE 6: Remover elemento inexistente ===\n");

    if (hash_remover(hash, 100)) {
        printf("Valor 100 removido!\n");
    } else {
        printf("Valor 100 nao encontrado!\n");
    }

    hash_exibir(hash);
    printf("\n");

    printf("=== TESTE 7: Verificar se tabela hash esta vazia ===\n");

    if (hash_esta_vazia(hash)) {
        printf("A tabela hash esta vazia!\n\n");
    } else {
        printf("A tabela hash possui elementos!\n\n");
    }

    printf("=== TESTE 8: Destruir tabela hash ===\n");

    hash_destruir(hash);

    printf("Tabela hash destruida com sucesso!\n");

    return 0;
}