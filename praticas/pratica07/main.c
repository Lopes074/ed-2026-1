#include <stdio.h>
#include "pilha.h"

int main() {

    printf("=== TESTE 1: Criar pilha ===\n");

    Pilha* pilha = pilha_criar();

    if (pilha_esta_vazia(pilha)) {
        printf("A pilha esta vazia!\n\n");
    }

    printf("=== TESTE 2: Empilhando elementos ===\n");

    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);

    pilha_exibir(pilha);
    printf("\n");

    printf("=== TESTE 3: Consultar topo ===\n");

    printf("Topo da pilha: %d\n\n", pilha_topo(pilha));

    printf("=== TESTE 4: Desempilhar elemento ===\n");

    int removido = pilha_desempilhar(pilha);

    if (removido != -1) {
        printf("Elemento removido: %d\n", removido);
    } else {
        printf("Falha ao desempilhar!\n");
    }

    pilha_exibir(pilha);
    printf("\n");

    printf("=== TESTE 5: Desempilhar varios elementos ===\n");

    printf("Removido: %d\n", pilha_desempilhar(pilha));
    printf("Removido: %d\n", pilha_desempilhar(pilha));

    pilha_exibir(pilha);
    printf("\n");

    printf("=== TESTE 6: Verificar topo apos remocoes ===\n");

    printf("Novo topo: %d\n\n", pilha_topo(pilha));

    printf("=== TESTE 7: Verificar se pilha esta vazia ===\n");

    if (pilha_esta_vazia(pilha)) {
        printf("A pilha esta vazia!\n\n");
    } else {
        printf("A pilha possui elementos!\n\n");
    }

    printf("=== TESTE 8: Esvaziando pilha ===\n");

    while (!pilha_esta_vazia(pilha)) {
        printf("Removido: %d\n", pilha_desempilhar(pilha));
    }

    printf("\n");

    printf("=== TESTE 9: Verificar pilha vazia ===\n");

    if (pilha_esta_vazia(pilha)) {
        printf("A pilha esta vazia!\n\n");
    }

    printf("=== TESTE 10: Destruir pilha ===\n");

    pilha_destruir(pilha);

    printf("Pilha destruida com sucesso!\n");

    return 0;
}