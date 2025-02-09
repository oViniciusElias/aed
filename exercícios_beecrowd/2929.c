/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2929
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
  int *elementos;
  int *menores;
  int topo;
  int capacidade;
} Pilha;

void Inicializar(Pilha *pilha, int capacidade) {
  pilha->elementos = (int *)malloc(capacidade * sizeof(int));
  pilha->menores = (int *)malloc(capacidade * sizeof(int));
  pilha->topo = -1;
  pilha->capacidade = capacidade;
}

int EstaVazia(Pilha *pilha) { return pilha->topo == -1; }

int ObterMinimo(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->menores[pilha->topo];
}

int Desempilhar(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->elementos[pilha->topo--];
}

void Empilhar(Pilha *pilha, int valor) {
  if (pilha->topo == pilha->capacidade - 1) {
    pilha->capacidade *= 2;
    pilha->elementos =
        (int *)realloc(pilha->elementos, pilha->capacidade * sizeof(int));
    pilha->menores =
        (int *)realloc(pilha->menores, pilha->capacidade * sizeof(int));
  }
  pilha->elementos[++pilha->topo] = valor;
  if (pilha->topo == 0) {
    pilha->menores[pilha->topo] = valor;
  } else {
    if (valor < pilha->menores[pilha->topo - 1]) {
      pilha->menores[pilha->topo] = valor;
    } else {
      pilha->menores[pilha->topo] = pilha->menores[pilha->topo - 1];
    }
  }
}

void LiberarPilha(Pilha *pilha) {
  free(pilha->elementos);
  free(pilha->menores);
}

int main() {
  Pilha pilha;
  int quantidade, valor;
  char operacao[10];

  scanf("%d", &quantidade);
  Inicializar(&pilha, quantidade);

  for (int i = 0; i < quantidade; i++) {
    scanf("%s", operacao);
    if (operacao[1] == 'U') {
      scanf("%d", &valor);
      Empilhar(&pilha, valor);
    } else if (operacao[1] == 'O') {
      if (EstaVazia(&pilha)) {
        printf("EMPTY\n");
      } else {
        Desempilhar(&pilha);
      }
    } else if (operacao[1] == 'I') {
      int valorMin = ObterMinimo(&pilha);
      if (valorMin == -1) {
        printf("EMPTY\n");
      } else {
        printf("%d\n", valorMin);
      }
    }
  }
  LiberarPilha(&pilha);
  return 0;
}