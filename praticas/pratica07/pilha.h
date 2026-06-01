#ifndef PILHA_H
#define PILHA_H

typedef struct pilha_t Pilha;

Pilha* pilha_criar();

void pilha_empilhar(Pilha* pilha, int valor);

int pilha_desempilhar(Pilha* pilha);

int pilha_topo(Pilha* pilha);

int pilha_esta_vazia(Pilha* pilha);

void pilha_exibir(Pilha* pilha);

void pilha_destruir(Pilha* pilha);

#endif