//Vinícius de Oliveira Elias - 197552 - MergeSort


#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int part(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

void quick_sort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = part(vetor, baixo, alto);
        quick_sort(vetor, baixo, pi - 1);
        quick_sort(vetor, pi + 1, alto);
    }
}