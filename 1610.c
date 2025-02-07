/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1610
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOS 10001

typedef struct No {
    int vertice;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
} ListaAdj;

ListaAdj grafo[MAX_NOS], grafo_transposto[MAX_NOS];
int visitado[MAX_NOS];
int contagem_cfc;
int pilha[MAX_NOS], topo;

void adicionarAresta(ListaAdj* grafo, int origem, int destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = destino;
    novoNo->proximo = grafo[origem].cabeca;
    grafo[origem].cabeca = novoNo;
}

void order_filler_dfs(int v) {
    visitado[v] = 1;
    No* temp = grafo[v].cabeca;
    while (temp) {
        if (!visitado[temp->vertice]) {
            order_filler_dfs(temp->vertice);
        }
        temp = temp->proximo;
    }
    pilha[topo++] = v;
}

void scc_counter_dfs(int v) {
    visitado[v] = 1;
    No* temp = grafo_transposto[v].cabeca;
    while (temp) {
        if (!visitado[temp->vertice]) {
            contagem_cfc++;
            scc_counter_dfs(temp->vertice);
        }
        temp = temp->proximo;
    }
}

void freeGraph(ListaAdj* grafo, int n) {
    for (int i = 0; i < n; i++) {
        No* temp = grafo[i].cabeca;
        while (temp) {
            No* toFree = temp;
            temp = temp->proximo;
            free(toFree);
        }
        grafo[i].cabeca = NULL;
    }
}

int main() {
    int t, n, m, a, b;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i <= n; i++) {
            grafo[i].cabeca = NULL;
            grafo_transposto[i].cabeca = NULL;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            adicionarAresta(grafo, a, b);
            adicionarAresta(grafo_transposto, b, a);
        }

        memset(visitado, 0, sizeof(visitado));
        topo = 0;
        for (int i = 1; i <= n; i++) {
            if (!visitado[i]) {
                order_filler_dfs(i);
            }
        }

        memset(visitado, 0, sizeof(visitado));
        contagem_cfc = 0;
        while (topo > 0) {
            int v = pilha[--topo];
            if (!visitado[v]) {
                scc_counter_dfs(v);
            }
        }

        printf(contagem_cfc ? "SIM\n" : "NAO\n");
        freeGraph(grafo, n + 1);
        freeGraph(grafo_transposto, n + 1);
    }
    return 0;
}
