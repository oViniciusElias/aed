/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED
*/

/*Algoritimo de ordenação escolhido: Bubble sort */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 20

/*Esta função recebe um vetor de ponteiros, em que cada elemento aponta para uma sting, e um inteiro N. 
Não retorna nada, pois muda o vetor diretamente na memória. O vetor é ordenado em ordem alfabética.*/
void bubbleSort(char *nomes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char *temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;        //deselegante e ineficiente pois cria uma variavel a mais. talvez mudar
            }
        }
    }
}

int main() {
    int N, K;
    char *nomes[100];

    scanf("%d %d", &N, &K);

    /*Alocação de memória para cada um dos nomes*/
    for (int i = 0; i < N; i++) {
        nomes[i] = malloc((TAM_MAX + 1) * sizeof(char));
        scanf("%s", nomes[i]);
    }

    bubbleSort(nomes, N);

    printf("%s\n", nomes[K - 1]);

    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }

    return 0;
}
