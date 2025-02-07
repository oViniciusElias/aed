/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1088
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

long long ordenacaoShellEContar(int vetor[], int tamanho) {
    long long contaTrocas = 0;
    int intervalo, i, j;
    int temporario;

    for (intervalo = tamanho/2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < tamanho; i++) {
            temporario = vetor[i];
            j = i;

            while (j >= intervalo && vetor[j - intervalo] > temporario) {
                vetor[j] = vetor[j - intervalo];
                j -= intervalo;
                contaTrocas++;
            }

            vetor[j] = temporario;
        }
    }

    return contaTrocas;
}

int main() {
    int tamanho;
    int vetor[MAXN];
    
    while (1) {
        if (scanf("%d", &tamanho) != 1) {
            return 1;
        }
        if (tamanho == 0) break;

        for (int i = 0; i < tamanho; i++) {
            if (scanf("%d", &vetor[i]) != 1) {
                return 1;
            }
        }

        long long numeroTrocas = ordenacaoShellEContar(vetor, tamanho);

        if (numeroTrocas % 2 == 1) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }

    return 0;
}