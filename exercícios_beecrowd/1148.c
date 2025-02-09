/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1148
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long int minimo(long long int a, long long int b) {
    return a < b ? a : b;
}

void floydWarshall(long long int **grafo, int numVertices) {
    for (int k = 1; k <= numVertices; ++k) {
        for (int i = 1; i <= numVertices; ++i) {
            for (int j = 1; j <= numVertices; ++j) {
                grafo[i][j] = minimo(grafo[i][j], grafo[i][k] + grafo[k][j]);
            }
        }
    }
}

int main(void) {
    long long int **grafo;
    int numVertices, numArestas, origem, destino, peso, numConsultas, origemConsulta, destinoConsulta;

    while (scanf("%d %d\n", &numVertices, &numArestas) != EOF) {
        if (numVertices == 0 && numArestas == 0) {
            break;
        }

        grafo = (long long int **)malloc((numVertices + 1) * sizeof(long long int *));
        for (int i = 1; i <= numVertices; ++i) {
            grafo[i] = (long long int *)malloc((numVertices + 1) * sizeof(long long int));
            for (int j = 1; j <= numVertices; ++j) {
                grafo[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < numArestas; ++i) {
            scanf("%d %d %d\n", &origem, &destino, &peso);
            grafo[origem][destino] = peso;
        }

        for (int i = 1; i <= numVertices; ++i) {
            for (int j = i; j <= numVertices; ++j) {
                if (grafo[i][j] != INT_MAX && grafo[j][i] != INT_MAX) {
                    grafo[i][j] = 0;
                    grafo[j][i] = 0;
                }
            }
        }

        floydWarshall(grafo, numVertices);

        scanf("%d\n", &numConsultas);
        for (int i = 0; i < numConsultas; ++i) {
            scanf("%d %d\n", &origemConsulta, &destinoConsulta);

            if (grafo[origemConsulta][destinoConsulta] == INT_MAX) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%lld\n", grafo[origemConsulta][destinoConsulta]);
            }
        }
        printf("\n");

        for (int i = 1; i <= numVertices; ++i) {
            free(grafo[i]);
        }
        free(grafo);
    }

    return 0;
}