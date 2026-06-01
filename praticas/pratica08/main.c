#include <stdio.h>
#include "fila.h"

int main() {

    printf("=== TESTE 1: Criar fila ===\n");

    Fila* fila = fila_criar();

    if (fila_esta_vazia(fila)) {
        printf("A fila esta vazia!\n\n");
    }

    printf("=== TESTE 2: Enfileirando elementos ===\n");

    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);

    fila_exibir(fila);
    printf("\n");

    printf("=== TESTE 3: Consultar inicio da fila ===\n");

    printf("Inicio da fila: %d\n\n", fila_inicio(fila));

    printf("=== TESTE 4: Desenfileirar elemento ===\n");

    int removido = fila_desenfileirar(fila);

    if (removido != -1) {
        printf("Elemento removido: %d\n", removido);
    } else {
        printf("Falha ao desenfileirar!\n");
    }

    fila_exibir(fila);
    printf("\n");

    printf("=== TESTE 5: Desenfileirar varios elementos ===\n");

    printf("Removido: %d\n", fila_desenfileirar(fila));
    printf("Removido: %d\n", fila_desenfileirar(fila));

    fila_exibir(fila);
    printf("\n");

    printf("=== TESTE 6: Verificar inicio apos remocoes ===\n");

    printf("Novo inicio: %d\n\n", fila_inicio(fila));

    printf("=== TESTE 7: Verificar se fila esta vazia ===\n");

    if (fila_esta_vazia(fila)) {
        printf("A fila esta vazia!\n\n");
    } else {
        printf("A fila possui elementos!\n\n");
    }

    printf("=== TESTE 8: Esvaziando fila ===\n");

    while (!fila_esta_vazia(fila)) {
        printf("Removido: %d\n", fila_desenfileirar(fila));
    }

    printf("\n");

    printf("=== TESTE 9: Verificar fila vazia ===\n");

    if (fila_esta_vazia(fila)) {
        printf("A fila esta vazia!\n\n");
    }

    printf("=== TESTE 10: Destruir fila ===\n");

    fila_destruir(fila);

    printf("Fila destruida com sucesso!\n");

    return 0;
}