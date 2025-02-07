/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1259
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int comparaCrescente(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int comparaDecrescente(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int quantidade;
    int numeros[MAX_SIZE];
    int pares[MAX_SIZE];
    int impares[MAX_SIZE];
    int contPares = 0, contImpares = 0;

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        int valor;
        scanf("%d", &valor);
        if (valor % 2 == 0) {
            pares[contPares++] = valor;
        } else {
            impares[contImpares++] = valor;
        }
    }

    qsort(pares, contPares, sizeof(int), comparaCrescente);

    qsort(impares, contImpares, sizeof(int), comparaDecrescente);

    for (int i = 0; i < contPares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < contImpares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}