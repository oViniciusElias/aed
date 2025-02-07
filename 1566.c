/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1566
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoContagem(int *vetor, int tamanho, int maximo) {
    int *auxiliar = (int *)malloc(maximo * sizeof(int));
    int indice = 0;

    for (int i = 0; i < maximo; ++i) {
        auxiliar[i] = 0;
    }

    for (int i = 0; i < tamanho; ++i) {
        auxiliar[vetor[i]] += 1;
    }

    for (int i = 0; i < maximo; ++i) {
        for (int j = 0; j < auxiliar[i]; ++j) {
            vetor[indice++] = i;
        }
    }

    free(auxiliar);
}

int main(void) {
    int numeroCasos, quantidadePessoas;
    int *alturas;

    scanf("%d", &numeroCasos);

    for (int caso = 0; caso < numeroCasos; ++caso) {
        scanf("%d", &quantidadePessoas);

        alturas = (int *)malloc(quantidadePessoas * sizeof(int));

        for (int i = 0; i < quantidadePessoas; ++i) {
            scanf("%d", &alturas[i]);
        }

        ordenacaoContagem(alturas, quantidadePessoas, 231);

        if (quantidadePessoas > 0) {
            printf("%d", alturas[0]);
        }
        for (int i = 1; i < quantidadePessoas; ++i) {
            printf(" %d", alturas[i]);
        }
        printf("\n");
    }

    free(alturas);

    return 0;
}
