#include <stdio.h>
#include "lista_linear.h"

int main() {

    printf("=== TESTE 1: Criar lista ===\n");

    Lista* lista = lista_criar();

    if (lista_esta_vazia(lista)) {
        printf("A lista esta vazia!\n\n");
    }

    printf("=== TESTE 2: Inserindo elementos ===\n");

    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);

    lista_exibir(lista);
    printf("\n");

    printf("=== TESTE 3: Buscar elemento existente ===\n");

    if (lista_buscar(lista, 20)) {
        printf("Valor 20 encontrado!\n\n");
    } else {
        printf("Valor 20 nao encontrado!\n\n");
    }

    printf("=== TESTE 4: Buscar elemento inexistente ===\n");

    if (lista_buscar(lista, 99)) {
        printf("Valor 99 encontrado!\n\n");
    } else {
        printf("Valor 99 nao encontrado!\n\n");
    }

    printf("=== TESTE 5: Remover elemento existente ===\n");

    if (lista_remover(lista, 30)) {
        printf("Valor 30 removido com sucesso!\n");
    } else {
        printf("Falha ao remover 30!\n");
    }

    lista_exibir(lista);
    printf("\n");

    printf("=== TESTE 6: Remover elemento inexistente ===\n");

    if (lista_remover(lista, 100)) {
        printf("Valor 100 removido!\n");
    } else {
        printf("Valor 100 nao encontrado!\n");
    }

    lista_exibir(lista);
    printf("\n");

    printf("=== TESTE 7: Inserindo mais elementos ===\n");

    lista_inserir(lista, 50);
    lista_inserir(lista, 60);

    lista_exibir(lista);
    printf("\n");

    printf("=== TESTE 8: Verificar se lista esta vazia ===\n");

    if (lista_esta_vazia(lista)) {
        printf("A lista esta vazia!\n\n");
    } else {
        printf("A lista possui elementos!\n\n");
    }

    printf("=== TESTE 9: Destruir lista ===\n");

    lista_destruir(lista);

    printf("Lista destruida com sucesso!\n");

    return 0;
}