#include <stdio.h>
#include "arvore_binaria.h"

int main() {

    printf("=== TESTE 1: Criar arvore ===\n");

    Arvore* arvore = arvore_criar();

    if (arvore_esta_vazia(arvore)) {
        printf("A arvore esta vazia!\n\n");
    }

    printf("=== TESTE 2: Inserindo elementos ===\n");

    arvore_inserir(arvore, 50);
    arvore_inserir(arvore, 30);
    arvore_inserir(arvore, 70);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 40);
    arvore_inserir(arvore, 60);
    arvore_inserir(arvore, 80);

    printf("Elementos inseridos com sucesso!\n\n");

    printf("=== TESTE 3: Exibicao em pre-ordem ===\n");

    arvore_exibir_pre_ordem(arvore);
    printf("\n");

    printf("=== TESTE 4: Exibicao em ordem ===\n");

    arvore_exibir_em_ordem(arvore);
    printf("\n");

    printf("=== TESTE 5: Exibicao em pos-ordem ===\n");

    arvore_exibir_pos_ordem(arvore);
    printf("\n");

    printf("=== TESTE 6: Verificar se arvore esta vazia ===\n");

    if (arvore_esta_vazia(arvore)) {
        printf("A arvore esta vazia!\n\n");
    } else {
        printf("A arvore possui elementos!\n\n");
    }

    printf("=== TESTE 7: Destruir arvore ===\n");

    arvore_destruir(arvore);

    printf("Arvore destruida com sucesso!\n");

    return 0;
}