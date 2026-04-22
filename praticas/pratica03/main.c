#include <stdio.h>
#include "conta.h"

int main() {
    printf("=== TESTE 1: Criar conta ===\n");
    Conta* c1 = conta_criar(101);
    printf("Saldo inicial: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 2: Deposito ===\n");
    conta_depositar(c1, 200.0);
    printf("Saldo apos deposito de 200: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 3: Saque valido ===\n");
    if (conta_sacar(c1, 50.0)) {
        printf("Saque de 50 realizado!\n");
    } else {
        printf("Falha no saque!\n");
    }
    printf("Saldo atual: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 4: Saque com saldo insuficiente ===\n");
    if (conta_sacar(c1, 500.0)) {
        printf("Saque realizado!\n");
    } else {
        printf("Saldo insuficiente!\n");
    }
    printf("Saldo atual: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 5: Deposito invalido (negativo) ===\n");
    conta_depositar(c1, -100.0);
    printf("Saldo apos tentativa invalida: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 6: Saque invalido (negativo) ===\n");
    if (conta_sacar(c1, -20.0)) {
        printf("Saque realizado!\n");
    } else {
        printf("Valor invalido para saque!\n");
    }
    printf("Saldo atual: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 7: Multiplas operacoes ===\n");
    conta_depositar(c1, 300.0);
    conta_sacar(c1, 100.0);
    conta_depositar(c1, 50.0);
    printf("Saldo final apos varias operacoes: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 8: Segunda conta ===\n");
    Conta* c2 = conta_criar(202);
    conta_depositar(c2, 500.0);
    printf("Saldo conta 2: %.2f\n", conta_ver_saldo(c2));
    printf("Saldo conta 1: %.2f\n\n", conta_ver_saldo(c1));

    printf("=== TESTE 9: Liberando memoria ===\n");
    conta_destruir(c1);
    conta_destruir(c2);
    printf("Contas destruidas com sucesso!\n");

    return 0;
}