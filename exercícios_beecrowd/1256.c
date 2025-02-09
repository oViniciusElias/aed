
/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1256
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
RACIOCÍNIO: Criar listas para tabela HASH, Listas e criar nós.
*/

typedef struct {
    int u, v, peso;
} ponta;

int caparar(const void *a, const void *b) {
    return ((ponta *)a)->peso - ((ponta *)b)->peso;
}

int encontra(int anterior[], int i) {
    if (anterior[i] == i)
        return i;
    return encontra(anterior, anterior[i]);
}

void unir(int anterior[], int rank[], int x, int y) {
    int raizX = encontra(anterior, x);
    int raizy = encontra(anterior, y);

    if (rank[raizX] < rank[raizy])
        anterior[raizX] = raizy;
    else if (rank[raizX] > rank[raizy])
        anterior[raizy] = raizX;
    else {
        anterior[raizy] = raizX;
        rank[raizX]++;
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n), m || n) {
        ponta pontas[n];
        int pesototal = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &pontas[i].u, &pontas[i].v, &pontas[i].peso);
            pesototal += pontas[i].peso;
        }

        qsort(pontas, n, sizeof(ponta), caparar);

        int anterior[m], rank[m];
        for (int i = 0; i < m; i++) {
            anterior[i] = i;
            rank[i] = 0;
        }

        int mstWeight = 0;
        for (int i = 0; i < n; i++) {
            int u = encontra(anterior, pontas[i].u);
            int v = encontra(anterior, pontas[i].v);

            if (u != v) {
                mstWeight += pontas[i].peso;
                unir(anterior, rank, u, v);
            }
        }

        printf("%d\n", pesototal - mstWeight);
    }

    return 0;
}