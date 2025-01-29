/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1152
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include <stdio.h>
#include <stdlib.h>

struct celula {
    int tamanho;
    int *pais, *rankings;
};

void inicio(struct celula *ub, int tamanho) {
    ub->tamanho = tamanho;
    ub->pais = (int*)malloc(tamanho * sizeof(int));
    ub->rankings = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        ub->pais[i] = i;
    }
}

void destroi(struct celula *ub) {
    ub->tamanho = 0;
    free(ub->pais);
    free(ub->rankings);
}

int encontraConjunto(struct celula *ub, int i) {
    if (ub->pais[i] == i) {
        return i;
    }
    ub->pais[i] = encontraConjunto(ub, ub->pais[i]);
    return ub->pais[i];
}

int mesmoConjunto(struct celula *ub, int i, int j) {
    return encontraConjunto(ub, i) == encontraConjunto(ub, j);
}

void uneConjuntos(struct celula *ub, int i, int j) {
    if (!mesmoConjunto(ub, i, j)) {
        int x = encontraConjunto(ub, i), y = encontraConjunto(ub, j);
        if (ub->rankings[x] > ub->rankings[y]) {
            ub->pais[y] = x;
        } else {
            ub->pais[x] = y;
            if (ub->rankings[x] == ub->rankings[y]) {
                ub->rankings[y]++;
            }
        }
    }
}

struct Aresta {
    int origem, destino, peso;
};

int comp(const void *a, const void *b) {
    return ((const struct Aresta*)a)->peso - ((const struct Aresta*)b)->peso;
}

int Kruskal(struct Aresta *grafo, int n, int m) {
    int resposta = 0;
    qsort(grafo, m, sizeof(struct Aresta), comp);

    struct celula ub;
    inicio(&ub, n);
    for (int i = 0; i < m; ++i) {
        struct Aresta atual = grafo[i];
        if (!mesmoConjunto(&ub, atual.origem, atual.destino)) {
            resposta += atual.peso;
            uneConjuntos(&ub, atual.origem, atual.destino);
        }
    }
    destroi(&ub);

    return resposta;
}

int main() {
    int n, m, origem, destino, peso;

    while (scanf("%d %d\n", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }

        struct Aresta *grafo = (struct Aresta *)malloc(m * sizeof(struct Aresta));

        int resposta = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d\n", &origem, &destino, &peso);
            grafo[i].origem = origem;
            grafo[i].destino = destino;
            grafo[i].peso = peso;
            resposta += grafo[i].peso;
        }
        resposta -= Kruskal(grafo, n, m);

        printf("%d\n", resposta);

        free(grafo);
    }

    return 0;
}