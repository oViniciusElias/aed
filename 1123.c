/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1123
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 260
#define LIMITE 9999999

typedef struct {
    int cidade, custo;
} Par;

typedef struct {
    Par elementos[MAXN * MAXN];
    int tamanho;
} HeapMin;

int visitados[MAXN];
Par grafo[MAXN][MAXN];
int graus[MAXN];

void adicionar(HeapMin *heap, Par elemento) {
    heap->elementos[heap->tamanho] = elemento;
    int i = heap->tamanho;
    heap->tamanho++;

    while (i != 0 && heap->elementos[i].custo < heap->elementos[(i - 1) / 2].custo) {
        Par temp = heap->elementos[i];
        heap->elementos[i] = heap->elementos[(i - 1) / 2];
        heap->elementos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Par removerMinimo(HeapMin *heap) {
    Par raiz = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    int i = 0;

    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (menor + 1 < heap->tamanho && heap->elementos[menor + 1].custo < heap->elementos[menor].custo) {
            menor++;
        }
        if (heap->elementos[i].custo <= heap->elementos[menor].custo) {
            break;
        }
        Par temp = heap->elementos[i];
        heap->elementos[i] = heap->elementos[menor];
        heap->elementos[menor] = temp;
        i = menor;
    }

    return raiz;
}

int main() {
    int numCidades, numEstradas, cidadeDestino, cidadeInicial;
    while (scanf("%d %d %d %d", &numCidades, &numEstradas, &cidadeDestino, &cidadeInicial) && (numCidades || numEstradas || cidadeDestino || cidadeInicial)) {
        for (int i = 0; i <= numCidades; i++) {
            graus[i] = 0;
            visitados[i] = 0;
        }

        while (numEstradas--) {
            int origem, destino, peso;
            scanf("%d %d %d", &origem, &destino, &peso);
            grafo[origem][graus[origem]].cidade = destino;
            grafo[origem][graus[origem]++].custo = peso;
            grafo[destino][graus[destino]].cidade = origem;
            grafo[destino][graus[destino]++].custo = peso;
        }

        HeapMin dijkstra;
        dijkstra.tamanho = 0;
        Par inicial = {cidadeInicial, 0};
        adicionar(&dijkstra, inicial);

        while (dijkstra.tamanho > 0) {
            Par atual = removerMinimo(&dijkstra);
            if (visitados[atual.cidade]) continue;
            visitados[atual.cidade] = 1;
            if (atual.cidade == cidadeDestino - 1) {
                printf("%d\n", atual.custo);
                break;
            }
            if (atual.cidade <= cidadeDestino - 1) {
                for (int i = 0; i < graus[atual.cidade]; i++) {
                    if (grafo[atual.cidade][i].cidade == atual.cidade + 1) {
                        Par novo = {atual.cidade + 1, grafo[atual.cidade][i].custo + atual.custo};
                        adicionar(&dijkstra, novo);
                        break;
                    }
                }
            } else {
                for (int i = 0; i < graus[atual.cidade]; i++) {
                    Par novo = {grafo[atual.cidade][i].cidade, grafo[atual.cidade][i].custo + atual.custo};
                    adicionar(&dijkstra, novo);
                }
            }
        }
    }

    return 0;
}